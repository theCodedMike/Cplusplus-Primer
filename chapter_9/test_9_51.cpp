//
// Created by lixia on 2025/9/8.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class MyDate {
    unsigned int year = 0;
    unsigned int month = 0;
    unsigned int day = 0;

public:
    MyDate() = default;
    MyDate(const unsigned int year, const unsigned int month, const unsigned int day)
        : year(year), month(month), day(day) {}
    explicit MyDate(const string &s_date);

    [[nodiscard]] unsigned _year() const {return year;}
    [[nodiscard]] unsigned _month() const {return month;}
    [[nodiscard]] unsigned _day() const {return day;}
};

const string DateDelimiter = "/- ";

// 目前只能解析纯数字的日期
MyDate::MyDate(const string &s_date) {
    vector<string> parts;
    stringstream sin(s_date);
    string part;

    // 使用 '/' 或 '-' 或 ' ' 作为分隔符
    if (s_date.find('/') != string::npos) {
        while (getline(sin, part, '/')) {
            parts.push_back(part);
        }
    } else if (s_date.find('-') != string::npos) {
        while (getline(sin, part, '-')) {
            parts.push_back(part);
        }
    } else if (s_date.find(' ') != string::npos) {
        while (getline(sin, part, ' ')) {
            parts.push_back(part);
        }
    }

    if (parts.size() != 3) {
        throw invalid_argument("Invalid date format");
    }

    year = stoi(parts[0]);
    month = stoi(parts[1]);
    day = stoi(parts[2]);
}


ostream & operator<<(ostream &os, const MyDate &date) {
    os << date._year() << '-' << date._month() << '-' << date._day();
    return os;
}


int main(int argc, char *argv[]) {
    const MyDate date("2025/09/08");
    cout << date << endl; // 2025-9-8
}
