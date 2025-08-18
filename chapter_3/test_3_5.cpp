//
// Created by lixia on 2025/8/18.
//

#include <iostream>
#include <string>
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char *argv[]) {
    string str_without_delimiter, str_with_delimiter, tmp;

    while (getline(cin, tmp)) {
        str_without_delimiter += tmp;
        str_with_delimiter += tmp + ' ';
    }

    cout << str_without_delimiter << endl;
    cout << str_with_delimiter << endl;

}
