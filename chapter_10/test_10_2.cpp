//
// Created by lixia on 2025/9/9.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    const list<string> names = {"Mike", "John", "Tomos", "Adam", "Bill", "Willian", "Mike", "Bill"};
    const string target = "Mike";

    const auto result = ranges::count(names, target);
    cout << result << endl; // 2
}