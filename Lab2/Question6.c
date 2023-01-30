#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	int k = 0;
	//iterate through size
	for (int i = 0 ; i < size ; i++){
		// place in efficient array if the value is not zero, along with the corresponding position
		if (source[i] != 0){
			val[k] = source[i];
			pos[k] = i;
			k++;
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	int p_index=0; // index for position
	// iterate through size
	for (int i = 0; i < m; i++){
		// if a number is met that is not in pos, then that index of source is 0
		if (i != pos[p_index])
			source[i] = 0 ;
		// otherwise the value is added in
		else{
			source[i] = val[p_index];
			p_index++;
		}
	}
}
