//
// Created by lixia on 2025/10/6.
//

#include <bitset>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
    bitset<64> bitvec(32); cout << bitvec << endl;
    // 0000000000000000000000000000000000000000000000000000000000100000

    bitset<32> bv(1010101); cout << bv << endl;
    // 00000000000011110110100110110101

    string bstr; cin >> bstr; // 只能输入0、1
    bitset<8> sbv(bstr); cout << sbv << endl;
    // 输入110010100001
    //    11001010 如果输入超过8位，会截取前8位
}
