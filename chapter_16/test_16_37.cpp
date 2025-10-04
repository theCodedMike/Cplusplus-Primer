//
// Created by lixia on 2025/10/4.
//
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    constexpr int age = 25;
    constexpr double height = 1.75;

    //constexpr auto max = std::max(age, height); //模板参数不匹配
    constexpr auto max = std::max(static_cast<double>(age), height);
    cout << max << endl;
}
