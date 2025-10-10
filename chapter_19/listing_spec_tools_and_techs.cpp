//
// Created by lixia on 2025/10/10.
//
#include <iostream>
#include <windows.h>
using namespace std;

class Base {
public:
    Base() = default;
    Base(string name, const int id)
        : name(std::move(name)), id(id) {}
    virtual ~Base() = default;

    void print_name() const {
        cout << "Base print_name...." << endl;
    }

    virtual void execute() const {
        cout << "Base execute...." << endl;
    }

protected:
    virtual bool equal(const Base & rhs) const {
        return name == rhs.name && id == rhs.id;
    }

private:
    string name;
    int id = 0;
};

class Derived final: public Base {
public:
    Derived() = default;
    Derived(string name, const int id, const int level)
        : Base(std::move(name), id), level(level) {}
    ~Derived() override = default;

    void print_name() const {
        cout << "Derived print_name...." << endl;
    }

    void execute() const override {
        cout << "Derived execute...." << endl;
    }

    bool equal(const Base & rhs) const override {
        const auto r = dynamic_cast<const Derived&>(rhs);
        return Base::equal(r) && level == r.level;
    }

private:
    int level = 0;
};




void test_oop();
void typeid_cmp();
void use_rtti();

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    //test_oop();
    //typeid_cmp();
    use_rtti();
}

void test_oop() {
    const Base base;
    base.print_name(); // Base print_name....
    base.execute();    // Base execute....

    Derived derived;
    derived.print_name(); // Derived print_name....
    derived.execute();    // Derived execute....

    Base other_base = derived;
    other_base.print_name(); // Base print_name....
    other_base.execute();    // Base execute....

    Base & other_base2 = derived;
    other_base2.print_name(); // Base print_name....
    other_base2.execute();    // Derived execute....
}

void ref_cast(const Base &b) {
    try {
        const auto &d = dynamic_cast<const Derived&>(b);
    } catch (bad_cast &e) {
        // 处理类型转换失败的情况
    }
}

void ptr_cast(const Base *bp) {
    if (const auto *dp = dynamic_cast<const Derived*>(bp)) {
        // 使用dp指向的Derived对象
    } else {
        // bp指向Base对象
    }
}

void typeid_cmp() {
    auto *dp = new Derived;
    Base *bp = dp;
    if (typeid(*bp) == typeid(*dp)) {
        cout << "bp和dp指向同一类型的对象" << endl;
    }
    if (typeid(*bp) == typeid(Derived)) {
        cout << "bp实际指向Derived对象" << endl;
    }
    delete dp;
}

void use_rtti() {
    Derived d1("Tom", 10086, 1);
    Derived d2("Tom", 10086, 1);
    cout << d1.equal(d2) << endl;

    int arr[10];
    Base *p = &d1;
    cout << typeid(42).name() << endl          // i
         << typeid(arr).name() << endl         // A10_i
         << typeid(std::string).name() << endl // NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
         << typeid(Derived).name() << endl     // 7Derived
         << typeid(p).name() << endl           // P4Base
         << typeid(*p).name() << endl;         // 7Derived
}