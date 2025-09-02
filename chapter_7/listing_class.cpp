//
// Created by lixia on 2025/9/2.
//

#include <iostream>
#include "../include/Screen.h"
using namespace std;

int main(int argc, char *argv[]) {
    Screen myScreen(5, 3);
    const Screen blank(5, 3);

    myScreen.set('#').display(cout); // 调用非常量版本
    blank.display(cout); // 调用常量版本
}
