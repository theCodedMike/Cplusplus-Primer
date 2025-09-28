//
// Created by lixia on 2025/9/25.
//

#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <memory>

class Quote {
public:
    Quote() = default;
    Quote(std::string book, const double sales_price) :
        bookNo(std::move(book)), price(sales_price) {}
    Quote(const Quote &) = default; // 拷贝构造
    Quote(Quote &&) = default;      // 移动构造
    Quote & operator=(const Quote &) = default; // 拷贝赋值
    Quote & operator=(Quote &&) = default;      // 移动赋值
    virtual ~Quote() = default;

    [[nodiscard]] const std::string & isbn() const;
    [[nodiscard]] virtual double net_price(std::size_t) const; // 虚函数
    virtual void debug() const;
    [[nodiscard]] virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }

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

    [[nodiscard]] virtual double net_price(std::size_t) const = 0; // 纯虚函数，函数体必须在类外定义

    [[nodiscard]] std::pair<std::size_t, double> discount_policy() const {
        return std::make_pair(quantity, discount);
    }

protected:
    std::size_t quantity = 0; // 折扣适用的购买量
    double discount = 0.0; // 折扣
};






class Bulk_quote final: public Disc_quote { // Bulk_quote继承了Quote
public:
    Bulk_quote() = default;
    Bulk_quote(std::string book, const double price, const std::size_t qty, const double disc) :
        Disc_quote(std::move(book), price, qty, disc) {}
    //using Disc_quote::Disc_quote; // 继承Disc_quote的构造函数

    [[nodiscard]] double net_price(std::size_t) const override; // 可以重写，也可以继续声明为虚函数
    void debug() const override;

    [[nodiscard]] Bulk_quote* clone() const & override{
        return new Bulk_quote(*this);
    }
    Bulk_quote* clone() && override {
        return new Bulk_quote(std::move(*this));
    }
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




class Basket {
public:
    void add_item(const Quote &sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset保存多个报价，按照compare成员排序
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
inline double Basket::total_receipt(std::ostream & os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

#endif //QUOTE_H