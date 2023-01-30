
#include "Questions.h"



int Q1_for(){
	int sum_for=0;
	
	// calculate your sum below..this has to use for loop
	for (int i=30; i<=1000; i++){ // interating from 30 to 1000
		if ((i%4) == 0){ // checking if divisible by 4
			sum_for += i;
		}
	}
	
	// here, we return the calculated sum:
	return sum_for;
}
int Q1_while(){
	int sum_while=0;


	// calculate your sum below..this has to use while loop
	int i = 30;
	while (i<=1000){ // iterating from 30 to 1000
		if ((i%4)==0) // checking dvisibility by 4
		sum_while += i;
		i++;
	}
	
	
	// here, we return the calcualted sum:
	return sum_while;
}
int Q1_do(){
	int sum_do=0;
	
	// calculate your sum below..this has to use do-while loop
	int i = 30;
	do{
		if ((i%4)==0)
			sum_do += i;
		i++;
	}
	while (i<=1000); //repeats operation until we reach 1000, starting from 30

	  
	// here, we return the calcualted sum:
	return sum_do;
}

//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit = 0;
	
	// Do your coding below to check

	if ((Q2_input >= 10000 && Q2_input <= 99999)||(Q2_input <=-10000 && Q2_input >=-99999))
		//condition checks from smallest to largest 5 digit #, uses logic or operator to account for negative #s
		IsFiveDigit = 1;
	            // if the condition isn't met, then IsFiveDigit remains as 0
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value

	if (Q3_input >= 90 && Q3_input <= 100)
		GPA = 4;
	else if (Q3_input >= 80 && Q3_input < 90) //exclusive brackets implemented to account for gaps. ex.89.5
		GPA = 3;
	else if (Q3_input >= 70 && Q3_input < 80)
		GPA = 2;
	else if (Q3_input >= 60 && Q3_input < 70)
		GPA = 1;
	else if (Q3_input >= 0 && Q3_input < 60)
		GPA = 0;
	else GPA = -1;
	
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	double denominator = 1;
	double sign = 1;
	
	for (int i=0; i < Q4_input; i++){ //calculate the infinite series upto input value terms
		pi += 4.0/denominator * sign;
		denominator += 2;
		sign *= -1; //alternates sign
	}

	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){ //function finding total number of pythagorean triples (set of sides forming a right triangle) for hyp of 400
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	for (int hyp = 1; hyp<=400; hyp++){ //iterates for hypotenuse, upto 400 length as per criteria
		for (int side1 = 1; side1 < hyp; side1++){ // iterates for side 1, strictly smaller than hyp
			for (int side2 = side1; side2 < hyp; side2++){ // iterates for side 2, always greater or equal to side 1, hence iteration starts from side 2 = side 1
				if ((hyp*hyp) == (side1*side1) + (side2*side2)){ //check if pythagorean theorem holds
					totNumTribles++;}
			}
		}
	}

	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    int sum; // will hold the sum of factors of input
	    for (int num=1; num <= Q6_input; num++){ //iterating up to input
	    	sum = 0; // sum has to reset for each iteration otherwise imperfect nums will be added
	    	for (int x=1; x<=num/2; x++){ //iterate to check for factors and add to sum
	    		if ((num % x) == 0)
	    			sum += x;
	    	}
	    		if (sum == num){ //check if perfect number to increment counts and add to array
	    			perfect[counts] = sum; // add the perfect number to the array
	    			counts++;
	    }
	    }

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0, rem=0;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	for (int i = 1; i <=7; i++){ // 7 iterations for 7 digit inputs
		rem = Q7_input % 10; //store individual digits
		reversedInt = reversedInt*10 + rem; //shift digits 1 to the left and add remainder to it
		Q7_input/=10; // iterate to next digit
	}
		return reversedInt;
	
}

int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	int rem = 0;
	while (Q7b_input > 0){ // loops for all digits now instead of only 7
			rem = Q7b_input % 10;
			reversedInt = reversedInt*10 + rem; // same logic as 7a
			Q7b_input/=10; // allows rightmost digit to be removed for next increment
		}
	
	
	return reversedInt;
}
