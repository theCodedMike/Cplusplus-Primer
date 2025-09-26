//
// Created by lixia on 2025/9/25.
//

#include "../include/Quote.h"

class Base {
public:
    static void statmem(); // 在基类和派生类中都是唯一的
};

class Derived final: public Base { // Derived不能作为基类
    void f(const Derived &);
};

void Derived::f(const Derived & derived_obj) {
    Base::statmem();       // ✔
    Derived::statmem();    // ✔
    derived_obj.statmem(); // ✔
    statmem();             // ✔
}



int main(int argc, char *argv[]) {
    Bulk_quote bulk;
    Quote item(bulk); // 使用Quote::Quote(const Quote&)构造函数
    item = bulk; // 使用Quote::operator=(const Quote&)
}
