//
// Created by lixia on 2025/8/23.
//

#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char *argv[])
{
    int i; double d;
    d = i = 3.5;
    cout << "i = " << i << " d = " << d << endl; // i = 3 d = 3
    i = d = 3.5;
    cout << "i = " << i << " d = " << d << endl; // i = 3 d = 3.5
}
