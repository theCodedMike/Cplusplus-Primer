//
// Created by lixia on 2025/8/15.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item total; // 保存下一条交易记录
    // 读入第一条交易记录，并确保有数据可以处理
    if (std::cin >> total) {
        Sales_item trans; // 保存和的变量
        // 读入并处理剩余交易记录
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans; // 更新总销售额
            }else {
                std::cout << total << std::endl;
                total = trans; // total表示下一本书的销售额
            }
        }

        std::cout << total << std::endl; // 打印最后一本书的结果
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
