//
// Created by lixia on 2025/8/18.
//

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


int main(int argc, char *argv[]) {
    string one_line;
    cout << "first input: " << endl;
    getline(cin, one_line);

    string one_word;
    cout << "second input: " << endl;
    cin >> one_word;

    cout << one_line << endl;
    cout << one_word << endl;
}
