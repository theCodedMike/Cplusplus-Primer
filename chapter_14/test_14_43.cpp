//
// Created by lixia on 2025/9/24.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    const vector nums = {160, 8, 24, 40, 56, 80};
    constexpr int div = 6;

    const auto result = std::ranges::all_of(nums, [&](const int i) {
        return equal_to()(modulus()(i, div), 0);
    });
    cout << (result == 0 ? "false" : "true") << endl;
}
