//
// Created by lixia on 2025/9/28.
//
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "../include/Quote.h"

using namespace std;


int main(int argc, char *argv[]) {
    std::vector<shared_ptr<Quote> > quotes;
    quotes.push_back(make_shared<Quote>("ISBN-911", 5));
    quotes.push_back(make_shared<Quote>("ISBN-912", 10));
    quotes.push_back(make_shared<Quote>("ISBN-913", 15));

    constexpr std::size_t cnt = 10;
    const double total_net_price =
        std::accumulate(quotes.cbegin(), quotes.cend(), 0,[&](double total, const shared_ptr<Quote> &item) {
            total += item->net_price(cnt);
            return total;
        });

    cout << "total_net_price: " << total_net_price << endl; // 300
}