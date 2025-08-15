//
// Created by lixia on 2025/8/14.
//

#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Enter two integers: ";
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 > v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    int count = 0;
    /*
    while (v1 <= v2) {
        std::cout << v1 << " ";
        ++count;
        if (count % 10 == 0)
            std::cout << std::endl;
        v1++;
    }
    */
    for (; v1 <= v2; ++v1) {
        std::cout << v1 << " ";
        ++count;
        if (count % 10 == 0)
            std::cout << std::endl;
    }
}
