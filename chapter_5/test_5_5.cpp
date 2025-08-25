//
// Created by lixia on 2025/8/25.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int grade;
    string letterGrade;
    cout << "Enter your grade: ";
    while (cin >> grade) {
        if (0 <= grade && grade <= 100)
            break;
        cout << "Invalid grade[0-100]. Enter your grade: ";
    }

    if (grade < 60)
        letterGrade = "F";
    else if (grade < 70)
        letterGrade = "D";
    else if (grade < 80)
        letterGrade = "C";
    else if (grade < 90)
        letterGrade = "B";
    else if (grade < 100)
        letterGrade = "A";
    else
        letterGrade = "A++";

    if (60 <= grade && grade < 100) {
        if (grade % 10 > 7)
            letterGrade += '+';
        else if (grade % 10 < 3)
            letterGrade += '-';
    }

    cout << letterGrade << endl;
}
