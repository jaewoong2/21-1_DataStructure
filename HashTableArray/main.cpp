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

    Table<int, int> table;
    table.insert(20200421, 20200421);
    table.insert(20200422, 20200422);
    table.insert(20200423, 20200423);
    table.insert(20200424, 20200424);
    table.insert(20200425, 20200425);
    table.insert(20200426, 20200426);
    table.insert(20200427, 20200427);

    table.deleteKey(20200424);
    table.deleteKey(20200423);

    table.insert(20200412, 20200412);
    table.dump();

    Table<int, CPhone> CPoneTable;

    CPoneTable.insert(stringToInt("Jone"), CPhone("Jone", 951201));
    CPoneTable.insert(stringToInt("Mary"), CPhone("David", 812101));
    CPoneTable.insert(stringToInt("David"), CPhone("Mary", 649001));
    CPoneTable.insert(stringToInt("Sua"), CPhone("Sua", 759901));

    CPhone target;
    CPoneTable.lookup(stringToInt("Jone"), target);
    std::cout << target << "\n";
    CPoneTable.dump();


    return 0;
}
