#include <iostream>
#include "vector.h"

Vector::Vector()
{
    arraySize = 0;
    elNumber = 1;
    array = new int[elNumber];
}

Vector::~Vector()
{
    delete[] array;
}

const int& Vector::operator[](size_t number)
{
  return array[number];
}

std::istream &operator>>(std::istream &is, Vector &v)
{
    int value;
    while (is >> value) 
    {
        v.push_back(value);
    }
    return is;
}

 std::ostream &operator<<(std::ostream &os, Vector &v) 
 {
    for (size_t i = 0; i < v.Size(); ++i)
    {
        os << v[i] << ' ';
    }
    return os;
 }

size_t Vector::Size() const
{
    return arraySize;
}

void Vector::newSize()
{
    elNumber = elNumber * 2;
    int* newArray = new int[elNumber];

    for (size_t i = 0; i < arraySize; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

void Vector::push_back(const int& number)
{
    if (arraySize == elNumber)
    {
        newSize();
    }
    array[arraySize] = number;
    ++arraySize;
}


int main(int, char**){
    Vector vector;
    int value;
    std::cout << "1. Enter the number, it will be added to the vector." << '\n';
    std::cout << "2. Enter the vector of numbers." << '\n';
    std::cout << "Ctrl + D(for Unix) or Ctrl + Z + Enter(for Windows) for end input" << '\n';


    std::cin >> value;
    std::cin >> vector;
    
    std::cout << "Size: " << vector.Size() << '\n';
    std::cout << "Vector: " << vector << '\n';

    
    vector.push_back(value);

    std::cout << "New vector: " << vector << '\n';
}
