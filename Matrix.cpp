#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Matrix.h"

using namespace std;




Matrix::Matrix(size_t rowNum, size_t colNum, double initValue)
{
	//allocSpace();
	//for (unsigned i = 0; i < row; i++) {
	//	for (unsigned j = 0; j < col; j++) {
	//		matrix[i][j] = 0;
	//	}
	//}
	row = rowNum;
	col = colNum;

}

Matrix::Matrix(const Matrix &m) :row(m.row), col(m.col)
{
	allocSpace();
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; i < col; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix & Matrix::operator=(const Matrix &m)
{
	// TODO: insert return statement here
	if (this == &m) {
		return *this;
	}

	if (row != m.row || col != m.col) {
		for (unsigned i = 0; i < row; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;

		row = m.row;
		col = m.col;
		allocSpace();

	}
	for (unsigned i = 0; i < row; ++i) {
		for (unsigned j = 0; j < col; ++j) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
			return *this;
}




void Matrix::allocSpace()
{
	matrix = new double *[row];
	for (unsigned i = 0; i < row; i++)
	{
		matrix[i] = new double[col];
	}
}

Matrix::~Matrix()
{
	for (unsigned i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix & Matrix::operator+=(const Matrix &m)
{
	assert(row == m.row && col == m.col);
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < row; j++) {
			matrix[i][j] += m.matrix[i][j];
		}
	}
	return *this;

}

Matrix & Matrix::operator-=(const Matrix &m)
{
	assert(row == m.row && col == m.col);
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < row; j++) {
			matrix[i][j] -= m.matrix[i][j];
		}
	}
	return *this;
}

Matrix & Matrix::operator*=(const Matrix &m)
{
	assert(row == m.row && col == m.col);
	Matrix temp(m.row, m.col);
	for (unsigned i = 0; i < temp.row; i++) {
		for (unsigned j = 0; j < m.row; j++) {
			for (unsigned k = 0; k < m.col;k++) {
				temp.matrix[i][j] += (matrix[i][k] * m.matrix[k][j]);
			}
		}
	}
	return (*this = temp);
}

bool Matrix::operator==(const Matrix &m)
{
	bool check = true;
	if (row != m.row || col != m.col) { return false; }
	for (unsigned i = 0; i < row; ++i)
	{
		for (unsigned j = 0; j < col; ++j)
		{
			if (matrix[i][j] != m.matrix[i][j])
			{
				return false;
			}
		}
	}
	return check;
}

bool Matrix::operator!=(const Matrix &m)
{

	return !(Matrix ::operator==(m));
}



ostream& operator<<(ostream& os, const Matrix& m)
{
	for (unsigned i = 0; i < m.row; ++i) {
		os << m.matrix[i][0];
		for (unsigned j = 1; j < m.col; ++j) {
			os << " " << m.matrix[i][j];
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, Matrix& m)
{
	for (unsigned  i = 0; i < m.row; ++i) {
		for (unsigned j = 0; j < m.col; ++j) {
			is >> m.matrix[i][j];
		}
	}
	return is;
}

Matrix operator+(const Matrix &, const Matrix &)
{
	return Matrix();
}

Matrix operator-(const Matrix &, const Matrix &)
{
	return Matrix();
}

Matrix operator*(const Matrix &, const Matrix &)
{
	return Matrix();
}
