//
// Created by lixia on 2025/10/10.
//
#include <iostream>
#include <windows.h>

#include "../include/Screen.h"
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
void use_enum();

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    //test_oop();
    //typeid_cmp();
    //use_rtti();
    use_enum();
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

void use_enum() {
    // 限定作用域的枚举类型 scoped enumeration
    enum class open_modes {
        input, output, append
    };
    // 不限定作用域的枚举类型 unscoped enumeration
    enum color {
        red, yellow, green
    };
    enum class int_types {
        char_type = 8, short_type = 16, int_type = 16, long_type = 32, long_long_type = 64
    };

    constexpr int i = color::yellow; // ✅
    //int j = int_types::short_type; // ❌ 限定作用域的枚举类型不能进行隐式转换
    cout << red <<" " << i << " " << green << endl; // 0 1 2

    // 指定enum的大小
    enum intValues : unsigned long long { // 默认是int类型
        // ...
    };
}

void ptr_to_mem() {
    // pointer to member
    //auto pdata = &Screen::contents;
    //const string Screen::*pdata = &Screen::contents; // 指向类成员变量的指针
    //auto pmf = &Screen::display; // 成员函数指针
    //Screen s;
    //s.*pdata;
    //(s.*pmf)(cout)
}

void nested_class() {
    class TextQuery {
    public:
        class QueryResult; // 稍后定义
    };
    class TextQuery::QueryResult {
        // ....
    };
}

void use_union() {
    // Token类型的对象只有一个成员，该成员的类型可能是下列类型中的任意一种
    union Token { // 默认是public
        char cval;
        int ival;
        double dval;
    };
    Token first = { 'a' };
    Token last;
    Token *pt = new Token;
    last.cval = 'z';
    pt->ival = 42;

    delete pt;
}

void bit_field() {
    typedef unsigned int Bit;
    class File {
        Bit mode: 2; // mode占2位
        Bit modified: 1;
        Bit prot_owner: 3;
        Bit prot_group: 3;
        Bit prot_world: 3;

    public:
        enum modes {
            READ = 01, WRITE = 02, EXECUTE = 03
        };
        File & open(modes) {
            mode |= READ;
            if (mode & WRITE)
                ;//...
            return *this;
        }
        void close() {
            if (modified)
                ; // save
        }
        void write() {
            modified = 1;
            // ...
        }
        bool is_read() const {
            return mode & READ;
        }
        void set_write() {
            mode |= WRITE;
        }
    };
}

void use_volatile() {
    volatile int display_register; // 该int值可能发生改变
    volatile int iax[10]; // iax的每个元素都是volatile
    volatile Screen s; // s的每个成员都是volatile
}

void linkage_directive() {
    /*
    // cstring
    extern "C" size_t strlen(const char *);
    extern "C" {
        int strcmp(const char *, const char *);
        char *strcat(char *, const char *);
    }*/
}