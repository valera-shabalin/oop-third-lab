#include <iostream>

#include "Vector.h"
#include "Matrix.h"

using namespace std;

int rand_int(int min, int max) {
    return min + rand() % (max - min);
}

double rand_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

void seporator()
{
    cout << "==================================" << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Rus");

    /* Создание массивов */
    auto func1 = [](size_t x, size_t y)->double { return rand_int(0, 10); };
    auto func2 = [](size_t x, size_t y)->double { return rand_int(0, 20); };

    Matrix m1(2, 2, func1);
    seporator();
    Matrix m2(2, 2, func2);
    seporator();
    Vector v1(4, func1);
    seporator();
    Vector v2(4, func2);
    seporator();

    cout << "Первая матрица: " << endl << m1;
    cout << "Вторая матрица: " << endl << m2;

    Matrix mull(m1 * m2);
    cout << mull;

    return 0;
}
