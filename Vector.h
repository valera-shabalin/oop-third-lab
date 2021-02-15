#ifndef VECTOR_H
#define VECTOR_H

#include "Base.h"

class Vector : public Base
{
public:
	/* ����������� � ���������� */
	Vector(size_t size = 0, double* vector = nullptr);

	virtual ~Vector();

	/* ���������� ��������� [] */
	double operator[](size_t n) const;
	double& operator[](size_t index);

	/* ���������� ��������� + */
	Vector& operator+=(const Base& Other);
	Vector operator+(const Base& Other);

	/* ���������� ��������� + */
	Vector& operator-=(const Base& Other);
	Vector operator-(const Base& Other);

	/* ���������� ��������� * */
	Vector& operator*=(const Base& Other);
	Vector operator*(const Base& Other);

	/* ���������� ��������� * �� ������ */
	Vector& operator*=(double k);
	Vector operator*(double k);

	/* ������� */
	virtual std::string GetType() const;
};

#endif
