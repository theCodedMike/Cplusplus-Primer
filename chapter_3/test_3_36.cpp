//
// Created by lixia on 2025/8/21.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::size;

bool cmp_vector(const vector<int> &, const vector<int> &);
bool cmp_array(const int *, size_t, const int *, size_t);


int main(int argc, char *argv[]) {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    vector<int> v3 = {1, 2, 4};
    vector<int> v4 = {1, 2, 3, 4};
    cout << "v1 " << (cmp_vector(v1, v2) ? "==" : "!=") << " v2" << endl; // v1 == v2
    cout << "v1 " << (cmp_vector(v1, v3) ? "==" : "!=") << " v3" << endl; // v1 != v3
    cout << "v1 " << (cmp_vector(v1, v4) ? "==" : "!=") << " v4" << endl; // v1 != v4
    cout << endl;

    int a1[3] = {1, 2, 3};
    int a2[3] = {1, 2, 3};
    int a3[3] = {1, 2, 4};
    int a4[4] = {1, 2, 3, 4};
    cout << "a1 " << (cmp_array(a1, size(a1), a2, size(a2)) ? "==" : "!=") << " a2" << endl; // a1 == a2
    cout << "a1 " << (cmp_array(a1, size(a1), a3, size(a3)) ? "==" : "!=") << " a3" << endl; // a1 != a3
    cout << "a1 " << (cmp_array(a1, size(a1), a4, size(a4)) ? "==" : "!=") << " a4" << endl; // a1 != a4
}

bool cmp_array(const int *p1, const size_t len1, const int *p2, const size_t len2) {
    if (len1 != len2)
        return false;
    for (int i = 0;i < len1; i++) {
        if (*(p1 + i) != *(p2 + i))
            return false;
    }
    return true;
}

bool cmp_vector(const vector<int> &v1, const vector<int> &v2) {
    return v1 == v2;
}