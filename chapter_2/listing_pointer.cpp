//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int iVal = 42;
    int *p = &iVal; // p存放变量iVal的地址，或者说p是指向变量iVal的指针
    std::cout << p << " " << *p << " " << iVal << std::endl; // 0xb1d3fffd64 42 42
    *p = 50;
    std::cout << p << " " << *p << " " << iVal << std::endl; // 0xb1d3fffd64 50 50

    double *dPtr; // 指针在定义时可以缺少初始化，这点与引用不同

    double dVal = 4;
    double *pd = &dVal; // ✔
    double *pd2 = pd; // ✔

    //int* pi = pd; // ❌
    //pi = &dVal; // ❌

    int j = 42;
    int &r = j; // &紧随类型名出现，所以是声明的一部分，r是一个引用
    int *ptr; // *紧随类型名出现，所以是声明的一部分，ptr是一个指针
    ptr = &j; // &出现在表达式中，是一个取地址符
    *ptr = j; // *出现在表达式中，是一个解引用符
    int &r2 = *ptr; // &是声明的一部分，*是一个解引用符

    int *p1 = nullptr; // 等价于 int *p1 = 0; 推荐
    int *p2 = 0; // 直接将p2初始化为字面常量0
    int *p3 = NULL; // 等价于 int *p3 = 0;

    double obj = 8.0902, *pD = &obj;
    void *pv = &obj; // void＊能存放任意类型对象的地址
    pv = pD; // pv可以存放任意类型的指针

    // * 和 & 修饰的是变量/对象名，不修饰类型名
    //int* intPtr, intVal; // intPtr是指向int的指针，intVal是int类型的变量
    int *intPtr, intVal; // 推荐这样写


    std::cout << std::endl;
    // 指向指针的指针
    int age = 30;
    int *pAge = &age; //pAge指向一个int类型的变量
    int **ppAge = &pAge; // ppAge指向一个int类型的指针
    std::cout << "The value of age:\n"
            << "direct value: " << age << '\n'
            << "indirect value: " << *pAge << '\n'
            << "double indirect value: " << **ppAge << '\n';

    std::cout << std::endl;
    // 指向指针的引用
    int num = 42;
    int *pNum; // pNum是一个int类型的指针
    int *&refPNum = pNum; // refPNum是一个int类型的指针的引用

    refPNum = &num; // refPNum引用了一个指针，所以给refPNum赋值就是令pNum指向num
    *refPNum = 0; // 解引用refPNum，就是令num等于0
}
