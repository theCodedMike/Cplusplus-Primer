//
// Created by lixia on 2025/8/15.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int i = 20; // 十进制
    int j = 024; // 八进制
    int k = 0x14; // 十六进制
    int l = 0b10100; // 二进制
    std::cout << i << " " << j << " " << k << " " << l << std::endl; // 20 20 20 20

    float f = 1.2;
    double d = 1.2E1;
    std::cout << f << " " << d << std::endl; // 1.2 12

    char c = 'w';
    std::string s = "What the Fuck!";
    std::cout << c << " " << s << std::endl; // w What the Fuck!
    std::cout << "a really, really long string literal "
            "that spans two lines" << std::endl; // a really, really long string literal that spans two lines
}
