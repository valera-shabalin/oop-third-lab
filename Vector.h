#ifndef VECTOR_H
#define VECTOR_H

#include "Base.h"

class Vector : public Base
{
public:
	/* Конструктор и деструктор */
	Vector(size_t size = 0, double* vector = nullptr);

	virtual ~Vector();

	/* Перегрузка оператора [] */
	double operator[](size_t n) const;
	double& operator[](size_t index);

	/* Перегрузка оператора + */
	Vector& operator+=(const Base& Other);
	Vector operator+(const Base& Other);

	/* Перегрузка оператора + */
	Vector& operator-=(const Base& Other);
	Vector operator-(const Base& Other);

	/* Перегрузка оператора * */
	Vector& operator*=(const Base& Other);
	Vector operator*(const Base& Other);

	/* Перегрузка оператора * на скаляр */
	Vector& operator*=(double k);
	Vector operator*(double k);

	/* Геттеры */
	virtual std::string GetType() const;
};

#endif
