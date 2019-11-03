#ifndef  MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <iostream>

class Matrix {

private:
	size_t row;
	size_t col;
	double *value;
	void allocSpace();

public:
	Matrix(); // default constructor
	Matrix(size_t rowNum, size_t colNum,double initValue);
	Matrix(const Matrix&);// copy constructor
	Matrix& operator=(const Matrix&);
	~Matrix();
	//inline double& operator()(int x, int y) { return matrix[x][y]; }
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);
	
	Matrix& operator+= (const Matrix&);
	Matrix& operator-= (const Matrix&);
	Matrix& operator*= (const Matrix&);
	bool operator == (const Matrix&);
	bool operator != (const Matrix&);
	std::size_t rows() { return row; }
	std::size_t cols() { return col; }
};

Matrix operator+ (const Matrix&, const Matrix&);
Matrix operator- (const Matrix&, const Matrix&);
Matrix operator* (const Matrix&, const Matrix&);




#endif // ! MATRIX_H
