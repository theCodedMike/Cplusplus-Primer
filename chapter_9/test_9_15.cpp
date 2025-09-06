//
// Created by lixia on 2025/9/6.
//

#include <iostream>
#include <vector>
using namespace std;

bool compare_vector(const vector<int> &v1, const vector<int> &v2);

int main(int argc, char *argv[]) {
    const vector<int> v1 = {1, 2, 3, 4, 5};
    const vector<int> v2 = {1, 2, 3, 4, 5};

    cout << "v1 == v2 : " << compare_vector(v1, v2) << endl;
}

bool compare_vector(const vector<int> &v1, const vector<int> &v2) {
    const auto v1_size = v1.size();
    if (const auto v2_size = v2.size(); v1_size != v2_size)
        return false;

    for (auto i = 0; i != v1_size; ++i) {
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}