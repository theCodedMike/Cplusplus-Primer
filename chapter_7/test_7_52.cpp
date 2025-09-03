//
// Created by lixia on 2025/9/3.
//

#include <iostream>
#include "../include/Sales_data.h"

int main(int argc, char *argv[]) {
    const Sales_data item = {"ISBN-978-320183", 25, 15.99};
    print(std::cout, item);
}
