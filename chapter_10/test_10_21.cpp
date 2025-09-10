//
// Created by lixia on 2025/9/10.
//
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int age = 5;
    auto is_zero = [&] {
        if (age > 0)
            --age;
        return age == 0;
    };

    for (int i = 0; i < 10; ++i)
        cout << (is_zero() == 0 ? "false" : "true") << ", age = " << age<< endl;
}
