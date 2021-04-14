//
// Created by 82109 on 2020-12-05.
//

#include "dynamicArray.h"
#include <string>
#include <iostream>
using namespace std;
DynamicArray::DynamicArray(const DynamicArray &object) {
    dynamicArray = new string[object.size];
    size = object.size;
    for(int i = 0; i < size; i++) {
        dynamicArray[i] = object.dynamicArray[i];
    }
}

void DynamicArray::addEntry(const string &str) {
    size++;
    string* tempArray = new string[size];
    for(int i = 0; i < size - 1; i++) {
        tempArray[i] = dynamicArray[i];
    }
    tempArray[size - 1] = str;
    delete [] dynamicArray;
    dynamicArray = tempArray;
}

bool DynamicArray::deleteEntry(const string &str) {
    bool flag = false;
    for(int i = 0; i < size; i++) {
        if(dynamicArray[i] == str) {
            if(!flag) {
                string* tempArray = new string[size - 1];
                for(int j = 0; j < i; j++) {
                    tempArray[j] = dynamicArray[j];
                }
                for(int j = i; j < size; j++) {
                    if(j + 1 != size) {
                        tempArray[j] = dynamicArray[j + 1];
                    }
                }
             delete [] dynamicArray;
             dynamicArray = tempArray;
             flag = true;
            }
        }
    }
    size--;
    return flag;
}


string DynamicArray::getEntry(const int& index) const {
    return dynamicArray[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &rightSide) {
    if(size != rightSide.size) {
        delete [] dynamicArray;
        dynamicArray = new string [rightSide.size];
    }

    size = rightSide.size;

    for(int i = 0; i < size; i++) {
        dynamicArray[i] = rightSide.dynamicArray[i];
    }

    return *this;
}

string& DynamicArray::operator[](const int &index) {
    return dynamicArray[index];
}

DynamicArray::~DynamicArray() {
    delete [] dynamicArray;
}
