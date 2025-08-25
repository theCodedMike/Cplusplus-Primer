//
// Created by lixia on 2025/8/25.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void switch_statement();
void if_statement();
void simple_statement();
void do_while();

int main(int argc, char *argv[]) {
    // 简单语句
    //simple_statement();

    // 语句作用域
    while (int i = 10 && i > 20)
        cout << i << endl;
    //i = 11; // ❌

    // 条件语句
    //if_statement();
    //switch_statement();

    // 迭代语句
    do_while();
}

void simple_statement() {
    int ival = 0;
    ival + 5; // 表达式语句
    cout << ival << endl;
    string input;
    while (cin >> input && input != "quit"); // 空语句
}

void if_statement() {
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string letterGrade;
    int grade;
    cin >> grade;
    if (grade < 60)
        letterGrade = scores[0];
    else {
        letterGrade = scores[(grade - 50) / 10];
        if (grade != 100) {
            if (grade % 10 > 7)
                letterGrade += '+';
            else if (grade % 10 < 3)
                letterGrade += '-';
        }
    }

    cout << letterGrade << endl;
}

void switch_statement() {
    string input;
    getline(cin, input);

    // 统计各个元音字符的出现次数
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    for (const char &ch: input) {
        switch (ch) {
            case 'a': ++aCnt;break;
            case 'e': ++eCnt;break;
            case 'i': ++iCnt;break;
            case 'o': ++oCnt;break;
            case 'u': ++uCnt;break;
            default: break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << endl;

    // 统计元音字符的出现次数
    unsigned vowelCnt = 0;
    for (const char & ch: input) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt; break;
            default: break;
        }
    }
    cout << "Number of vowel: \t" << vowelCnt << endl;
}

void do_while() {
    string rsp;
    do {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
        << " = " << val1 + val2 << endl << endl
        << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}