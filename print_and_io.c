#ifndef PRINT_IO_LIBS_H
	#include "libraries.h"
	#include "print_and_io.h"
	#include "constants.h"
	#include "game_logic.h"
#endif

// elaborate ASCII style board print-out
void print_board_state(int * ra){
	printf("\n     14    13      12      11      10       9       8     7  \n");
	printf(" _____________________________________________________________\n");
	printf(" |      ");
	//printf("\n |   ");
	// don't print the last array index until the next row (this is player two's store)
	for( int i = MAX_ARRAY_SIZE - 2; i > PLAYER_ONE_STORE_LOC; i--){
		printf(" ( %2d ) ", ra[i]);
	}
	printf("      |\\");
	printf("\n | ( %2d )                                              ( %2d ) | \\", ra[MAX_ARRAY_SIZE - 1], ra[PLAYER_ONE_STORE_LOC]);
	printf("\n");
	printf(" |      ");
	for( int i = 0; i < PLAYER_ONE_STORE_LOC; i++){
		printf(" ( %2d ) ", ra[i]);
	}
	printf("      |  |");
	printf("\n");
	printf(" -------------------------------------------------------------|  |\n");
	printf(" \\          1       2       3       4       5       6          \\ |\n");
	printf("  \\_____________________________________________________________\\|\n");
}

void print_welcome(){
	printf("\nWelcome to Mancala!\n\n");
}

int get_input(){
	int in = 0;
	do{
		printf("\n\nPlayer one, please enter a valid input (1 - 6) or -1 to quit: ");
		scanf("%d", &in);
	}while( (in > 6 || in < 1) && in != -1 );
	if( in != -1){
		in -= 1;
	}
	return in;
}

// purely for debugging purposes, utility method
void print_ra(int * ra){
	printf("Flat array representation: \n");
	printf(" 1  2  3  4  5  6  7  8  9  10 11 12 13 14\n");
	for( int i = 0; i < MAX_ARRAY_SIZE; i++){
		printf(" %d ", ra[i]);
	}
	printf("\n");
}

// we assume that pots 0 through 5 are for player one
// pots 7 through 11 are for player two
void init_ra(int * ra){
	for( int i = 0; i < MAX_ARRAY_SIZE; i++){
		if( i != PLAYER_ONE_STORE_LOC && i != MAX_ARRAY_SIZE - 1 ){
			ra[i] = 4;
		}
	}
}

int get_computer_turn( int * check_array, int size){
	int found_playable_pot = 0;
	// keep track of index
	int spot_number = PLAYER_ONE_STORE_LOC;
	int ret_val = 0;
	// array is passed as a ptr and can be referred to as such
	int * ptr = check_array + PLAYER_ONE_STORE_LOC;
	int rand_turn = get_rand_num();
	while( ! found_playable_pot ){

		// check if spot has playable pieces
		// pointer arithmetic

		for( int * ptr = check_array + PLAYER_ONE_STORE_LOC;
			ptr != check_array + size 
					&& !found_playable_pot ; ptr++){
			// debug code, uncomment to see the loop searching through the array
			// printf("\nrand turn: %d", rand_turn + 1);
			// printf("\nspot_number: %d\n", spot_number + 1);
			// printf("\nvalue: %d\n", *ptr);
			if( rand_turn == spot_number && (*ptr != 0)){
				found_playable_pot = 1;
				ret_val = spot_number;
			}

			spot_number++;
		}
		// don't reset if we found a playable spot
		if( !found_playable_pot ){
			rand_turn = get_rand_num();
			//printf("New rand num: %d\n", rand_turn);
			spot_number = PLAYER_ONE_STORE_LOC;
		}
	}
	return ret_val;
}