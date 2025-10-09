//
// Created by lixia on 2025/10/9.
//
#include <iostream>

using namespace std;

class Class {
public:
    Class() {
        add_one();
    }

    static void add_one() {
        ++count;
    }
    static int get_count() {
        return count;
    }
private:
    inline static int count = 0;
};
class Base : public Class { };
class D1 : virtual public Base { };
class D2 : virtual public Base { };
class MI : public D1, public D2 { };
class Final : public MI, public Class { };



int main(int argc, char *argv[]) {
    Final final;
    cout << "Final::count = " << Final::get_count() << endl; // 2
}
