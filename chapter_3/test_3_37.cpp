//
// Created by lixia on 2025/8/22.
//

#include <iostream>
using std::cout;
using std::endl;

void program1();
void program2();

int main(int argc, char *argv[]) {
    program1();
    cout << "-------------------------------" << endl;
    program2();
}

// 输出结果不可预测
void program1() {
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
}

// 可以正常输出，复合预期
void program2() {
    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
}