//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"


int main(int argc, char *argv[]) {
    int n;
    while (true) {
        cout << "Enter an non negative integer: ";
        cin >> n;
        if (n >= 0)
            break;

        cout << "Sorry, ";
    }

    cout << n << "! = " << fact_while(n) << endl;
}

long double fact_while(unsigned int n) {
    long double result = 1;

    while (n > 0)
        result *= n--;

    return result;
}
