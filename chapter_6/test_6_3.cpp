//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"


int main(int argc, char *argv[]) {
    cout << "5! = " << fact_for(5) << endl;
    cout << "10! = " << fact_for(10) << endl;
    cout << "100! = " << fact_for(100) << endl;
}

long double fact_for(const unsigned int n) {
    long double result = 1;
    for (unsigned int i = 1; i <= n; ++i)
        result *= i;

    return result;
}
