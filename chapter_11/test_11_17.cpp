//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void test_1();
void test_2();
void test_3();
void test_4();

int main(int argc, char *argv[]) {
    //test_1();
    //test_2();
    //test_3();
    test_4();
}

void test_1() {
    multiset<string> c = {"a", "b", "c", "d", "e", "f"};
    vector<string> v = {"u", "v", "w", "x", "y", "z"};

    std::copy(v.begin(), v.end(), inserter(c, c.end()));

    for (const auto &val: c) {
        cout << val << " "; // a b c d e f u v w x y z
    }
}

void test_2() {
    multiset<string> c = {"a", "b", "c", "d", "e", "f"};
    vector<string> v = {"u", "v", "w", "x", "y", "z"};

    // ❌ multiset没有push_back()
    //std::copy(v.begin(), v.end(), back_inserter(c));

    for (const auto &val: c) {
        cout << val << " "; // a b c d e f u v w x y z
    }
}

void test_3() {
    multiset<string> c = {"a", "b", "c", "d", "e", "f"};
    vector<string> v = {"u", "v", "w", "x", "y", "z"};

    std::copy(c.begin(), c.end(), inserter(v, v.end()));

    for (const auto &val: v) {
        cout << val << " "; // u v w x y z a b c d e f
    }
}

void test_4() {
    multiset<string> c = {"a", "b", "c", "d", "e", "f"};
    vector<string> v = {"u", "v", "w", "x", "y", "z"};

    std::copy(c.begin(), c.end(), back_inserter(v));

    for (const auto &val: v) {
        cout << val << " "; // u v w x y z a b c d e f
    }
}