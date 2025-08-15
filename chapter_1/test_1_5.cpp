//
// Created by lixia on 2025/8/14.
//

#include <iostream>
#include <string>
#include <windows.h>

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);

    double height = 2.05;
    float weight = 70.5;
    int age = 15;
    std::string name = "Zhang San";

    std::cout << "Name: " << name << ", Age: " << age << "岁, Height: " << height << "米, Weight: " << weight << "千克" << std::endl;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << "岁" << std::endl;
    std::cout << "Height: " << height << "米" << std::endl;
    std::cout << "Weight: " << weight << "千克" << std::endl;
}
