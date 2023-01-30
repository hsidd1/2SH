#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag = 1;

	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	for (int i = 0; i < N2; i++){ // iterate each row
		int sum = 0;
		for (int j = 0; j < N2; j++) // iterate through columns
			sum += fabs(mat[i][j]);
		sum -= fabs(mat[i][i]); // need sum of elements in the row EXCLUDING the diagonal element
		if (fabs(mat[i][i]) < sum)
			isDiag = 0; // if diagonal element is less than sum of all other elements in the row, it is not diagonally dominant

	}

    return isDiag;
}

