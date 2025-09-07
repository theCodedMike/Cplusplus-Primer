//
// Created by lixia on 2025/9/8.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    string numbers("0123456789"), name("r2d2");
    const size_t pos = numbers.find(name);

    cout << pos << " " << (pos == string::npos) << endl; // 18446744073709551615 1
}
