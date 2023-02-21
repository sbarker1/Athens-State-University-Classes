#pragma once

#include <cassert>
#include "Matrix.h"

using namespace std;

template <class T>
Matrix<T>::Matrix(int sizeX, int sizeY, T initValue) : dx(sizeX), dy(sizeY)
{
    assert(sizeX > 0 && sizeY > 0);
    for (int i = 0; i < dx; i++)
    {
        vector<T> temp;
        for (int j = 0; j < dy; j++)
            temp.push_back(initValue);
        data.push_back(temp);
    }
}
template <class T>
T& Matrix<T>::operator()(int x, int y)
{
    assert(x >= 0 && x < dx&& y >= 0 && y < dy);
    return this->data[x][y];
}

template <typename MType>
Matrix<MType> operator+(const Matrix<MType>& m1, const Matrix<MType>& m2)
{
    assert(m1.dx == m2.dx && m1.dy == m2.dy);
    Matrix<MType> result = m1;
    for (int i = 0; i < m1.dx; i++)
        for (int j = 0; j < m1.dy; j++)
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
    return result;
}

template <typename Type>
ostream& operator<<(ostream& out, const Matrix<Type>& m)
{
    out << endl;
    for (int x = 0; x < m.dx; x++)
    {
        for (int y = 0; y < m.dy; y++)
            out << m.data[x][y] << "\t";
        out << endl;
    }
    return out;
}
