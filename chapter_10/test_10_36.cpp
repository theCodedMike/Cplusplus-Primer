//
// Created by lixia on 2025/9/11.
//

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[]) {
    const list<int> lst = {11, 23, 0, -78, 9, 209, -1, 0, 3};
    auto last_pos = std::find(lst.crbegin(), lst.crend(),0);
    cout << *last_pos << " " << *(--last_pos)<< endl; // 0 3
}
