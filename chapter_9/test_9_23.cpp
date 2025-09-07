//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> v = {10};

    if (!v.empty()) {
        cout << "val1 = " << *v.begin() << endl;    // val1 = 10
        cout << "val2 = " << v.front() << endl;     // val2 = 10
        cout << "val3 = " << *(v.end() - 1) << endl;// val3 = 10
        cout << "val4 = " << v.back() << endl;      // val4 = 10
    }
}
