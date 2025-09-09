//
// Created by lixia on 2025/9/9.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    vector<double> v = {3.2, -9, 18.2, 11.9, -10.1, 5.5};
    const double sum = std::accumulate(v.cbegin(), v.cend(), 0.0); // 0会被识别成int，会损失精度
    cout << "Sum of vector elements: " << sum << endl;
}
