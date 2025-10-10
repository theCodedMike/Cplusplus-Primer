//
// Created by lixia on 2025/10/10.
//
#include <iostream>
using namespace std;

class A {};
class B : public A {};
class C : public B {};

int main(int argc, char *argv[]) {
    A *pa = new C;
    cout << typeid(pa).name() << endl; // P1A

    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl; // P1A

    B *pb = new B;
    A &rb = *pb;
    cout << typeid(rb).name() << endl;  // 1A

    delete pa;
    delete pb;
}
