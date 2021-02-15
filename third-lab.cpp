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

    double* arr = create_array(1, 4);
    double* mat = create_array(1, 4);

    Vector vec1(4, arr);
    Matrix mat1(1, 4, arr);
    cout << vec1;
    cout << mat1;
    Vector vec2 = vec1 + mat1;
    cout << vec2;
}
