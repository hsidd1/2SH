
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	if(row <= 0){
		rowsNum = 3;
	}else{
		rowsNum = row;
		 }

	if(col <= 0){
		colsNum = 3;
	}else{
		colsNum = col;
		 }

	// Allocating memory for matrixData
	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	// Storing the elements as 0
	for (int i = 0 ; i < rowsNum ; i++ ){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));

		for (int j = 0 ; j < colsNum ; j++ ){
			matrixData[i][j]=0;
			 }
		 }

}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	rowsNum=row;
	colsNum=col;
	matrixData=NULL;

	matrixData = (int**)malloc(rowsNum*sizeof(int*));


	for (int i = 0 ; i < rowsNum ; ++i ){
		matrixData[i] = (int*) malloc(colsNum*sizeof(int));

		for (int j = 0 ; j < colsNum ; ++j ){
			// Storing elements with data from the inputed table
			matrixData[i][j]=*(*(table + i) + j);
			 }
		 }
}

int Matrix::getElement(int i, int j){
	if (i < 0 || i > rowsNum || j < 0 || j > colsNum){ // if out of range
		throw std::out_of_range( "Invalid indexes." );
	}
	else{
		return matrixData[i][j];
	}
		return -1;
	}



bool Matrix::setElement(int x, int i, int j){
	if (!(i < 0 || i > rowsNum || j < 0 || j > colsNum)){ // if not out of range
		matrixData[i][j] = x;
		return true;
	}

    return false;
}


Matrix Matrix::copy(){ // returns deep copy of matrix

    Matrix copy=  Matrix(rowsNum,colsNum );

    for (int i = 0; i < rowsNum; i++){
    		for (int j = 0; j < colsNum; j++){
    			copy.setElement(getElement(i,j), i, j); // copy elements into 'copy'
    		}
    	}
    return  copy;
}


void Matrix::addTo( Matrix m ){
	int sum = 0;
	if ((m.colsNum != colsNum) || (m.rowsNum != rowsNum)){
		throw std::invalid_argument( "Invalid operation" );
	}
	else{
	for (int i = 0; i < rowsNum; ++i){
		for (int j = 0; j < colsNum; ++j){
			// compute sum and set into matrix
			sum = m.getElement(i,j) + getElement(i,j);
			setElement(sum, i, j);
		}
	}
	}
	
}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */
	Matrix subM = Matrix (i+1,j+1);

	if (i < 0|| i >= rowsNum || j < 0 || j >= rowsNum){ // if out of range
			throw std::out_of_range( "Submatrix not defined" );
		}else{

			for(int x = 0; x < i+1; x++){
				for(int y = 0; y < j+1; y++){
					// create sub matrix
					subM.setElement(getElement(x, y), x, y);
				}
			}
		}

    return  subM;
}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return -1;
}


int Matrix::getsizeofcols(){



	/* update below return */
    return -1;
}


bool Matrix::isUpperTr(){ // determine if matrix is upper triangular

	/* write your implementation here and update return accordingly */
	for(int i = 1; i < rowsNum; i++){
			for(int j = 0; j < i; j++){
				if(matrixData[i][j] != 0){ // only upper triangular if 0 below diagonal
					return false;
				}
			}
		}
	  return true;
}


string Matrix::toString(){ // returns string form of matrix

	string output;
	for(int i = 0; i < rowsNum; ++i){
			for(int j = 0; j < colsNum; ++j){

				output += to_string(matrixData[i][j]) + " ";
			}
			output += "\n"; // new line after each row
		}
	//return output;
	 return output;
}
