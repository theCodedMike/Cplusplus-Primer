//
// Created by lixia on 2025/10/6.
//

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

struct Test {
    vector<bool> results;

    explicit Test(const size_t len) : results(len, false) {
        results.shrink_to_fit();
    }

    [[nodiscard]] size_t size() const {
        return results.size();
    }
    [[nodiscard]] size_t cap() const {
        return results.capacity();
    }
};


int main(int argc, char *argv[]) {
    auto test = Test(10);
    cout << endl << endl;
    cout << test.size() << " " << test.cap() << endl;
}
