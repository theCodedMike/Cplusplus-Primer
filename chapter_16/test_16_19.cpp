//
// Created by lixia on 2025/10/3.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename Container>
void print(const Container &v) {
    typename Container::size_type len = v.size();

    for (auto i = 0; i < len; ++i) {
        cout << v[i] << " ";
    }
}
int main(int argc, char *argv[]) {
    const vector<int> nums = {1, 2, 3, 4, 5};
    print(nums);
    cout << endl;

    const vector<string> prog_langs = {"C++", "Java", "Python", "C"};
    print(prog_langs);
}
