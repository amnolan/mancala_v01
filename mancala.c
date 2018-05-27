/*
	@amnolan
*/
#ifndef IMPORTS
	#include "constants.h"
	#include "libraries.h"
	#include "print_and_io.h"
	#include "game_logic.h"
	#include "check_logic.h"
#endif

typedef struct{
	int p1_score;
	int computer_score;
} Game;

void play_mancala(){
	Game game;
	game.p1_score = 0;
	game.computer_score = 0;

	int input, available, winner = 0, exit_flag = 0;
	int ra [MAX_ARRAY_SIZE];
	int int_size = sizeof(ra)/sizeof(int);
	init_ra(ra);
	
	print_welcome();

	do{
		int can_player_go_again = 0, not_first_loop = 0;
		available = 0;

		print_board_state(ra);

			do{
				if( not_first_loop ){
					printf("\nThat spot is empty! Please enter another choice. ");
				}
				not_first_loop = 1;
				input = get_input();
				exit_flag = input;
				available = player_1_play_option_available(ra, int_size, input);
			}while( ! available && input != -1);
			
			move_pieces_counter_clockwise(ra, int_size, input, PLAYER_ONE);
			print_board_state(ra);

			winner = is_row_cleared_of_all_pieces(ra, int_size, PLAYER_ONE);
			if(winner){
				printf("\nPlayer one won!\n");
				game.p1_score = ra[ PLAYER_ONE_STORE_LOC ];
				game.computer_score = ra[ MAX_ARRAY_SIZE - 1 ];
				exit_flag = -1;
			}

		// reset upon exiting
		can_player_go_again = 0;

		// we don't have to worry about the computer selecting -1 here
		if( exit_flag != -1){
			int computers_turn = get_computer_turn(ra, int_size);

			printf("\n\nThe Computer selected spot number: %d\n\n", computers_turn + 1);				
			move_pieces_counter_clockwise(ra, int_size, computers_turn, COMPUTER);

			printf("\n");
			winner = is_row_cleared_of_all_pieces(ra, int_size, COMPUTER);
			if(winner){
				printf("Computer won!\n");
				game.p1_score = ra[ PLAYER_ONE_STORE_LOC ];
				game.computer_score = ra[ MAX_ARRAY_SIZE - 1 ];
				exit_flag = -1;
			}
		}

	}while( exit_flag != -1 );

	// case someone arbitrarily stops in the middle by typing in
	if( exit_flag == -1){
		game.p1_score = ra[ PLAYER_ONE_STORE_LOC ];
		game.computer_score = ra[ MAX_ARRAY_SIZE - 1 ];
	}
	// use of structs
	printf("\nFinal score for Player One at end of game is : %d\n", game.p1_score );
	printf("\nFinal score for Computer at end of game is : %d\n", game.computer_score );
}

int main(){
	play_mancala();
}