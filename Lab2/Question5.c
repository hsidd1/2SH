#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void string_copy(const char source[], char destination[], int n){
	int i;
	// iterate through size
	for(i = 0; i < n-1; i++){
		// copy to array, break once Null is reached
		if(source[i] != '\0'){
			destination[i] = source[i];
		}else{
			break;
		}
	}
	//make last character Null character
	destination[i+1] = '\0';
}


