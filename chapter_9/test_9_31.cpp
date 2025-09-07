//
// Created by lixia on 2025/9/7.
//

#include <list>
#include <forward_list>

#include "../include/Utils.h"
using namespace std;

void remove_even_and_copy_odd_in_list();
void remove_even_and_copy_odd_in_forward_list();

int main(int argc, char *argv[]) {
    remove_even_and_copy_odd_in_list();
    //remove_even_and_copy_odd_in_forward_list();
}

// 删除偶数值，并复制奇数值
void remove_even_and_copy_odd_in_list() {
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto curr = lst.begin();

    while (curr != lst.end()) {
        if (*curr % 2 == 1) {
            curr = lst.insert(curr, *curr);
            ++curr;
            ++curr;
        } else {
            curr = lst.erase(curr);
        }
    }

    print_collection(lst); // [1, 1, 3, 3, 5, 5, 7, 7, 9, 9]
}

// 删除偶数值，并复制奇数值
void remove_even_and_copy_odd_in_forward_list() {
    forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flist.before_begin();
    auto curr = flist.begin();

    while (curr != flist.end()) {
        if (*curr % 2 == 1) {
            curr = flist.insert_after(prev, *curr);
            ++curr;
            ++curr;
            ++prev;
            ++prev;
        } else {
            curr = flist.erase_after(prev);
        }
    }

    print_collection(flist); // [1, 1, 3, 3, 5, 5, 7, 7, 9, 9]
}