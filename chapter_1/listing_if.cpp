//
// Created by lixia on 2025/8/14.
//

#include <iostream>

int main(int argc, char *argv[]) {
    // currVal是我们正在统计的数；我们将读入的新值存入val
    int currVal = 0, val = 0;
    // 读取第一个数，并确保确实有数据可以处理
    if (std::cin >> currVal) {
        int cnt = 1; // 保存我们正在处理的当前值的个数
        while (std::cin >> val) { // 读取剩余的数
            if (val == currVal)   // 如果值相同
                ++cnt;            // 将cnt加1
            else {                // 否则，打印前一个值的个数
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;    // 记录新值
                cnt = 1;          // 重置计数器
            }
        } // while循环在这里结束

        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    } // 最外层的if语句在这里结束

    return 0;
}
