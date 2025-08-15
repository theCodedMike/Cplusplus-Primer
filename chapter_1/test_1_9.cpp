//
// Created by lixia on 2025/8/14.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int sum = 0;

    /*
    int i = 50;
    while (i <= 100) {
        sum += i;
        i++;
    }
    */

    for (int i = 50; i <= 100; i++)
        sum += i;

    std::cout << "50 + 51 + ... + 100 = " << sum << std::endl;
}
