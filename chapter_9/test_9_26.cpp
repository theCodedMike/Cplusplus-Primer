//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include <list>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> vi(begin(ia), end(ia));
    auto v_beg = vi.begin();
    while (v_beg != vi.end()) {
        if (*v_beg % 2 == 0)
            v_beg = vi.erase(v_beg);
        else
            ++v_beg;
    }
    print_collection(vi); // [1, 1, 3, 5, 13, 21, 55, 89]

    list<int> li(ia, ia + size(ia));
    auto l_beg = li.begin();
    while (l_beg != li.end()) {
        if (*l_beg % 2 == 1)
            l_beg = li.erase(l_beg);
        else
            ++l_beg;
    }
    print_collection(li); // [0, 2, 8]
}
