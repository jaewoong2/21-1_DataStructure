//
// Created by 82109 on 2021-05-12.
//

#ifndef HASHTABLEARRAY_CPHONE_H
#define HASHTABLEARRAY_CPHONE_H
#include <string>
#include <ostream>

class CPhone {
public:
    CPhone();
    CPhone(const std::string &name, const int &birthDay);
    std::string getName();
    int getBirthDay();
    void setName(const std::string &name);
    void setBirthDay(const int &day);
    friend std::ostream& operator<<(std::ostream& os, const CPhone& cPhone_);

private:
    std::string name;
    int birthDay;
};


#endif //HASHTABLEARRAY_CPHONE_H
