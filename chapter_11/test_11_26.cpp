//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    map<int, int> m;
    cout << m[0] << endl; // 0 不会抛异常
    m[0] = 1;
    cout << m[0] << endl; // 1

    m.insert({-5, 5});
    cout << m[-5] << endl; // 5
    m[-10] = 10;
    cout << m[-10] << endl; // 10

    /*
    // 异常终止...
    vector<int> v;
    v[0] = 1;
    cout << v[0] << endl;
    */
}
