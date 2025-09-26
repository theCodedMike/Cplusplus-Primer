//
// Created by lixia on 2025/9/26.
//
#include <iostream>
#include "../include/Quote.h"

using namespace std;


int main(int argc, char *argv[]) {
    const Quote base("ISBN-911", 5.99);
    base.debug();
    cout << endl;

    const Bulk_quote derived("ISBN-912", 9.99, 5, 0.2);
    derived.debug();
}
