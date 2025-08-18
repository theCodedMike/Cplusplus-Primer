//
// Created by lixia on 2025/8/18.
//

#include <iostream>

#include "../include/Sales_data.h"

int main(int argc, char *argv[]) {
    Sales_data data1, data2;

    double price = 0; // 书的单价，用于计算销售收入
    // 读入第1笔交易
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // 计算销售收入
    data1.revenue = data1.units_sold * price;

    // 读入第2笔交易
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    // 计算销售收入
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        // 输出ISBN、总销售量、总销售额、平均价格
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}
