//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <map>

using namespace std;


int main(int argc, char *argv[]) {
    multimap<string, string> authors = {
        {"Lu Xun", "1st book"},
        {"Lu Xun", "2nd book"},
        {"Lu Xun", "3rd book"},
        {"Cao Xueqin", "The Red Building"},
        {"Lao She", "Xiang Zi"},
        {"Lao She", "Nothing"}
    };

    string author_name = "Lu Xun";
    while (true) {
        auto iter = authors.find(author_name);
        if (iter == authors.cend())
            break;

        authors.erase(iter);
    }

    for (const auto &[author, book] : authors) {
        cout << author << ": " << book << endl;
    }
}