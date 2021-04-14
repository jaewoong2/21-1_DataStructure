//
// Created by 82109 on 2020-12-05.
//

#ifndef STRINGPOINTERARRAY_DYNAMICARRAY_H
#define STRINGPOINTERARRAY_DYNAMICARRAY_H
#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
public:
    DynamicArray(){ size = 0; dynamicArray = nullptr; };
    DynamicArray(const DynamicArray& object);
    int getSize() const { return size; } ;
    void addEntry(const string& str);
    bool deleteEntry(const string& str);
    string getEntry(const int& index) const;
    DynamicArray& operator=(const DynamicArray& rightSide);
    string& operator[](const int& index);
    ~DynamicArray();
private:
    string* dynamicArray;
    int size;
};

#endif //STRINGPOINTERARRAY_DYNAMICARRAY_H

