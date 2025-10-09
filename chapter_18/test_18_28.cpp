//
// Created by lixia on 2025/10/9.
//

#include <iostream>
using namespace std;

struct Base {
    void bar(int);
protected:
    int ival = 1;
};

struct Derived1 : virtual public Base {
    void bar(char);
    void foo(char);
protected:
    char cval = 'A';
};

struct Derived2 : virtual public Base {
    void foo(int);
protected:
    int ival = 10;
    char cval = 'Z';
};

class VMI : public Derived1, public Derived2 {
public:
    void print_derivec2_ival() const {
        cout << ival << endl;
    }
    void print_base_ival() const {
        cout << Base::ival << endl;
    }

    void print_derived1_cval() const {
        cout << Derived1::cval << endl;
    }
    void print_derived2_cval() const {
        cout << Derived2::cval << endl; // 这里必须指定Derived2::
    }
};

int main(int argc, char *argv[]) {
    const VMI vmi;
    vmi.print_base_ival();     // 1
    vmi.print_derivec2_ival(); // 10
    vmi.print_derived1_cval(); // A
    vmi.print_derived2_cval(); // Z
}
