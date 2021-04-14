//
// Created by 82109 on 2021-03-28.
//

#include "pharmacy.h"

Pharmacy::Pharmacy(const Pharmacy &anotherPharmacy) {
    name = anotherPharmacy.name;
    numberOfMask = anotherPharmacy.numberOfMask;
    arrivalTime = anotherPharmacy.arrivalTime;
    distance = anotherPharmacy.distance;
};


Pharmacy Pharmacy::operator=(const Pharmacy &anotherPharmacy) {
    name = anotherPharmacy.name;
    numberOfMask = anotherPharmacy.numberOfMask;
    arrivalTime = anotherPharmacy.arrivalTime;
    distance = anotherPharmacy.distance;

    return *this;
}