#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	
	// indices of arrays
	int val1_i = 0, val2_i = 0, val3_i = 0, j=0;
	// loop through val1
	while (val1_i < k1){
		// add in the smaller index values and positions first from val2, pos2
		while (pos2[val2_i] < pos1[val1_i]){
			val3[val3_i] = val2[val2_i];
			pos3[val3_i] = pos2[val2_i];
			val2_i++;
			val3_i++;
		}
		// when the sum is non zero and positions match
		if ((val1[val1_i] + val2[val2_i]) != 0 && (pos1[val1_i] == pos2[val2_i])){
			// add in the sums and the corresponding position to val3, pos3
			val3[val3_i] = val1[val1_i] + val2[val2_i];
			pos3[val3_i] = pos1[val1_i];
			val1_i++;
			val2_i++;
			val3_i++;
		}
		// if positions match but sum is 0, increment but dont add in pos and sum
		else if (((val1[val1_i] + val2[val2_i]) == 0) && (pos1[val1_i] == pos2[val2_i])){
			val1_i++;
			val2_i++;
		}
		// remaining will be the val1, pos1 indices that are added directly
		else{
			val3[val3_i] = val1[val1_i];
			pos3[val3_i] = pos1[val1_i];
			val3_i++;
			val1_i++;
		}

	}
	// for loop to add in remaining val2, pos2 values and positions that are higher than val1/pos1
	for (j = val2_i; j < k2; j++){
		val3[val3_i] = val2[val2_i];
		pos3[val3_i] = pos2[val2_i];
		val3_i++;
		val2_i++;
		}
}

