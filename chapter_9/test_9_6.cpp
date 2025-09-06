//
// Created by lixia on 2025/9/6.
//

#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
    list<int> lst1 = {10, -9, 33, 156};
    auto iter1 = lst1.begin(), iter2 = lst1.end();

    while (iter1 != iter2) { // 这里不能用 < <=
        cout << *iter1;
        ++iter1;

        if (iter1 != iter2)
            cout << ", ";
    }
}
