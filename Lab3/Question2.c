#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/

	// first line indicates # of students so it is read to store number of students
	FILE *input_file = fopen(filename, "r");
	fscanf(input_file, "%d", sizePtr);

	class_list = calloc(*sizePtr, sizeof(student)); // allocate class list

	for (int i = 0 ; i < *sizePtr; i++){ // iterate to scan file items for each student
		class_list[i] = (student*) calloc(1, sizeof(student)); // allocate for each element in class list

		// access member variables in struct to store after reading. File follows same order as follows (student id, first name, last name)
		fscanf(input_file, "%d", &(class_list[i]->student_id));
		fscanf(input_file, "%s", class_list[i]->first_name);
		fscanf(input_file, "%s", class_list[i]->last_name);
	}

	fclose(input_file);
	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	for (int pos = 0; pos < size; pos++) // iterate for number of students in list
		if (idNo == list[pos]->student_id) return pos; // return the position if student id matches idNo
	return -1; // denotes not found
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	FILE *grades_file = fopen(filename, "r");
	for (int i = 0; i < size; i++){
		int ID = 0;

		fscanf(grades_file, "%d", &ID); // read student ID from the file
		int pos = find(ID, list, size); // position will be determined using find()
		if (pos == -1){ // -1 means not found
			printf("No student found with ID [%d]",  ID);
			continue; // continue iterations
		}
		// read both grades
		fscanf(grades_file, "%d", &(list[pos]->project1_grade));
		fscanf(grades_file, "%d", &(list[pos]->project2_grade));
	}
	fclose(grades_file);
}

void compute_final_course_grades(student **list, int size)
{
	/*write your implementation here*/
	for (int i = 0; i < size; i++)
		list[i]->final_grade = (double) (list[i]->project1_grade + list[i]->project2_grade)/2.0; // computes average of 2 grades
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *output_file = fopen(filename, "w");
		fprintf(output_file, "%d\n", size); // first write number of students

		for(int i = 0; i < size; i++)
			fprintf(output_file, "%d %f\n", list[i]->student_id, list[i]->final_grade); // write student id followed by final grade

		fclose(output_file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int pos = find(idNo, list, *sizePtr); // determine position based on ID number

		if(pos == -1){ // message declaring student ID not found in list
			printf("Student with ID [%d] not found in list.\n",idNo);

		}else{
			free(list[pos]); // deallocate struct variable holding info of withdrawn student
			(*sizePtr)--; // shift pointer
			for (int i = pos; i < *sizePtr; i++)
				list[i]=list[i+1]; // shift array one position left
		}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for (int i = 0; i < * sizePtr; i++)
		free(list[i]); // each element is deallocated

	free(list); // list deallocated
	*sizePtr = 0; // set size to 0
}
