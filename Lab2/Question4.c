#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i=0;
	char c;
	while (word[i] !='\0'){ // iterate until NULL
		c = word[i];
		if (word[i] >= 'A' && word[i]<= 'Z')
			c = word[i] + 32; // convert to lower case if capital
		freq[c -'a']++; // increments element in freq array based on alphabetical order
		i++;
	}
}
