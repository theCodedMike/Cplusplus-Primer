//
// Created by lixia on 2025/9/3.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
    static double interest_rate;
    static constexpr int period = 30;

    static double init_interest_rate();

    std::string owner;
    double amount = 0;
    //double daily_tbl[period];
public:
    Account() = default;
    explicit Account(const std::string &owner, const double amount = 0) :
        owner(owner), amount(amount) {}

    void calculate() { amount += amount * interest_rate; }

    static double rate() {
        return interest_rate;
    }
    static void rate(double);
};


// 定义并初始化一个静态成员
double Account::interest_rate = init_interest_rate();
inline double Account::init_interest_rate() {
    return 0.05;
}


inline void Account::rate(double r) {
    interest_rate = r;
}


#endif //ACCOUNT_H