//
// Created by lixia on 2025/9/11.
//

#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (const int &n: ranges::reverse_view(v)) {
        cout << n << " ";
    }
    cout << endl;
    for (auto iter = v.crbegin(); iter != v.crend(); ++iter)
        cout << *iter << " ";
    cout << endl;
}
