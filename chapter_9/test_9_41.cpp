//
// Created by lixia on 2025/9/7.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    vector<char> vc = {'a', 'b', 'c'}; // 因为最后一个字符不是'\0'，所以下面初始化时需要指定个数
    const string s(vc.begin(), vc.end());
    cout << s << endl; // abc

    const string s2(&vc[0], vc.size());
    cout << s2 << endl; // abc

    const string s3(&vc.at(0), vc.size());
    cout << s3 << endl; // abc

    const string s4(vc.data(), vc.size());
    cout << s4 << endl; // abc

    const string s5(&vc.front(), vc.size());
    cout << s5 << endl; // abc
}
