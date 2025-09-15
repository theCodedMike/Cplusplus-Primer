//
// Created by lixia on 2025/9/15.
//

#include <memory>
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    //IntP p0(ix); // ❌
    //IntP p1(pi); cout << *p1 << endl;            // 1024 程序会异常终止
    IntP p2(pi2); cout << *p2 << endl;             // 2048
    //IntP p3(&ix); cout << *p3 << endl;           // 1024 程序会异常终止
    IntP p4(new int(2048)); cout << *p4 << endl;   // 2048
    //IntP p5(p2.get()); cout << *p5 << endl;      // 2048 程序会异常终止
}
