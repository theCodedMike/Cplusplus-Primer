//
// Created by lixia on 2025/9/7.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> v;

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
        cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    }
}
// size: 1, capacity: 1
// size: 2, capacity: 2
// size: 3, capacity: 4
// size: 4, capacity: 4
// size: 5, capacity: 8
// size: 6, capacity: 8
// size: 7, capacity: 8
// size: 8, capacity: 8
// size: 9, capacity: 16
// size: 10, capacity: 16
// size: 11, capacity: 16
// size: 12, capacity: 16
// size: 13, capacity: 16
// size: 14, capacity: 16
// size: 15, capacity: 16
// size: 16, capacity: 16
// size: 17, capacity: 32
// size: 18, capacity: 32
// size: 19, capacity: 32
// size: 20, capacity: 32
// size: 21, capacity: 32
// size: 22, capacity: 32
// size: 23, capacity: 32
// size: 24, capacity: 32
// size: 25, capacity: 32
// size: 26, capacity: 32
// size: 27, capacity: 32
// size: 28, capacity: 32
// size: 29, capacity: 32
// size: 30, capacity: 32
// size: 31, capacity: 32
// size: 32, capacity: 32
// size: 33, capacity: 64
// size: 34, capacity: 64
// size: 35, capacity: 64
// size: 36, capacity: 64
// size: 37, capacity: 64
// size: 38, capacity: 64
// size: 39, capacity: 64
// size: 40, capacity: 64
// size: 41, capacity: 64
// size: 42, capacity: 64
// size: 43, capacity: 64
// size: 44, capacity: 64
// size: 45, capacity: 64
// size: 46, capacity: 64
// size: 47, capacity: 64
// size: 48, capacity: 64
// size: 49, capacity: 64
// size: 50, capacity: 64
// size: 51, capacity: 64
// size: 52, capacity: 64
// size: 53, capacity: 64
// size: 54, capacity: 64
// size: 55, capacity: 64
// size: 56, capacity: 64
// size: 57, capacity: 64
// size: 58, capacity: 64
// size: 59, capacity: 64
// size: 60, capacity: 64
// size: 61, capacity: 64
// size: 62, capacity: 64
// size: 63, capacity: 64
// size: 64, capacity: 64
// size: 65, capacity: 128
// size: 66, capacity: 128
// size: 67, capacity: 128
// size: 68, capacity: 128
// size: 69, capacity: 128
// size: 70, capacity: 128
// size: 71, capacity: 128
// size: 72, capacity: 128
// size: 73, capacity: 128
// size: 74, capacity: 128
// size: 75, capacity: 128
// size: 76, capacity: 128
// size: 77, capacity: 128
// size: 78, capacity: 128
// size: 79, capacity: 128
// size: 80, capacity: 128
// size: 81, capacity: 128
// size: 82, capacity: 128
// size: 83, capacity: 128
// size: 84, capacity: 128
// size: 85, capacity: 128
// size: 86, capacity: 128
// size: 87, capacity: 128
// size: 88, capacity: 128
// size: 89, capacity: 128
// size: 90, capacity: 128
// size: 91, capacity: 128
// size: 92, capacity: 128
// size: 93, capacity: 128
// size: 94, capacity: 128
// size: 95, capacity: 128
// size: 96, capacity: 128
// size: 97, capacity: 128
// size: 98, capacity: 128
// size: 99, capacity: 128
// size: 100, capacity: 128