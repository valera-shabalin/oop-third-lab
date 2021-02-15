#ifndef MATRIX_H
#define MATRIX_H

#include "Base.h"

class Matrix : public Base
{
private:
	/* ��������������� ����� ��� ���������� [][] */
	class Row
	{
	private:
		size_t index = 0;
		const Matrix* Owner = nullptr;
	public:
		/* ����������� */
		Row(const Matrix* Owner, size_t index);

		/* ���������� ��������� [] */
		double operator[](size_t x) const;
		double& operator[](size_t x);
	};
public:
	/* ������������ � ���������� */
	Matrix(size_t n, size_t m, double* matrix = nullptr);
	Matrix(size_t n = 0);

	virtual ~Matrix() noexcept;

	/* ���������� ��������� [] */
	Matrix::Row operator[](size_t index);
	const Matrix::Row operator[](size_t index) const;

	/* ���������� ���������� + */
	Matrix& operator+=(const Base& Other);
	Matrix operator+(const Base& Other);

	/* ���������� ���������� - */
	Matrix& operator-=(const Base& Other);
	Matrix operator-(const Base& Other);

	/* ���������� ���������� * */
	Matrix& operator*=(const Base& Other);
	Matrix operator*(const Base& Other);

	/* ���������� ��������� * �� ������ */
	Matrix& operator*=(double k);
	Matrix operator*(double k);

	/* ������� */
	virtual std::string GetType() const;
};

#endif MATRIX_H

