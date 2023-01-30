#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int index2 = 0; // index for concatenation of str2 into z

	int z_size = strlen(str1) + strlen(str2) + 1;
	z = (char*) calloc(z_size, sizeof(char));

	for (int i = 0; str1[i]; i++){ // iterate through str1
		z[i] = str1[i];
		index2 = i; // store which index in z to start appending str2 from
	}

	for (int k = 0; str2[k]; k++){ // iterate through str2
		if(strlen(str1) == 0)
			z[index2++] = str2[k];
		else
			z[++index2] = str2[k];
	}

	z[index2+1] = 0;

	/* finally, return the string*/
	return z;
}
