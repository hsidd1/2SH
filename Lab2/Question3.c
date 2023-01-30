#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
void diag_scan(int mat [][N3], int arr []){
    int k = 0, x, y;

    int diags = 2*N3 - 1; // number of diagonals
    for (int i = 0; i < diags; i++){ // loop num of diags

    	// first pattern for the diags upto and including the row equal in value to diags
        if (i < N3){
            for (int j = 0; j <= i; j++){
            	// x and y change as follows
                x = i - j;
                y = j;
                // add into array and increment counter
                arr[k] = mat[x][y];
                k++;
            }
        }
        else{
        	//pattern for the remaining elements
            for (int j = 0; j < diags - i; j++){
            	// x and y change as follows
            	x = N3 - 1 - j;
                y = i - N3 + 1 + j;
                // add into array and increment counter
                arr[k] = mat[x][y];
                k++;
            }
        }
    }
}
