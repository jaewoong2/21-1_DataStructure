//
// 20160569 임재웅 자료구조 CPhone.cpp
//

#include "CPhone.h"
#include <string>
#include <ostream>
#include <iostream>


CPhone::CPhone() {
    name = "";
    birthDay = 000000;
}

CPhone::CPhone(const std::string &name_, const int &birthDay_) {
    this->name = name_;
    this->birthDay = birthDay_;
}


int CPhone::getBirthDay() {
    return birthDay;
}


std::string CPhone::getName() {
    return name;
}

void CPhone::setBirthDay(const int &birthDay_) {
    this->birthDay = birthDay_;
}

void CPhone::setName(const std::string &name_) {
    this->name = name_;
}

std::ostream &operator<<(std::ostream &os, const CPhone &cPhone_) {

    std::cout << "Birth Day: " << cPhone_.birthDay;
    std::cout << '\t';
    std::cout << "Name: " << cPhone_.name;

    return os;
}

