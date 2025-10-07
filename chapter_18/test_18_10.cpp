//
// Created by lixia on 2025/10/7.
//
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
const T & use_try_catch(const vector<T> &vec, size_t idx) {
    try {
        return vec.at(idx);
    } catch (const exception &e) {
        cout << e.what() << endl;
        return vec[0];
    } catch (...) {
        cout << "unknown exception" << endl;
        return 0;
    }
}

template <typename T>
const T & without_try_catch(const vector<T> &vec, size_t idx) {
    return vec.at(idx);
}

int main(int argc, char *argv[]) {
    const vector nums = {1, 2, 3, 4, 5};

    //cout << use_try_catch(nums, 5) << endl;
    cout << without_try_catch(nums, 5) << endl;
}