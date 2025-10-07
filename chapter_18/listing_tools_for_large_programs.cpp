//
// Created by lixia on 2025/10/7.
//
#include <iostream>
#include "../include/Sales_data.h"

using namespace std;

int main(int argc, char *argv[]) {

}

void manip() {
    try {
        // ...
    } catch (...) {
        // 处理异常的某些特殊操作
        throw; // 再往外抛
    }
}

class Base {
public:
    virtual ~Base() = default;

    virtual double f1(double) noexcept; // 不会抛出异常
    virtual int f2() noexcept(false);   // 可能抛出异常
    virtual void f3();                  // 可能抛出异常
};
class Derived final : public Base {
public:
    //double f1(double); // ❌ Base::f1承诺不会抛出异常
    double f1(double) noexcept override;
    int f2() noexcept(false) override; // ✔ 与Base::f2的异常说明一致
    void f3() noexcept override; // ✔ Derived的f3做出更严格的限定
};

void customize_exception() {
    Sales_data item1, item2;
    while (cin >> item1 >> item2) {
        try {
            Sales_data sum = item1 + item2;
            cout << sum << endl << endl;
        } catch (const isbn_mismatch &e) {
            cerr << e.what() << ": left isbn(" << e.left
            << "), right isbn(" << e.right << ")\n";
        }
    }
}