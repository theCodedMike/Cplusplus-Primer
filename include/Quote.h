//
// Created by lixia on 2025/9/25.
//

#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>
#include <utility>

class Quote {
public:
    Quote() = default;
    Quote(std::string book, const double sales_price) :
        bookNo(std::move(book)), price(sales_price) {}
    virtual ~Quote() = default;

    [[nodiscard]] const std::string & isbn() const;
    [[nodiscard]] virtual double net_price(std::size_t) const; // 虚函数
    virtual void debug() const;

private:
    std::string bookNo; // 书籍的ISBN编号

protected:
    double price = 0.0; // 普通状态下不打折的价格
};

inline const std::string & Quote::isbn() const {
    return bookNo;
}

inline double Quote::net_price(const std::size_t cnt) const {
    return cnt * price;
}

inline void Quote::debug() const {
    std::cout << "bookNo: " << bookNo << std::endl;
    std::cout << "price: " << price << std::endl;
}





class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(std::string book, const double price, const std::size_t qty, const double disc) :
        Quote(std::move(book), price), quantity(qty), discount(disc) { }

    [[nodiscard]] double net_price(std::size_t) const = 0; // 纯虚函数，函数体必须在类外定义
protected:
    std::size_t quantity = 0; // 折扣适用的购买量
    double discount = 0.0; // 折扣
};






class Bulk_quote final: public Disc_quote { // Bulk_quote继承了Quote
public:
    Bulk_quote() = default;
    Bulk_quote(std::string book, const double price, const std::size_t qty, const double disc) :
        Disc_quote(std::move(book), price, qty, disc) {}

    [[nodiscard]] double net_price(std::size_t) const override; // 可以重写，也可以继续声明为虚函数
    void debug() const override;
};

inline double Bulk_quote::net_price(const std::size_t cnt) const {
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;

    return cnt * price;
}

inline void Bulk_quote::debug() const {
    Quote::debug();
    std::cout << "min_qty: " << quantity << std::endl;
    std::cout << "discount: " << discount << std::endl;
}










inline double print_total(std::ostream &os, const Quote &item, const std::size_t n) {
    const double ret = item.net_price(n); // 动态绑定 运行时绑定
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
#endif //QUOTE_H