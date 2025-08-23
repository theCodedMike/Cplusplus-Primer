//
// Created by lixia on 2025/8/23.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string get_result(int);
string get_result2(int);

int main(int argc, char *argv[]) {
    int input;
    cout << "Enter your grade: ";
    cin >> input;

    cout << "The result is " << get_result(input) << endl;
    cout << "The result is " << get_result2(input) << endl;
}

string get_result(const int grade) {
    return grade >= 90 ? "high pass" :
    grade >= 75 ? "pass" :
    grade >= 60 ? "low pass" : "fail";
}

string get_result2(const int grade) {
    string result;
    if (grade >= 90)
        result = "high pass";
    else if (grade >= 75)
        result = "pass";
    else if (grade >= 60)
        result = "low pass";
    else
        result = "fail";

    return result;
}