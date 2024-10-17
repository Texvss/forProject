#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

class Vector 
{
public:
    Vector();
    ~Vector();
    
    friend std::istream& operator>>(std::istream& is, Vector& v);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    void push_back(const int& number);
    size_t Size() const;
    const int& operator[](size_t number);

private:
    int* array;
    size_t arraySize;
    size_t elNumber;
    void newSize();
};


#endif