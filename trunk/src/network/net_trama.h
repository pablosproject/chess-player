/*
 * net_trama.h
 *
 *  Created on: 10/12/2011
 *      Author: gabi
 */

#ifndef net_trama_H_
#define net_trama_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structs/board.h"
#include "../log/log.h"
#include "../search/search_functions.h"
#include <time.h>


#define KILL_PIECE						0
#define ERROR_TRAMA_SERVER 				-1
#define ERROR_UPDATE_BOARD 				-2
#define ERROR_FIND_ACTUAL_AND_NEXT 		-3
#define ERROR_DELETE_ACTUAL				-4
#define ERROR_FIND_POSITION				-5
#define ERROR_GENERATING_MESSAGE		-6
#define ERROR_COLOR_KILL_PIECEs_NOT_FOUND -7
#define ERROR_Make_movement_ko 			-8

int process_trama(char* msg_server,char* msg_player,Board * boardActual,Board * previousBoard);
int Make_simple_movement(char* msg_server,char* msg_player,Board * boardActual);
int Make_Enroc_Llarg(char* msg_player,Board * boardActual);
int Make_Enroc_curt(char* msg_player,Board * boardActual);
int Make_movement_ko( char* msg_server, char* msg_player,Board * boardActual,Board * previousBoard);
int Make_corona_movement(char* msg_server,char* msg_player,Board * boardActual);
int Make_peo_al_pas_movement(char* msg_server,char* msg_player,Board * boardActual);
int update_board(char initial_row,char initial_column,char final_row, char final_column,Board* boardActual);
int getBitMapPosition(char row, char column,BitMap* actualBitMap);
int Compare_position_color_pieces_board(Board* boardActual,Board* nextMove,int* killer);
int search_next_movement(Board* boardActual,Board* nextMove);
int make_mesage_to_server(BitMap* start, BitMap* end,char* msg_player);
int update_board_after_search(Board* boardActual, Board* nextMove, BitMap* start, BitMap*end);
int search_and_update_kill_piece(Board* boardActual,int black_white,BitMap finalBitMap);
int change_pawn_corona(Board* boardActual,char final_row,char final_column,int Type_Piece_change,int color_pawn);
int make_firts_play(char* msg_player,Board * boardActual);
int first_children(Board* nextMove,Board* boardActual);
/*
 * This function extract from the union of the actual and next movement, the single movement.
 *
 * @param actual, a bitmap where to store the actual position
 * @param next, a bitmap where to store the next position
 * @param total, the union of the two position
 * @param nextOriginal,the movement generated by the search algorithm
 *
 * @return an int that indicate the success or failure of the operation
 */
int extractActualNextBitmap(BitMap * actual, BitMap * next, BitMap * total, BitMap * nextOriginal);

/*
 * This functionactualize the board:
 * -Delete the old piece position stored in actual
 * -Insert the new piece position contained in next
 * -Search in the enemies pieces if there's one killed and erase it
 *
 * @param actualBoard, the board to actualize
 * @param next, a pointer to the next movement por a piece
 * @param actual, the actual position of a piece
 */
int actualizeBoard(Board * actualBoard, BitMap * next, BitMap * actual );

//TODO:comment
void actualizeTotalBoard(Board *board);



#endif /* net_trama_H_ */
