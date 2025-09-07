//
// Created by lixia on 2025/9/7.
//

#include <iostream>
#include <string>
using namespace std;

auto new_name(const string &, const string &, const string &) -> string;


int main(int argc, char *argv[]) {
    const string name = "Bill";
    cout << "new name: " << new_name(name, "Mr.", "III") << endl;
}
auto new_name(const string &name, const string &prefix, const string &suffix) -> string {
    string new_name;

    new_name.insert(new_name.size(), prefix);
    new_name.insert(new_name.size(), " ");
    new_name.insert(new_name.size(), name);
    new_name.insert(new_name.size(), " ");
    new_name.insert(new_name.size(), suffix);

    return new_name;
}