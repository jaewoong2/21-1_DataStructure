//
// 20160569 임재웅 자료구조 Hash Table p.51
//

#include <iostream>
#include "Table.h"
#include "CPhone.h"

int stringToInt(std::string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str.at(i);
    }
    return sum;
}

int main() {

    Table<int, CPhone> CPhoneTable;

    CPhoneTable.insert(stringToInt("Mary"), CPhone("David", 812101));
    CPhoneTable.insert(stringToInt("David"), CPhone("Mary", 649001));
    CPhoneTable.insert(stringToInt("Sua"), CPhone("Sua", 759901));

    CPhone target;
    CPhoneTable.lookup(stringToInt("Mary"), target);
    std::cout << target << "\n";
    CPhoneTable.dump();


    return 0;
}
