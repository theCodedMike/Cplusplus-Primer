//
// Created by lixia on 2025/9/28.
//

#include "../include/Quote.h"

using namespace std;


int main(int argc, char *argv[]) {
    Basket basket;

    const auto quote = Quote("ISBN-911", 10);
    basket.add_item(quote);
    basket.add_item(quote);
    basket.add_item(quote);
    const auto bulk_quote = Bulk_quote("ISBN-912", 15, 5, 0.2);
    basket.add_item(bulk_quote);
    basket.add_item(bulk_quote);
    basket.add_item(bulk_quote);
    basket.add_item(bulk_quote);

    basket.total_receipt(cout);

    // output:
    // ISBN: ISBN-911 # sold: 3 total due: 30
    // ISBN: ISBN-912 # sold: 4 total due: 60
    // Total Sale: 90
}
