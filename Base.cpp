#include <iostream>

#include "Base.h"

size_t Base::static_id = 0;
bool Base::debug = true;

using namespace std;

/* Конструктор */
Base::Base(size_t size, double* data)
{
	this->id = ++static_id;

	if (size > 0)
	{
		this->data = new double[size]();
		this->n = 1;
		this->m = size;
	}

	if (data != nullptr)
	{
		copy(data, data + size, this->data);
	}

	if (debug)
	{
		cout << "Constructor 'Base' with ID: " << this->id << endl;
	}	
}

/* Конструктор копирования */
Base::Base(const Base& Other) : Base()
{
	*this = Other;
}

/* Оператор копирования = */
const Base& Base::operator=(const Base& Other)
{
	if (debug)
	{
		cout << "Copy constructor in 'Base': " << this->id << " <= " << Other.id << endl;
	}
		
	if (this == &Other)
	{
		return *this;
	}
		
	size_t size = Other.GetSize();

	if (this->GetSize() != size)
	{
		if (this->data != nullptr)
		{
			delete[] this->data;
		}
		this->data = size > 0 ? new double[size] : nullptr;
	}

	this->n = Other.n;
	this->m = Other.m;

	if (size > 0)
	{
		copy(Other.data, Other.data + size, this->data);
	}

	return *this;
}

/* Конструктор перемещения */
Base::Base(Base&& Other) noexcept : Base() {
	*this = move(Other);
}

/* Оператор перемещения = */
Base& Base::operator=(Base&& Other) noexcept {
	if (debug)
	{
		cout << "Move constructor in 'Base': " << this->id << " <= " << Other.id << endl;
	}
		
	if (this == &Other)
	{
		return *this;
	}
		
	this->MakeNull();
	swap(this->data, Other.data);
	swap(this->n, Other.n);
	swap(this->m, Other.m);

	return *this;
}

/* Деструктор */
Base::~Base()
{
	if (debug)
	{
		cout << "Destructor 'Base' with ID: " << this->id << endl;
	}

	this->MakeNull();
	this->id = 0;
}

/* Сделать массив пустым */
Base& Base::MakeNull()
{
	this->n = this->m = 0;

	if (!this->IsEmpty()) {
		delete[] this->data;
		this->data = nullptr;
	}

	return *this;
}

/* Проверка на пустоту */
bool Base::IsEmpty() const
{
	return this->data == nullptr;
}

/* Проверка на возможность сложения и умножения */
bool Base::AllowSumm(const Base& Other) const
{
	return this->n == Other.n && this->m == Other.m;
}
bool Base::AllowMultiply(const Base& Other) const
{
	return this->n == Other.m;
}

/* Получить минимальный и максимальный элементы */
double Base::GetMax() const
{
	if (this->IsEmpty())
	{
		throw "Object is empty.";
	}

	double max = *this->data;

	for (size_t i = 1; i < this->GetSize(); i++)
	{
		if (max < *(this->data + i))
		{
			max = *(this->data + i);
		}
			
	}

	return max;
}
double Base::GetMin() const
{
	if (this->IsEmpty())
	{
		throw "Object is empty.";
	}
		
	double min = *this->data;

	for (size_t i = 1; i < this->GetSize(); i++)
	{
		if (min > *(this->data + i))
		{
			min = *(this->data + i);
		}
	}

	return min;
}

/* Перегрузка оператора << */
ostream& operator << (ostream& out, Base& Base)
{
	if (Base.IsEmpty())
	{
		out << "Object is empty." << endl;
		return out;
	}

	for (size_t i = 0; i < Base.n; i++)
	{
		for (size_t j = 0; j < Base.m; j++)
		{
			out << *(Base.data + Base.m * i + j) << " ";
		}
		out << endl;
	}

	return out;
}

/* Геттеры */
size_t Base::GetId() const
{
	return this->id;
}
size_t Base::GetSize() const
{
	return this->n * this->m;
}
size_t Base::GetN() const
{
	return this->n;
}
size_t Base::GetM() const
{
	return this->m;
}
double* Base::GetData() const
{
	return this->data;
}
