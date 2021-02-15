#include <iostream>

#include "Vector.h"
#include "Matrix.h"

using namespace std;

void seporator()
{
    cout << "==================================" << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Rus");

    /* Создание массивов */
    double* arr1 = create_array(2, 2);
    double* arr2 = create_array(1, 4);
    double* arr3 = create_array(2, 2);
    double* arr4 = create_array(1, 4);
    double* arr5 = create_array(4, 1);

    /* Инициализация объектов */
    Vector vec1(4, arr2), vec2(4, arr4);
    seporator();
    Matrix mat1(2, 2, arr1), mat2(2, 2, arr2), mat3(2), mat4(1, 4, arr4), mat5(4, 1, arr5);
    seporator();

    /* Проверка сложения */
    Vector vec_summ = vec1 + mat4;
    cout << "Сумма вектора и матрицы: " << vec_summ;
    seporator();
    Matrix mat_summ = mat4 + vec2;
    cout << "Сумма матрицы и вектора: " << mat_summ;
    seporator();

    /* Проверка умножения */
}
