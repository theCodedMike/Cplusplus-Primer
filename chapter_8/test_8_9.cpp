//
// Created by lixia on 2025/9/5.
//

#include <iostream>
#include <sstream>
using namespace std;

std::istream & input(std::istream &is) {
    string input;
    getline(is, input);
    cout << "what you enter: " << input << endl;

    is.clear();
    return is;
}


int main(int argc, char *argv[]) {
    string s = "hello world";
    istringstream sin(s);
    input(sin);
}
