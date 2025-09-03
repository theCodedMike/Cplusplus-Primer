//
// Created by lixia on 2025/8/18.
//

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

class Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
public:
    Sales_data() = default;
    //Sales_data() : Sales_data("", 0, 0) {} // 委托构造函数
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}
    explicit Sales_data(std::istream &); // explicit可以避免隐式类类型转换

    // 既声明也定义，也是内联函数
    std::string isbn() const {
        return bookNo; // 等价于 this->bookNo;
    }
    // 只声明，没有定义
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

// friend
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream & print(std::ostream &, const Sales_data &);
    friend std::istream & read(std::istream &, Sales_data &);

};

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

inline Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


Sales_data add(const Sales_data &, const Sales_data &);
std::ostream & print(std::ostream &, const Sales_data &);
std::istream & read(std::istream &, Sales_data &);

inline Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

inline std::istream & read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

inline std::ostream & print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}
#endif //SALES_DATA_H