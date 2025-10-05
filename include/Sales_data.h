//
// Created by lixia on 2025/8/18.
//

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <utility>

class Sales_data {
    // friend
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream & print(std::ostream &, const Sales_data &);
    friend std::istream & read(std::istream &, Sales_data &);
    friend std::ostream & operator<<(std::ostream &os, const Sales_data &rhs);
    friend std::istream & operator>>(std::istream &is, Sales_data &rhs);
    friend struct std::hash<Sales_data>;

public:
    Sales_data() = default;
    //Sales_data() : Sales_data("", 0, 0) {} // 委托构造函数
    explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
    Sales_data(std::string s, const unsigned n, const double p)
        : bookNo(std::move(s)), units_sold(n), revenue(p * n) {}
    explicit Sales_data(std::istream &); // explicit可以避免隐式类类型转换
    Sales_data(const Sales_data &); // 拷贝构造函数
    Sales_data& operator=(const Sales_data&);// 拷贝赋值函数
    Sales_data& operator=(const std::string &s);
    ~Sales_data() = default; // 析构函数

    // 既声明也定义，也是内联函数
    [[nodiscard]] const std::string &isbn() const {
        return bookNo; // 等价于 this->bookNo;
    }
    // 只声明，没有定义
    Sales_data& combine(const Sales_data&);
    [[nodiscard]] double avg_price() const;

    Sales_data & operator+=(const Sales_data &rhs);
    bool operator==(const Sales_data &) const;
    bool operator!=(const Sales_data &) const;
    bool operator<(const Sales_data &) const;
    bool operator>(const Sales_data &) const;
    explicit operator const std::string &() const;
    explicit operator double() const;
    explicit operator bool() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline Sales_data::Sales_data(const Sales_data &orig) :
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue)
{}

inline Sales_data& Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

inline Sales_data& Sales_data::operator=(const std::string &s) {
    bookNo = s;
    return *this;
}

inline Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

inline Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    return combine(rhs);
}

inline bool Sales_data::operator==(const Sales_data & rhs) const {
    return units_sold == rhs.units_sold &&
           revenue == rhs.revenue &&
           bookNo == rhs.bookNo;
}

inline bool Sales_data::operator!=(const Sales_data & rhs) const {
    return !(*this == rhs);
}

inline bool Sales_data::operator<(const Sales_data & rhs) const {
    if (bookNo < rhs.bookNo)
        return true;
    if (bookNo == rhs.bookNo && units_sold < rhs.units_sold)
        return true;
    if (bookNo == rhs.bookNo && units_sold == rhs.units_sold && revenue < rhs.revenue)
        return true;
    return false;
}

inline bool Sales_data::operator>(const Sales_data & rhs) const {
    return rhs < *this;
}

inline Sales_data::operator double() const {
    return revenue;
}

inline Sales_data::operator const std::string &() const {
    return bookNo;
}

inline Sales_data::operator bool() const {
    return !bookNo.empty() && units_sold > 0 && revenue > 0;
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
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data(); // 输入失败，对象被赋予默认状态
    return is;
}

inline std::ostream & print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

inline Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

inline bool compare_isbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

inline size_t hasher(const Sales_data &sd) {
    return std::hash<std::string>()(sd.isbn());
}

inline bool eq_op(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

inline std::ostream & operator<<(std::ostream &os, const Sales_data &rhs) {
    return print(os, rhs);
}

inline std::istream & operator>>(std::istream &is, Sales_data &rhs) {
    return read(is, rhs);
}

inline Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    return add(lhs, rhs);
}

// 模板特例
namespace std {
    template <>
    struct hash<Sales_data> {
        using result_type = size_t;
        using argument_type = Sales_data;

        size_t operator()(const Sales_data& s) const noexcept;
    };

    inline size_t hash<Sales_data>::operator()(const Sales_data &s) const noexcept {
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}

#endif //SALES_DATA_H