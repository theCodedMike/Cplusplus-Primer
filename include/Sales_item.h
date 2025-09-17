//
// Created by lixia on 2025/8/14.
//

#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>


class Sales_item {
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend bool operator<(const Sales_item&, const Sales_item&);
    friend bool operator==(const Sales_item&, const Sales_item&);

public:
    // 构造函数
    Sales_item() = default;
    Sales_item(const std::string &book): bookNo(book) {}
    Sales_item(std::istream &is) { is >> *this; }

    Sales_item& operator+=(const Sales_item&);
    std::string isbn() const { return bookNo; }
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


inline bool compareIsbn(const Sales_item& lhs, const Sales_item& rhs) {
    return lhs.isbn() == rhs.isbn();
}

Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool operator==(const Sales_item& lhs, const Sales_item& rhs) {
    return lhs.units_sold == rhs.units_sold &&
        lhs.revenue == rhs.revenue &&
            lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item& lhs, const Sales_item& rhs) {
    return !(lhs == rhs);
}

Sales_item& Sales_item::operator+=(const Sales_item& rhs) {
    if (isbn() != rhs.isbn())
        bookNo = rhs.bookNo;
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}

std::istream& operator>>(std::istream& in, Sales_item& s) {
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    if (in) // check that inputs succeeded
        s.revenue = s.units_sold * price;
    else
        s = Sales_item(); // input failed: reset object to default state
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_item& s) {
    out << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

#endif //SALES_ITEM_H