//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <memory>
#include <list>
#include "../include/StrBlob.h"
#include "../include/TextQuery.h"

using namespace std;

void use_shared_ptr();
void managing_memory_directly();
void use_unique_ptr();
void use_weak_ptr();
void use_dynamic_arrays();
void use_allocator();
void text_query_program();

int main(int argc, char *argv[]) {
    //use_shared_ptr();
    //managing_memory_directly();
    //use_unique_ptr();
    //use_weak_ptr();
    //use_dynamic_arrays();
    //use_allocator();
    text_query_program();
}

void use_shared_ptr() {
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;
    if (p1 && p1->empty())
        *p1 = "hello";

    shared_ptr<int> p3 = make_shared<int>(10); // 推荐使用这种创建方式
    shared_ptr<string> p4 = make_shared<string>(7, 's');
    auto p5 = make_shared<int>(); // p5指向的对象只有p5一个引用者
    cout << *p5 << ", address is " << p5 << endl;

    auto q(p5); // q和p5指向同一个对象，该对象有2个引用者

    p3 = make_shared<int>(44); // 原对象"10"所在内存会被释放，p3的引用计数为0。然后又被指向"44"所在的对象，引用计数又变为1
    cout << p3.use_count() << endl; // 1
    cout << endl;

    StrBlob my_str;
    my_str.push_back("hello");
    my_str.push_back("world");
    my_str.push_back("ok");
    cout << my_str.size() << endl; // 3
    cout << my_str.front() << endl;// hello
    cout << my_str.back() << endl;// ok
    my_str.pop_back();
    cout << my_str.back() << endl; // world
}

void managing_memory_directly() {
    string *ps1 = new string; // 默认初始化为空string
    string *ps2 = new string(); // 值初始化为空string
    string *ps3 = new string(5, 'a');
    int *pi1 = new int;   // 值未定义
    int *pi2 = new int(); // 值初始化为0
    int *pi3 = new int(10);
    cout << *pi1 << ", " << *pi2 << ", " << *pi3 << endl; // 123691152, 0, 10

    const int * pci = new const int(10);
    const string * pcs = new const string;
    delete pci;
    delete pcs;
    pci = nullptr; // ✔ 明确指出pci不指向任何对象
    pcs= nullptr;

    int *p1 = new int; // 如果分配失败，new抛出std::bad_alloc
    int *p2 = new (nothrow) int; // 如果分配失败，new返回一个空指针

    int i, *pi4 = &i, *pi5 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    //delete i; //❌ i不是指针
    delete pi4; // 未定义，pi4指向一个局部变量
    delete pd;  // ✔
    delete pd2; //未定义，pd2指向的内存已经被释放了
    delete pi5; // ✔ 释放空指针没什么错

    //shared_ptr<int> spi1 = new int(1024); // ❌ 必须使用直接初始化
    shared_ptr<int> spi2(new int(1024)); // ✔

    shared_ptr<int> spi(new int(40)); // 引用计数为1
    int * pi = spi.get(); // ✔，使用pi时记得不要让它管理的指针被释放
    {
        shared_ptr<int>(pi); // 未定义，2个独立的shared_ptr指向相同的内存
    } // 程序块结束，pi被销毁，它所指向的内存被释放
    int foo = *spi; // 未定义 spi指向的内存已被释放
}

void use_unique_ptr() {
    unique_ptr<double> p1; // 指向一个double
    //unique_ptr<double> p2(new int(1024)); // C++11
    auto p2 = make_unique<int>(1024); // C++14 推荐
    //auto p3(p2); // ❌ unique_ptr不支持拷贝
    unique_ptr<int> p3;
    //p3 = p2; // ❌ unique_ptr不支持赋值

    unique_ptr<int> p4(p2.release()); // 所有权从p2转移给p4，p2置空
    p3.reset(p4.release()); // p3原来指向的内存被释放，所有权从p4转移到p3
    cout << *p3 << endl; // 1024
}

void use_weak_ptr() {
    const auto sp = make_shared<int>(100);
    const weak_ptr<int> wp(sp);
    cout << wp.use_count() << endl; // 1
    if (!wp.expired())
        cout << *wp.lock() << endl; // 100
}

size_t get_size() {
    return 0;
}

void use_dynamic_arrays() {
    size_t sz = 10; // 必须是整型，不必是常量
    int *pia = new int[sz]; // 10个未初始化的int
    delete []pia;

    typedef int arrT[40];
    int *pia2 = new arrT;
    delete []pia2;

    int *pia3 = new int[sz](); // 10个值初始化为0的int数组
    int *pia4 = new int[sz] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    delete []pia3;
    delete []pia4;

    char arr[get_size()]; // ❌ 不能定义长度为0的数组
    char *cp = new char[get_size()]; // ✔ cp不能解引用
    delete []cp;

    unique_ptr<int[]> up(new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    for (auto i = 0; i < 10; ++i)
        cout << up[i] << " ";
    up.release(); // 自动用delete[]销毁其指针
    cout << endl;

    shared_ptr<int> sp(new int[10](), [](const int *p) { delete[] p; });
    for (auto i = 0, *p = sp.get(); i < 10; ++i)
        cout << p[i] << " ";
    sp.reset(); cout << endl;

    string *const p = new string[sz];
    string s;
    string *q = p;
    while (cin >> s && q != p + sz) {
        if (s == "quit")
            break;
        *q++ = s;
    }
    delete []p;
}

void use_allocator() {
    const size_t n = 10;
    allocator<string> alloc; // 可以分配string的allocator对象
    const auto p = alloc.allocate(n); // 分配n个未初始化的string

    auto q = p;
    //alloc.construct(q++); // C++20已移除该api
    allocator_traits<allocator<string>>::construct(alloc, q++); // *q为空字符串
    allocator_traits<allocator<string>>::construct(alloc, q++, 10, 'c'); // *q为cccccccccc
    allocator_traits<allocator<string>>::construct(alloc, q++, "hi"); // *q为hi
    while (q != p) {
        //alloc.destroy(--q); // C++20已移除该api
        auto tmp = --q;
        cout << *tmp << " ";
        allocator_traits<allocator<string>>::destroy(alloc, q); // 释放真正构造的string
    }
    cout << endl;
    alloc.deallocate(p, n); // 释放内存

    vector<int> nums = {1, 2, 3, 4, 5};
    allocator<int> alloc2;
    auto pi = alloc2.allocate(nums.size() * 2);
    auto qi = uninitialized_copy(nums.cbegin(), nums.cend(), pi);
    auto end = uninitialized_fill_n(qi, nums.size(), 10);
    while (end-- != pi) {
        cout << *end << " "; // 10 10 10 10 10 5 4 3 2 1
        allocator_traits<allocator<int>>::destroy(alloc2, end);
    }
    cout << endl;
    alloc2.deallocate(pi, nums.size() * 2);
}

void run_queries(ifstream & infile) {
    const TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}
void text_query_program() {
    const string file_path = "./Youth.txt";
    ifstream infile(file_path);
    if (!infile.is_open()) {
        cerr << "cannot open file" + file_path << endl;
        return;
    }

    run_queries(infile);
}