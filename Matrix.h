#ifndef MATRIX_H
#define MATRIX_H

#include "Base.h"

class Matrix : public Base
{
private:
	/* Вспомогательный класс для перегрузки [][] */
	class Row
	{
	private:
		size_t index = 0;
		const Matrix* Owner = nullptr;
	public:
		/* Конструктор */
		Row(const Matrix* Owner, size_t index);

		/* Перегрузка оператора [] */
		double operator[](size_t x) const;
		double& operator[](size_t x);
	};
public:
	/* Конструкторы и деструктор */
	Matrix(size_t n, size_t m, double* matrix = nullptr);
	Matrix(size_t n = 0);

	virtual ~Matrix() noexcept;

	/* Перегрузка оператора [] */
	Matrix::Row operator[](size_t index);
	const Matrix::Row operator[](size_t index) const;

	/* Перегрузка операторов + */
	Matrix& operator+=(const Base& Other);
	Matrix operator+(const Base& Other);

	/* Перегрузка операторов - */
	Matrix& operator-=(const Base& Other);
	Matrix operator-(const Base& Other);

	/* Перегрузка операторов * */
	Matrix& operator*=(const Base& Other);
	Matrix operator*(const Base& Other);

	/* Перегрузка оператора * на скаляр */
	Matrix& operator*=(double k);
	Matrix operator*(double k);

	/* Геттеры */
	virtual std::string GetType() const;
};

#endif MATRIX_H

