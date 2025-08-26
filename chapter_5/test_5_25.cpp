//
// Created by lixia on 2025/8/26.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    while (true) {
        try {
            int divisor, dividend;
            cout << "Enter two integers: ";
            cin >> divisor >> dividend;

            if (dividend == 0)
                throw runtime_error("Dividend cannot be zero.");

            cout << divisor << " / " << dividend << " = " << (divisor / dividend) << endl;
            break;
        } catch (runtime_error &err) {
            cout << err.what() << endl;
            cout << "Try again? Enter y or n: ";
            char c;
            cin >> c;
            if (c == 'n')
                break;
        }
    }

    cout << "Over..." << endl;
}
