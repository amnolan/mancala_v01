#ifndef GAME_LOGIC_LIBS_H
	#include "print_and_io.h"
	#include "libraries.h"
	#include "constants.h"
	#include "check_logic.h"
#endif


int get_rand_num(){
	int ret_val = 0;
	// select a pot to play
	srand((unsigned) time(NULL));
	ret_val = ( rand() % (MAX_ARRAY_SIZE - 2 - PLAYER_ONE_STORE_LOC)) + PLAYER_ONE_STORE_LOC + 1;
	return ret_val;
}

// workhorse method of the game
// decides how to move, how to award points and allows recursive calls
// to ensure players get to play continuously when applicable (e.g. last one lands on player's side)
void move_pieces_counter_clockwise(int * ra, int size, int start_index, int player_num){
	
	int ctr = 0;
	int starting_pieces = 0;
	int perpendicular_spot;

	starting_pieces = ra[start_index];
	// pieces_stolen_from_opponent = starting_pieces;
	ra[start_index] = 0;
	ctr++;
	while( starting_pieces > 0 ){
		// distribute the pieces

		// skip opponent's store and restart at beginning
		if( (start_index + ctr) == size - 1 && player_num == PLAYER_ONE){
			ctr = 0;
			start_index = 0;
		}

		// fill computer's store and restart at beginning
		if( (start_index + ctr) == size && player_num == COMPUTER){
			ctr = 0;
			start_index = 0;
		}

		// if computer, skip the player one store
		if( (start_index + ctr) == PLAYER_ONE_STORE_LOC && player_num == COMPUTER){
			ctr = 0;
			start_index = PLAYER_ONE_STORE_LOC + 1;
			//starting_pieces++;
		}

		// debug print statement
		//printf("\nstarting_pieces count: %d, start_index count: %d, ctr count %d\n\n", starting_pieces, start_index, ctr);
		ra[start_index + ctr]++;
		starting_pieces--;
		ctr++;

		// does the last stone placed in the hole land on the player's own side
		if( starting_pieces == 0 ){
			// this tells us where we just "were" when the last piece was sown
			int curr_index = start_index + ctr - 1;
			if( player_num == PLAYER_ONE){
				// check ending index
				if( curr_index >= 0 && curr_index < PLAYER_ONE_STORE_LOC ){
					printf("\nThis turn ended on player one's side, player one goes again.\n");
					int captured_pieces = 0;
					// this means that we ended on player one's side and the final piece
					// was sown alone into the pot
					if( ra[curr_index] == 1){
						// get the spot directly across so we can take the pieces from the opponent
						perpendicular_spot = index_perpendicular_from_pot(curr_index);
						if( ra[perpendicular_spot] > 0 ){
							captured_pieces = ra[perpendicular_spot];
							ra[PLAYER_ONE_STORE_LOC] += captured_pieces;
							// take the prize from their spot
							ra[perpendicular_spot] = 0;
							printf("\nThe final piece was sown into a pot alone. Thus we took %d pieces from the Computer!\n", captured_pieces);
						}
					}
					
					// use of recursion to continue playing until this statement is no longer true
					print_board_state(ra);
					move_pieces_counter_clockwise(ra, size, curr_index, player_num);
				}
			}else{
				// go again until it no longer lands on the Computer's side
				if( curr_index > PLAYER_ONE_STORE_LOC && curr_index < size - 1 ){
					printf("\nEnds on computer's side, computer goes again.\n");

					int captured_pieces = 0;
					// this means that we ended on player one's side and the final piece
					// was sown alone into the pot
					if( ra[curr_index] == 1){
						// get the spot directly across so we can take the pieces from the opponent
						perpendicular_spot = index_perpendicular_from_pot(curr_index);
						if( ra[perpendicular_spot] > 0 ){
							captured_pieces = ra[perpendicular_spot];
							ra[MAX_ARRAY_SIZE - 1] += captured_pieces;
							// take the prize from their spot
							ra[perpendicular_spot] = 0;
							printf("\nThe final piece was sown into a pot alone. Thus Computer took %d pieces from Player One!\n", captured_pieces);
						}
					}
					// use of recursion to continue playing until this statement is no longer true
					print_board_state(ra);
					move_pieces_counter_clockwise(ra, size, curr_index, player_num);
				}
			}
		}
	}
}