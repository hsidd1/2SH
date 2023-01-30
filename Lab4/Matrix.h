
#include <string>
using namespace std;

class Matrix {

public:

	Matrix(); // this is the empty constructor. It dynamically allocates the memory for the matrix and initializes it to a square 3x3 matrix
    Matrix( int row, int col );
	Matrix( int row, int col, int **table);

	int getElement(int i, int j);
    bool setElement(int x, int i, int j);

    Matrix copy();

	void addTo( Matrix m );

	Matrix subMatrix(int i, int j);

    int getsizeofrows();

    int getsizeofcols();

    bool isUpperTr();


    string toString();

private:

	int    rowsNum;
	int    colsNum;
	int    **matrixData;

};
