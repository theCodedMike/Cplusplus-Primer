//
// Created by lixia on 2025/9/8.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

double compute_expression(const string &);

int main(int argc, char *argv[]) {
    cout << compute_expression("1 + 2 + 3 + 4 + 5") << endl; // 15
    cout << compute_expression("1 + 2 * 3 / 3") << endl; // 3
    cout << compute_expression("(1 + 2) * (3 - 5)") << endl; // -6
    cout << compute_expression("(3 * ((5 - 4) * 4))") << endl; // 12
}


double calculate(const double &l_num, const double &r_num, const char &op) {
    switch (op) {
        case '+': return l_num + r_num;
        case '-': return l_num - r_num;
        case '*': return l_num * r_num;
        case '/':
            if (r_num == 0)
                throw invalid_argument("expression error");
            return l_num / r_num;
        default: throw invalid_argument("expression error");
    }
}

void compute(stack<double> &num, stack<char> &op) {
    if (num.empty())
        throw invalid_argument("expression error");
    double r_num = num.top();
    num.pop();

    if (num.empty())
        throw invalid_argument("expression error");
    double l_num = num.top();
    num.pop();

    if (op.empty()) {
        throw invalid_argument("expression error");
    }
    num.push(calculate(l_num, r_num, op.top()));
    op.pop();
}

double compute_expression(const string &expression) {
    stack<double> num;
    stack<char> op;

    for (const auto &ch: expression) {
        if (isdigit(ch))
            num.push(stod(to_string(ch - '0')));
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            op.push(ch);
        else if (ch == ')') {
            compute(num, op);
        }
    }

    while (!op.empty()) {
        compute(num, op);
    }
    return num.top();
}

