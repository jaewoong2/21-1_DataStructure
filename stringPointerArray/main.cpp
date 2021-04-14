#include <iostream>
#include "dynamicArray.h"
#include <string>
using namespace std;


int main() {
    DynamicArray s1, s2;
    cout << s1.getSize() << "\n";
    s1.addEntry("hi");
    cout << s1[0] << endl;
    cout << s1.getSize() << "\n";
    s1.addEntry("asd");
    cout << s1.getSize() << "\n";
    s1.deleteEntry("hi");
    cout << s1.getSize() << "\n";
    cout << s1[0] << endl;
    cout << s1.getSize() << "\n";

    string *str = new string[1];
    s2.addEntry("20");
    s2.addEntry("20");
    s2.addEntry("20");
    s2.addEntry("20");
    s2.addEntry("20");
    s2.addEntry("20");

    str[0] = "hi2";

    s1 = s2;
    cout << s1[5] << endl;
    cout << s1.getSize() << endl;

    DynamicArray s3(s2);

    cout << s3[5] << endl;
    cout << s3.getSize() << endl;

    return 0;
}
