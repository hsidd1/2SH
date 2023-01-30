#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   

//=========Question 1==================================
	void TestQ1_two_strings(CuTest *tc) {

		CuAssertStrEquals(tc, "HelloWorld!", my_strcat("Hello","World!"));
	}

	void TestQ1_second_empty(CuTest *tc) {

		CuAssertStrEquals(tc, "Hello", my_strcat("Hello",""));
	}
	void TestQ1_first_empty(CuTest *tc) {

		CuAssertStrEquals(tc, "World!", my_strcat("","World!"));
	}

	void TestQ1_both_empty(CuTest *tc) {

			CuAssertStrEquals(tc, "", my_strcat("",""));
		}

	void TestQ1_str1_longer(CuTest *tc) {

				CuAssertStrEquals(tc, "verylongwordhi", my_strcat("verylongword","hi"));
			}


//===========================================================
//=================Question 2================================
	void TestQ2_find_notThere(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = -1;
		int actual = find(0011,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

	}

	void TestQ2_find_There(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 4;
		int actual = find(9000,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

	}

	void TestQ2_inputGradesAndCalculateFinal(CuTest *tc) {



		char inputFile[] =  "students.txt";
		char gradesFile[] =  "grades.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);
		//input grades using the grades input file
		input_grades(gradesFile,Clist,size);
		//calculate final grades
		compute_final_course_grades(Clist,size);
		//Output final course marks
		output_final_course_grades("outputGrades.txt",Clist,size);

		//now we open the golden file with the written file and compare line by line

		char actualFile[] =  "outputGrades.txt";
		char goldenFile[] =  "output.txt";

		char actual[1000], expected[1000];
		int actualID,expectedID;
		double actualFinalGrade,expectedFinalGrade;
		FILE *actualPtr, *expectedPtr;
		if ((actualPtr = fopen(actualFile, "r")) == NULL || (expectedPtr = fopen(goldenFile, "r")) == NULL) {
			printf("Error! opening file");
			// Program exits if file pointer returns NULL.
			exit(1);
		}

		int actualNumStudents,expectedNumStudents;


		fscanf(actualPtr,"%d",&actualNumStudents);

		fscanf(expectedPtr,"%d",&expectedNumStudents);

		CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

		int i;
		for(i=0;i<expectedNumStudents;i++){
		//while (actualPtr != NULL && expectedPtr!=NULL){
			// reads text until newline is encountered
		/*	fscanf(actualPtr, "%[^\n]", actual);
			printf("%s ", actual);
			fscanf(expectedPtr, "%[^\n]", expected);
			printf("%s\n", expected);

			CuAssertStrEquals(tc, expected, actual);

		*/

			fscanf(actualPtr,"%d",&actualID);

			fscanf(expectedPtr,"%d",&expectedID);

			CuAssertIntEquals(tc, expectedID, actualID);

			fscanf(actualPtr,"%lf",&actualFinalGrade);
			fscanf(expectedPtr,"%lf",&expectedFinalGrade);
			CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
		}
		if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

			printf("files are not of equal size");
			// Program exits if file pointer returns NULL.
			exit(1);

		}

	}
	void TestQ2_withdraw(CuTest *tc){
	        char inputFile[] =  "students.txt";
	        int size;
	        student **Clist = create_class_list(inputFile,&size);

	        withdraw(9000, Clist, &size);
	        if(find(9000,Clist,size) != -1 || size != 4){
	            printf("TestQ2_withdraw test case has failed!\n");
	            exit(1);
	        }
	    }

	void TestQ2_full_test(CuTest *tc) {
			char inputFile[] =  "lab3-siddih38/student_test.txt";
			char gradesFile[] =  "lab3-siddih38/grades_test.txt";
			int size;

			// Created class list using the input file
			student **Clist = create_class_list(inputFile,&size);

			// Inputed grades using the grades input file
			input_grades(gradesFile,Clist,size);
			// Calculated final grades
			compute_final_course_grades(Clist,size);

			// Withdraw three times
			// Id which is not found in the list
			withdraw(8888,Clist,&size);
			// Id which are found and will be withdrawn from the list
			withdraw(1010,Clist,&size);
			withdraw(5555,Clist,&size);

			//Output final course marks
			output_final_course_grades("lab3-siddih38/test_outputGrades.txt",Clist,size);

			//now we open the golden file with the written file and compare line by line
			char actualFile[] =  "lab3-siddih38/test_outputGrades.txt";
			char goldenFile[] =  "lab3-siddih38/test_output.txt";

			char actual[1000], expected[1000];
			int actualID,expectedID;
			double actualFinalGrade,expectedFinalGrade;

			FILE *actualPtr, *expectedPtr;
			if ((actualPtr = fopen(actualFile, "r")) == NULL || (expectedPtr = fopen(goldenFile, "r")) == NULL) {
				printf("Error! opening file");
				// Program exits if file pointer returns NULL.
				exit(1);
			}

			int actualNumStudents,expectedNumStudents;

			fscanf(actualPtr,"%d",&actualNumStudents);

			fscanf(expectedPtr,"%d",&expectedNumStudents);

			CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

			int i;
			for(i=0;i<expectedNumStudents;i++){
				fscanf(actualPtr,"%d",&actualID);
				fscanf(expectedPtr,"%d",&expectedID);
				CuAssertIntEquals(tc, expectedID, actualID);
				fscanf(actualPtr,"%lf",&actualFinalGrade);
				fscanf(expectedPtr,"%lf",&expectedFinalGrade);
				CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
			}

			if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

				printf("files are not of equal size");
				// Program exits if file pointer returns NULL.
				exit(1);
			}

			// Destroy the list
			destroy_list(Clist,&size);
			output_final_course_grades("lab3-siddih38/test_destroyoutputGrades.txt",Clist,size);

			//now we open the golden file with the written file and compare line by line
			char actualFile_des[] =  "lab3-siddih38/test_destroyoutputGrades.txt";
			char goldenFile_des[] =  "lab3-siddih38/output_destroy.txt";

			if ((actualPtr = fopen(actualFile_des, "r")) == NULL || (expectedPtr = fopen(goldenFile_des, "r")) == NULL) {
				printf("Error! opening file");
				// Program exits if file pointer returns NULL.
				exit(1);
			}

			fscanf(actualPtr,"%d",&actualNumStudents);

			fscanf(expectedPtr,"%d",&expectedNumStudents);

			CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

			for(i=0;i<expectedNumStudents;i++){
				fscanf(actualPtr,"%d",&actualID);
				fscanf(expectedPtr,"%d",&expectedID);
				CuAssertIntEquals(tc, expectedID, actualID);
				fscanf(actualPtr,"%lf",&actualFinalGrade);
				fscanf(expectedPtr,"%lf",&expectedFinalGrade);
				CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
			}

			if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

				printf("files are not of equal size");
				// Program exits if file pointer returns NULL.
				exit(1);
			}
	}

//===========================================================
//=================Question 3================================  
	void TestQ3_readandSort1(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
   
	void TestQ3_readandSort2(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort2_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
 


  
//===========================================================
	CuSuite* Lab3GetSuite() {
		CuSuite* suite = CuSuiteNew();
		SUITE_ADD_TEST(suite, TestQ1_two_strings);
		SUITE_ADD_TEST(suite, TestQ1_second_empty);
		SUITE_ADD_TEST(suite, TestQ1_first_empty);
		SUITE_ADD_TEST(suite, TestQ1_both_empty);
		SUITE_ADD_TEST(suite, TestQ1_str1_longer);




		SUITE_ADD_TEST(suite, TestQ2_find_notThere);
		SUITE_ADD_TEST(suite, TestQ2_find_There);
		SUITE_ADD_TEST(suite, TestQ2_inputGradesAndCalculateFinal);
		SUITE_ADD_TEST(suite, TestQ2_withdraw);
		SUITE_ADD_TEST(suite, TestQ2_full_test);



		SUITE_ADD_TEST(suite, TestQ3_readandSort1);
		SUITE_ADD_TEST(suite, TestQ3_readandSort2);
        
       

		return suite;
	}
    
