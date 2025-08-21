//
// Created by lixia on 2025/8/21.
//

#include "../include/Utils.h"
using std::string;
using std::cout;
using std::endl;
using std::size;
using std::begin;
using std::end;

void initialize();
void traverse();
void pointer_and_array();


int main(int argc, char *argv[]) {
    //initialize();
    //traverse();
    pointer_and_array();
}

void initialize() {
    constexpr unsigned sz = 5;
    int nums[sz];
    //print_collection(nums); // 因为没有赋值，所以打印的是随机值

    const unsigned sz2 = 3;
    int ia1[sz2] = {0, 1, 2};
    int ia2[] = {3, 2, 1};
    int ia3[5] = {3, 0, 1};
    cout << ia3 << endl; // 这里打印出一个地址，指向ia3的第1个元素
    print_collection(ia3); // [3, 0, 1, 0, 0]
    //int ia4[3] = {1, 1, 1, 1, 1}; // ❌
    string ia5[3] = {"hi", "hello"};
    print_collection(ia5); // [hi, hello, ]

    char ca1[] = {'C', '+', '+'};
    char ca2[] = {'C', '+', '+', '\0'};
    char ca3[] = "C++";
    //const char ca4[6] = "Daniel"; //❌ 7个字符，最后一个是'\0'
    cout << size(ca1) << " " << ca1 << endl; // 3 C++?  这里的输出有问题
    cout << size(ca2) << " " << ca2 << endl; // 4 C++
    cout << size(ca3) << " " << ca3 << endl; // 4 C++

    // 不能把数组的内容拷贝给其他数组作为其初始值
    int tmp[10] = {0, 2, 3};
    //int tmp2[] = tmp; // ❌
    //tmp2 = tmp;  // ❌

    int *ptrs[10]; // ptrs是含有10个整型指针的数组
    //int &refs[10] = /**/; // ❌ 不能是引用的数组
    int (*pArray)[10] = &tmp; // pArray指向一个含有10个整数的数组
    int (&rArray)[10] = tmp; // rArray引用一个含有10个整数的数组
    int *(*pArray2)[10] = &ptrs; // pArray2指向一个含有10个整数指针的数组
    int *(&rArray2)[10] = ptrs; // rArray2引用一个含有10个整数指针的数组
}

void traverse() {
    int nums[5] = {19, -9, 22, 10, 0};
    // 范围for循环 推荐
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
    // for
    for (int i = 0; i < size(nums); ++i)
        cout << nums[i] << " ";
    cout << endl;

    // 指针
    for (auto beg = std::begin(nums), end = std::end(nums); beg != end; ++beg)
        cout << *beg << " ";
    cout << endl;
    // 指针
    for (int *start = nums, *end = &nums[5]; start != end; ++start)
        cout << *start << " ";
    cout << endl;
}

void pointer_and_array() {
    string names[] = {"Jack", "Tom", "Fuck"};
    string *p = names;
    string *p2 = &names[0]; // p 和 p2 指向同一个数组 等价的
    string *p3 = &names[3]; // 最后一个地址，但不能解引用
    cout << *(names + 0) << " " << names[0] << endl; // Jack
    cout << *(names + 1) << " " << names[1] << endl; // Tom
    cout << *(names + 2) << " " << names[2] << endl; // Fuck

    auto p4(names); // p3的类型是string *
    decltype(names) p5; //p4的类型是string[]
    p5[0] = "1"; p5[1] = "2"; p5[2] = "3";
    print_collection(p5); // [1, 2, 3]
    auto diff = end(p5) - begin(p5); // ptrdiff_t类型，有符号整数
    cout << diff << endl; // 3

    auto pend = end(p5);
    cout << *(pend - 1) << endl; // 3
}