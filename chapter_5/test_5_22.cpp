//
// Created by lixia on 2025/8/26.
//
#include <iostream>
using namespace std;

int get_size();


int main(int argc, char *argv[]) {
    int sz;
    do {
        sz = get_size();
        cout << sz << endl;
    } while (sz <= 0);
}


int get_size() {
    cout << "Enter a number: ";
    int size;
    cin >> size;
    return size;
}
