//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 10; i++) {
        auto val = test_local_var(1);
        cout << i << ": " << get<0>(val) << " " << get<1>(val) << " " << get<2>(val) << endl;
    }
}

tuple<int, int, int> test_local_var(int l) {
    int m = 1;
    static int n = 1;
    return make_tuple(++l, ++m, ++n);
}
