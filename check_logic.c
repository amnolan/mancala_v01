#ifndef CHECK_LOGIC
	#include "libraries.h"
	#include "constants.h"
#endif

// lookup which value is directly across from current spot
int index_perpendicular_from_pot(int index){
	int ret_val = 0;
	if( index == 0){
		ret_val = 12;
	}else if(index == 1){
		ret_val = 11;
	}else if(index == 2){
		ret_val = 10;
	}else if(index == 3){
		ret_val = 9;
	}else if(index == 4){
		ret_val = 8;
	}else if(index == 5){
		ret_val = 7;
		// end bottom row lookup
	}else if(index == 7){
		ret_val = 5;
	}else if(index == 8){
		ret_val = 4;
	}else if(index == 9){
		ret_val = 3;
	}else if(index == 10){
		ret_val = 2;
	}else if(index == 11){
		ret_val = 1;
	}else if(index == 12){
		ret_val = 0;
	}
	return ret_val;
}

// check to see if player won by virtue of clearing the row
int is_row_cleared_of_all_pieces(int * ra, int size, int player){
	int num_gt_zero_found = 0;
	if(player == PLAYER_ONE){
		for( int j = 0; j < PLAYER_ONE_STORE_LOC; j++ ){
			if( ra[j] > 0 ){
				num_gt_zero_found = 1;
			}
		}
	}else{
		for( int j = PLAYER_ONE_STORE_LOC; j < size; j++ ){
			if( ra[j] > 0 ){
				num_gt_zero_found = 1;
			}
		}
	}
	return !num_gt_zero_found;
}

// pointer arithmetic
int player_1_play_option_available(int * ra, int ra_size, int selection){
	int ctr = 0, available = 0;
	for( int * ptr = ra; (ptr != ra + ra_size) && (ctr < UPPER_LIMIT_SELECTION); ptr++ ){
		if( ctr == selection && *ptr > 0){
			available = 1;
		}
		ctr++;
	}
	return available;
}

int check_spot_valid( int * check_array, int size, int spot ){
	int spot_valid = 0;
	int val = check_array[spot];
	if( val > 0 ){
		spot_valid = 1;
	}
	return spot_valid;
}