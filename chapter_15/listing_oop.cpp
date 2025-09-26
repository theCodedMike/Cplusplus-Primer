//
// Created by lixia on 2025/9/25.
//
#include <iostream>
#include "../include/Quote.h"

using namespace std;

class Base {
public:
    static void statmem(); // 在基类和派生类中都是唯一的
};

void Base::statmem() {
    cout << "Base::statmem()...";
    cout << endl;
}


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
    const Bulk_quote bulk;
    Quote item(bulk); // 使用Quote::Quote(const Quote&)构造函数
    item = bulk; // 使用Quote::operator=(const Quote&)

    const Quote base("ISBN-911", 5.99);
    print_total(cout, base, 10); // 调用Quote::net_price
    const Bulk_quote derived("ISBN-912", 9.99, 5, 0.2);
    print_total(cout, derived, 10); // 调用Bulk_quote::net_price

    double price = derived.Quote::net_price(10); // 强制使用基类中定义的函数版本
    cout << "price: " << price << endl; // 99.9
    price = derived.net_price(10);
    cout << "price: " << price << endl; // 79.92
}
