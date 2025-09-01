//
// Created by lixia on 2025/9/1.
//

#include <iostream>
#include "./../include/Sales_data.h"
using namespace std;

int main(int argc, char *argv[]) {
    Sales_data data1;
    print(cout, data1);
    cout << endl;

    Sales_data data2("ISBN-2012-09-80");
    print(cout, data2);
    cout << endl;

    Sales_data data3("ISBN-2012-09-80", 10, 22.2);
    print(cout, data3);
    cout << endl;

    Sales_data data4(cin);
    print(cout, data4);
    cout << endl;
}
