//
// Created by lixia on 2025/8/14.
//

#include <iostream>
#include <ostream>

/**
 * 简单的主函数，读取2个数，求它们的和
 * @param argc 命令行参数个数
 * @param argv 各个参数
 */
int main(int argc, char *argv[]) {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;   // 保存我们读入的输入数据的变量
    std::cin >> v1 >> v2; // 读取输入数据
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;

    return 0;
}
