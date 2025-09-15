//
// Created by lixia on 2025/9/15.
//

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

shared_ptr<vector<int>> factory();
void input(const shared_ptr<vector<int>>&);
void print(const shared_ptr<vector<int>>&);

int main(int argc, char *argv[]) {
    const auto spv = factory();
    input(spv);
    print(spv);
    cout << spv.use_count() << endl;
}


shared_ptr<vector<int>> factory() {
    return make_shared<vector<int>>();
}

void input(const shared_ptr<vector<int>>& spv) {
    cout << "Enter some integers('q' to quit):" << endl;
    int val;

    while (cin >> val)
        spv->push_back(val);
}

void print(const shared_ptr<vector<int>>& spv) {
    for (const int i : *spv)
        cout << i << " ";
    cout << endl;
}