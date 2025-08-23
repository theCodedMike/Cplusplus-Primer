//
// Created by lixia on 2025/8/23.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    int input;
    cout << "Enter an integer: ";

    while (cin >> input && input != 42) {
        cout << "Your input is " << input << endl << endl;
        cout << "Enter an integer: ";
    }

    cout << "Over..." << endl;
}
