#ifndef BASE_H
#define BASE_H

class Base
{
protected:
	/* Поля */
	size_t id = 0, m = 0, n = 0;
	double* data = nullptr;

	/* Статичные поля */
	static size_t static_id;
	static bool debug;

	/* Конструкторы и деструктор */
	Base(size_t size = 0, double* data = nullptr);
	Base(const Base& Other);
	Base(Base&& Other) noexcept;

	virtual ~Base();

	/* Оператор копирования = */
	virtual const Base& operator=(const Base& Other);

	/* Оператор перемещения = */
	virtual Base& operator=(Base&& Other) noexcept;

public:
	/* Сделать пустым */
	Base& MakeNull();

	/* Проверка на пустоту */
	bool IsEmpty() const;

	/* Проверка на возможность сложения или умножения */
	virtual bool AllowSumm(const Base& Other) const;
	virtual bool AllowMultiply(const Base& Other) const;

	/* Получить минимальный и максимальный элементы */
	double GetMax() const;
	double GetMin() const;

	/* Перегрузка оператора << */
	friend std::ostream& operator << (std::ostream& out, Base& Base);

	/* Геттеры */
	virtual std::string GetType() const = 0;
	size_t GetId() const;
	size_t GetSize() const;
	size_t GetN() const;
	size_t GetM() const;
	double* GetData() const;
};

/* Вспомогательные функции */
double* create_array(size_t x, size_t y = 1);

#endif BASE_H
