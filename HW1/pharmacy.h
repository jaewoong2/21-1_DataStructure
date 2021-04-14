//
// Created by 82109 on 2021-03-28.
//

#ifndef HW1_PHARMACY_H
#define HW1_PHARMACY_H
#include <string>

using std::string;


/*
 * Precondition: None
 * PostCondition: 생성자가 생성한 객체가 생서된다. 멤버변수로 는 `name`, `numberOfMask`, `distance`, `arrivalTime` 이 있고,
 * 연산자 로는, `=` 가 있다
 * Returns: 생성자가 생성한 객체가 생서된다.
 */
class Pharmacy {

public: // 쓰이는 멤버변수만 public 으로 처리
    /*
     * Precondition: None
     * PostCondition: (Default 생성자 역할)
     * Returns: 객체 생성
     */
    Pharmacy() {};

    /*
     * Precondition: 다른 Pharmacy 객체가 선언되어 있어서 그것이 매개변수로 들어와야함
     * PostCondition: 매개변수로 들어온 Pharmacy 객체를 복사한 객체 생성(복사생성자)
     * Returns: 객체 생성
     */
    Pharmacy(const Pharmacy& anotherPharmacy);

    int numberOfMask;
    string name;

    /*
     * Precondition: 다른 Pharmacy 객체가 선언되어 있어서 그것이 매개변수로 들어와야함
     * PostCondition: 매개변수로 들어온 Pharmacy 객체에 있는 멤버변수로 각각의 멤버변수를 받아옴
     * Returns: 해당 객체
     */
    Pharmacy operator=(const Pharmacy& anotherPharmacy);


private: //쓰이지 않는 멤버변수는 private 처리
    int distance;
    int arrivalTime;
};


#endif //HW1_PHARMACY_H
