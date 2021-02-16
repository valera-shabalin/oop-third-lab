#include <iostream>

#include "Vector.h"

using namespace std;

/* ����������� */
Vector::Vector(size_t size, double* vector) : Base(size, vector)
{
	if (debug)
	{
		cout << "Constructor 'Vector' with ID: " << this->id << endl;
	}
}

/* �����������, ����������� �����-��������� */
Vector::Vector(size_t size, double(*func)(size_t, size_t)) : Base(size)
{
	for (size_t i = 0; i < size; i++)
	{
		*(this->data + i) = func(i, size);
	}

	if (debug)
	{
		cout << "Constructor 'Vector' with ID: " << this->id << endl;
	}
}

/* ���������� */
Vector::~Vector()
{
	if (debug)
	{
		cout << "Destructor 'Vector' with ID: " << this->id << endl;
	}
}

/* ���������� ��������� [] */
double Vector::operator[](size_t index) const
{
	if (index > this->m)
	{
		throw "Out of vector.";
	}
		
	return *(this->data + index);
}
double& Vector::operator[](size_t index)
{
	if (index > this->m)
	{
		throw "Out of vector.";
	}
		
	return *(this->data + index);
}

/* ���������� ��������� += */
Vector& Vector::operator+=(const Base& Other) {
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
Vector Vector::operator+(const Base& Other) {
	return move(*this += Other);
}

/* ���������� ��������� -= */
Vector& Vector::operator-=(const Base& Other) {
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
Vector Vector::operator-(const Base& Other) {
	return move(*this -= Other);
}

/* ���������� ��������� *= */
Vector& Vector::operator*=(const Base& Other) {
	if (!this->AllowSumm(Other))
	{
		throw "The operation cannot be performed.";
	}
		

	for (size_t i = 0; i < this->GetSize(); i++)
	{
		*(this->data + i) *= *(Other.GetData() + i);
	}

	return *this;
}

/* ���������� ��������� * */
Vector Vector::operator*(const Base& Other) {
	return move(*this *= Other);
}

/* ���������� ��������� *= �� ������ */
Vector& Vector::operator*=(double k) {
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		*(this->data + i) *= k;
	}

	return *this;
}

/* ���������� ��������� * �� ������ */
Vector Vector::operator*(double k) {
	return move(*this *= k);
}

/* ������� */
string Vector::GetType() const
{
	return "Vector";
}
