//
// Created by lixia on 2025/9/6.
//

#include <list>
#include <vector>
#include <string>

#include "../include/Utils.h"
using namespace std;

int main(int argc, char *argv[]) {
    list<char *> lc;
    char name1[] = "Jack";
    char name2[] = "Mike";
    char name3[] = "Lucy";
    char name4[] = "Tom";
    lc.push_back(name1);
    lc.push_back(name2);
    lc.push_back(name3);
    lc.push_back(name4);

    vector<string> names;
    names.assign(lc.begin(), lc.end());
    print_collection(names); // [Jack, Mike, Lucy, Tom]
}
