//
// Created by lixia on 2025/10/6.
//
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    const vector<size_t> pos = {1, 2, 3, 5, 8, 13, 21};

    bitset<32> bitvec;
    for (const size_t p: pos) {
        bitvec[p] = true;
    }

    cout << bitvec << endl; // 00000000001000000010000100101110
}
