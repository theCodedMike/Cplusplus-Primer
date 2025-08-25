//
// Created by lixia on 2025/8/25.
//

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    int grade;
    cout << "Enter your grade: ";
    while (cin >> grade) {
        if (0 <= grade && grade <= 100)
            break;
        cout << "Invalid grade[0-100]. Enter your grade: ";
    }

    string letterGrade = grade < 60
                             ? "F"
                             : grade < 70
                                   ? "D"
                                   : grade < 80
                                         ? "C"
                                         : grade < 90
                                               ? "B"
                                               : grade < 100
                                                     ? "A"
                                                     : "A++";
    if (60 <= grade && grade < 100) {
        letterGrade += grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";
    }

    cout << letterGrade << endl;
}
