//
// Created by lixia on 2025/9/16.
//

#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

const size_t N = 20;  //理论上这个值应该足够大

int main(int argc, char *argv[]) {
    allocator<string> al;
    const auto beginner = al.allocate(N);
    string word;

    cout << "Enter some words, 'quit' to quit:" << endl;
    auto p = beginner;
    for (int i = 0; i < N; ++i, ++p) {
        cin >> word;
        if (word == "quit") {
            break;
        }

        allocator_traits<decltype(al)>::construct(al, p, word);
    }

    ranges::for_each(beginner, p, [](const string &s) {
        cout << s << endl;
    });

    while (p-- != beginner) {
        allocator_traits<decltype(al)>::destroy(al, p);
    }
    al.deallocate(beginner, N);
}
