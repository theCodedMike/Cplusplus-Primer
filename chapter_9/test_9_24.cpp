//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    const vector<int> v;

    cout << "v.at(0) = " << v.at(0) << endl;    // std::out_of_range
    cout << "v[0] = " << v[0] << endl;            // 程序异常终止
    cout << "v.front() = " << v.front() << endl;  // 程序异常终止
    cout << "v.begin() = " << *v.begin() << endl; // 程序异常终止
}