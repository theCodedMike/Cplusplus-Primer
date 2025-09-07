//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include "../include/Utils.h"
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> vi = {2, 1, 2};
    auto iter = vi.begin();
    int count = 0;

    while (iter != vi.end()) {
        if (*iter % 2) {
            ++count;
            iter = vi.insert(iter, *iter);
            if (count == 5)
                break;
        }

        ++iter;
    }

    print_collection(vi); // [2, 1, 1, 1, 1, 1, 1, 2]
}
