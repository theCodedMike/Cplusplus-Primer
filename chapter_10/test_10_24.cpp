//
// Created by lixia on 2025/9/10.
//

#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_size(const string &s, const string::size_type sz) {
    return sz > s.size();
}

int main(int argc, char *argv[]) {
    vector<int> nums = {10, 2, 3, 4, 5, 6, 11, 8, 9, 1};
    string target = "helloworld";

    const auto find_iter = std::ranges::find_if(
        nums, std::bind(check_size, target, std::placeholders::_1));
    if (find_iter != nums.end())
        cout << *find_iter << endl;
}



