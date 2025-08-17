//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int main(int argc, char *argv[]) {
    // int &refVal; // 错误，引用必须被初始化

    int iVal = 29;
    int &refVal = iVal;
    std::cout << iVal << " " << refVal << std::endl; // 29 29
    refVal = 33;
    std::cout << iVal << " " << refVal << std::endl; // 33 33
    refVal += 10;
    std::cout << iVal << " " << refVal << std::endl; // 43 43

    int i = 1024, i2 = 2048; // i和i2都是int类型
    int &r = i, r2 = i2;     // r是一个引用，与i绑定在一起；r2是一个int类型
    int i3 = 1024, &ri = i3; // i3是一个int类型；ri是一个引用，与i3绑定在一起
    int &u3 = i3, &r4 = i2;  // r3和r4都是引用

    //int &refVal = 10; // ❌，引用必须绑定一个对象，不能是字面值或某个表达式的计算结果
    double dVal = 3.24;
    //int &refVal = dVal; // ❌，此处引用的初始值必须是int类型
}
