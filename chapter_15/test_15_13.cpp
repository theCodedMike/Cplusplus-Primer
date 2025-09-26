//
// Created by lixia on 2025/9/26.
//
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Base {
public:
    explicit Base(string s) : basename(std::move(s)) {}
    virtual ~Base() = default;

    const string & name() { return basename; }
    virtual void print(ostream &os) const {
        os << basename;
    }
private:
    string basename;
};

class Derived final : public Base {
public:
    Derived(string s, const int i) : Base(std::move(s)), i(i) { }

    void print(ostream &os) const override {
        Base::print(os);
        os << " " << i;
    }
private:
    int i;
};

int main(int argc, char *argv[]) {
    const Base base("base");
    base.print(cout);
    cout << endl << endl;;

    const Derived derived("derived", 42);
    derived.print(cout);
}
