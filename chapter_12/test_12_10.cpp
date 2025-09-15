//
// Created by lixia on 2025/9/15.
//
#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int>);


int main(int argc, char *argv[]) {
    shared_ptr<int> p(new int(42));
    //process(shared_ptr<int>(p));

    //process(shared_ptr<int>(p.get())); // 程序异常终止

    cout << "main: " << p.use_count() << endl;


    auto p1 = new int();
    auto sp = shared_ptr<int>();
    process(sp);
    //process(new int()); // 类型不匹配
    //process(p1); // 类型不匹配
    process(shared_ptr<int>(p1));

    auto sptr = sp.get();
    delete sptr;
}

void process(shared_ptr<int> sp) {
    cout << "process: " << sp.use_count() << endl; // 2
}