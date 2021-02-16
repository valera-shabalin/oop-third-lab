#include <iostream>

#include "Matrix.h"

using namespace std;

/* ����������� ROW */
Matrix::Row::Row(const Matrix* Owner, size_t index)
{
	this->Owner = Owner;
	this->index = index;
}

/* ���������� ��������� [] ROW */
double Matrix::Row::operator[](size_t index) const
{
	if (index > this->Owner->m)
		throw "Out of matrix.";

	return *(this->Owner->data + this->index * this->Owner->n + index);
}
double& Matrix::Row::operator[](size_t index)
{
	if (index > this->Owner->m)
		throw "Out of matrix.";

	return *(this->Owner->data + this->index * this->Owner->n + index);
}

/* ����������� */
Matrix::Matrix(size_t n, size_t m, double* matrix) : Base(n * m, matrix)
{
	this->n = n;
	this->m = m;

	if (debug)
	{
		cout << "Constructor 'Matrix' with ID: " << this->id << endl;
	}
}

/* ����������� � ����� ���������� */
Matrix::Matrix(size_t n) : Matrix(n, n) {}

/* �����������, ����������� �����-��������� */
Matrix::Matrix(size_t n, size_t m, double(*func)(size_t, size_t)) : Base(n * m)
{
	this->n = n;
	this->m = m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			*(this->data + i * m + j) = func(i, j);
		}
	}

	if (debug)
	{
		cout << "Constructor 'Matrix' with ID: " << this->id << endl;
	}
}

/* ���������� */
Matrix::~Matrix()
{
	if (debug)
	{
		cout << "Destructor 'Matrix' with ID: " << this->id << endl;
	}
}

/* ���������� ��������� [] */
Matrix::Row Matrix::operator[](size_t index)
{
	if (index >= this->n)
	{
		throw "Out of matrix.";
	}
		
	return Row(this, index);
}
const Matrix::Row Matrix::operator[](size_t index) const
{
	if (index >= this->n)
	{
		throw "Out of matrix.";
	}
		
	return Row(this, index);
}

/* ���������� ��������� += */
Matrix& Matrix::operator+=(const Base& Other) {
	if (!this->AllowSumm(Other))
	{
		throw "The operation cannot be performed.";
	}
		
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		*(this->data + i) += *(Other.GetData() + i);
	}

	return *this;
}

/* ���������� ��������� + */
Matrix Matrix::operator+(const Base& Other) {
	return move(*this += Other);
}

/* ���������� ��������� -= */
Matrix& Matrix::operator-=(const Base& Other) {
	if (!this->AllowSumm(Other))
	{
		throw "The operation cannot be performed.";
	}
		
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		*(this->data + i) -= *(Other.GetData() + i);
	}

	return *this;
}

/* ���������� ��������� - */
Matrix Matrix::operator-(const Base& Other) {
	return move(*this -= Other);
}

/* ���������� ��������� *= */
Matrix& Matrix::operator*=(const Base& Other) {
	if (!this->AllowMultiply(Other))
	{
		throw "The operation cannot be performed.";
	}
		

	size_t new_size = this->n * Other.GetM();
	double* matrix = new double[new_size]();

	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < Other.GetM(); j++)
		{
			for (size_t k = 0; k < this->m; k++)
			{
				*(matrix + i * Other.GetM() + j) += *(this->data + i * this->m + k) * *(Other.GetData() + k * Other.GetM() + j);
			}
		}
	}

	delete[] this->data;
	this->data = matrix;
	this->m = this->n;
	this->n = Other.GetM();

	return *this;
}

/* ���������� ��������� * */
Matrix Matrix::operator*(const Base& Other) {
	return move(*this *= Other);
}

/* ���������� ��������� *= �� ������ */
Matrix& Matrix::operator*=(double k) {
	if (this->IsEmpty())
	{
		throw "Matrix is empty.";
	}
		
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		*(this->data + i) *= k;
	}
		
	return *this;
}

/* ���������� ��������� * �� ������ */
Matrix Matrix::operator*(double k) {
	return move(*this *= k);
}

/* ������� */
string Matrix::GetType() const
{
	return "Matrix";
}
