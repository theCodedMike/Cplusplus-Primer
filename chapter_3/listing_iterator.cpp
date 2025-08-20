//
// Created by lixia on 2025/8/20.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

void binary_search(int target);

int main(int argc, char *argv[]) {
    string s = "some string";
    if (s.begin() != s.end()) {
        auto iter = s.begin();
        *iter = toupper(*iter);
    }
    cout << s << endl;

    vector<int>::iterator it; // it能读和写容器内的元素
    string::iterator it2; // it2能读写string中的字符
    vector<int>::const_iterator cit; // cit只能读容器中的元素
    string::const_iterator cit2; // cit2只能读string中的字符

    vector<int> nums = {4, 2, -11};
    auto b = nums.begin(); // b的类型是vector<int>::iterator
    auto cb = nums.cbegin(); // cb的类型是vector<int>::const_iterator
    const vector<int> nums2 = {11, 1024, 999};
    auto b2 = nums2.begin(); // b2的类型是vector<int>::const_iterator

    vector<string> words = {"hello", "what", "", "fuck"};
    // !(*iter).empty()
    for (auto iter = words.cbegin(); iter != words.cend() && !iter->empty(); ++iter) {
        cout << *iter << endl;
    }
    cout << words.cend() - words.cbegin() << endl; // 4

    binary_search(0);
    binary_search(5);
    binary_search(14);
}


void binary_search(int target) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto beg = nums.cbegin(), end = nums.cend();
    auto mid = beg;

    while (beg < end) {
        mid = beg + (end - beg) / 2;

        if (target < *mid)
            end = mid;
        else if (target > *mid)
            beg = mid + 1;
        else {
            cout << "find it..." << endl;
            return;
        }
    }

    cout << "cannot find it..." << endl;
}
