#ifndef BASE_H
#define BASE_H

class Base
{
protected:
	/* ���� */
	size_t id = 0, m = 0, n = 0;
	double* data = nullptr;

	/* ��������� ���� */
	static size_t static_id;
	static bool debug;

	/* ������������ � ���������� */
	Base(size_t size = 0, double* data = nullptr);
	Base(const Base& Other);
	Base(Base&& Other) noexcept;

	virtual ~Base();

	/* �������� ����������� = */
	virtual const Base& operator=(const Base& Other);

	/* �������� ����������� = */
	virtual Base& operator=(Base&& Other) noexcept;

public:
	/* ������� ������ */
	Base& MakeNull();

	/* �������� �� ������� */
	bool IsEmpty() const;

	/* �������� �� ����������� �������� ��� ��������� */
	virtual bool AllowSumm(const Base& Other) const;
	virtual bool AllowMultiply(const Base& Other) const;

	/* �������� ����������� � ������������ �������� */
	double GetMax() const;
	double GetMin() const;

	/* ���������� ��������� << */
	friend std::ostream& operator << (std::ostream& out, Base& Base);

	/* ������� */
	virtual std::string GetType() const = 0;
	size_t GetId() const;
	size_t GetSize() const;
	size_t GetN() const;
	size_t GetM() const;
	double* GetData() const;
};

/* ��������������� ������� */
double* create_array(size_t x, size_t y = 1);

#endif BASE_H
