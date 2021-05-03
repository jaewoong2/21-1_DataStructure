#include <iostream>
#include "Table.h"

int main() {
    Table<int, char> table;

    table.insert('a', 123);
    table.insert('b', 234);
    table.insert('c', 345);

    int result = 0;
    table.lookup('a', result);
    std::cout << result << "\n";
    table.lookup('b', result);
    std::cout << result << "\n";
    table.lookup('c', result);
    std::cout << result << "\n";

    table.insert('a', 1234);
    table.lookup('a', result);
    std::cout << result << "\n";
}
