//
// Created by lixia on 2025/9/25.
//
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "../include/Quote.h"

using namespace std;

class Base {
public:
    static void statmem(); // 在基类和派生类中都是唯一的

    explicit Base(const int prot) : prot_mem(prot) {
        if (prot_mem < 0) {
            cerr << "prot_mem < 0" << endl;
            prot_mem = 0;
        }
    }
    virtual ~Base() = default;

protected:
    int prot_mem;
};

void Base::statmem() {
    cout << "Base::statmem()...";
    cout << endl;
}


class Derived final: public Base { // final表明Derived是不可被继承的
    friend void clobber(Derived &);
    friend void clobber(Base &);

public:
    Derived(const int prot, const int i) :
        Base(prot), j(i) { }

    void f(const Derived &);

private:
    // using Base::prot_mem; //可以通过这种方式改变访问权限
    int j;
};

void Derived::f(const Derived & derived_obj) {
    Base::statmem();       // ✔
    Derived::statmem();    // ✔
    derived_obj.statmem(); // ✔
    statmem();             // ✔
}

void clobber(Derived & d) {
    d.j = d.prot_mem = 10; // ✔
}

void clobber(Base & b) {
    //b.prot_mem = 20; // ❌ prot_mem访问不到
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

    vector<Quote> quotes;
    quotes.push_back(derived);
    cout << quotes.back().net_price(10) << endl; // 99.9 这里派生类部分被忽略了

    vector<shared_ptr<Quote>> basket; // 使用容器存储对象时，推荐使用shared_ptr
    basket.push_back(make_shared<Bulk_quote>(derived));
    cout << basket.back()->net_price(10) << endl; // 79.92
}
