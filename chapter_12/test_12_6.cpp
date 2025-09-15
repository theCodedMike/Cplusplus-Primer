//
// Created by lixia on 2025/9/15.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> * factory();
void input(vector<int> *);
void print(const vector<int> *);


int main(int argc, char *argv[]) {
    auto pv = factory();
    input(pv);
    print(pv);
    delete pv;
    pv = nullptr;
}

vector<int> * factory() {
    return new vector<int>();
}

void input(vector<int> * v) {
    cout << "Enter some integers('q' to quit):" << endl;
    int val;

    while (cin >> val)
        v->push_back(val);
}

void print(const vector<int> * v) {
    for (const int & num: *v) {
        cout << num << " ";
    }
    cout << endl;
}