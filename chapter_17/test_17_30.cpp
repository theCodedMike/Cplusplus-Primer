//
// Created by lixia on 2025/10/6.
//
#include <iostream>
#include <random>

using namespace std;

unsigned int gen_rand_num(const unsigned seed, const unsigned int min = 0, const unsigned int max = 2147483646) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution u(min, max);
    return u(e);
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i)
        cout << gen_rand_num(i, 0, 100) << " ";
    cout << endl;
    for (int i = 0; i < 10; ++i)
        cout << gen_rand_num(i, 0, 100) << " ";
}
