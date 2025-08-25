//
// Created by lixia on 2025/8/25.
//

#include <vector>
#include <iostream>
using namespace std;

bool is_prefix(const vector<int> &, const vector<int> &);

int main(int argc, char *argv[]) {
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    cout << is_prefix(v1, v2) << endl;
}

bool is_prefix(const vector<int> &v1, const vector<int> &v2) {
    const size_t size = v1.size() <= v2.size() ? v1.size() : v2.size();

    for (auto i = 0; i < size; ++i) {
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}