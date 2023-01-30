#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){


    char **word_list;

    /*write your implementation here*/
    FILE *input_file = fopen(input_filename, "r");
    // read number of words and store
    fscanf(input_file, "%d", nPtr);

    word_list = calloc(*nPtr, sizeof(char*));
    char* temp = calloc(15, sizeof(char)); // pointer for words

    for (int i = 0; i < *nPtr; i++){
    	fscanf(input_file, "%s", temp); // read from file, store in temp
    	int len = strlen(temp);
    	word_list[i] = calloc(len+1, sizeof(char));
    	// allocate memory using strlen+1
    	strcpy(word_list[i], temp);// copy string form temp to wordlist[i] using strcpy

    }
    fclose(input_file);
    return word_list;
}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/
	for (int i = 0; ; ++i) { // loop until if conditions are met
	        char c1 = str1[i], c2 = str2[i]; // avoid reading from memory each time
	        if (!(c1 || c2)) // break and return -1 case (checking end of strings)
	            break;

	        if (c1 != c2)
	            return c1 > c2; // returns 1 if str2 is alphabetically smaller than str1, 0 if str1 is smaller
	    }

	    return -1;
	}

void sort_words(char **words, int size){

	/*write your implementation here*/
	// insertion sort algoirthm which compares words one at a time and repeats until everything is sorted
	  int j;
	    for (int i = 1; i < size; i++){ //per word in list
	        j = i - 1; //for index before
	        while (j >= 0 && compare_str(words[j], words[j+1])){ //see if str1 > str2. swap if true
	            swap(&words[j], &words[j+1]);
	            j--;
	        }
	    }

}

void swap(char **str1, char **str2){ // swap two values (address as parameters)
	/*this is a helper function that you can implement and use to facilitate your development*/
	char *temp; //temp pointer
	    temp = *str1;
	    *str1 = *str2;
	    *str2 = temp;
}

void sort2_words(char **words, int size){


	/*write your implementation here*/
	// implementation of selection sort algorithm
	 int minIndex;
	    for (int i = 0; i < size - 1; i++){
	    	minIndex = i;
	        for (int j = i; j < size; j++){
	        	if (compare_str(words[minIndex], words[j])){
	        		minIndex = j; //min index is changed if str1>str2
	        	}
	        }
	        swap(&words[i], &words[minIndex]); // swaps min index in outer loop
	    }
}

