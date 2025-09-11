//
// Created by lixia on 2025/9/11.
//
#include <vector>
#include <list>
#include "../include/Utils.h"

using namespace std;

list<int> copy_reverse_range_1(const vector<int> &v, vector<int>::size_type, vector<int>::size_type);
list<int> copy_reverse_range_2(const vector<int> &v, vector<int>::size_type, vector<int>::size_type);

int main(int argc, char *argv[]) {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const auto lst1 = copy_reverse_range_1(v, 3, 7);
    print_collection(lst1); // [7, 6, 5, 4, 3]

    const auto lst2 = copy_reverse_range_2(v, 3, 7);
    print_collection(lst2); // [7, 6, 5, 4, 3]
}

list<int> copy_reverse_range_1(const vector<int> &v, const vector<int>::size_type begin, const vector<int>::size_type end) {
    if (begin < 1 || end > v.size() || begin > end)
        throw invalid_argument("Invalid range");

    const auto iter_beg = v.cbegin() + begin - 1;
    const auto iter_end = v.cbegin() + end;

    list<int> lst;
    std::copy(iter_beg, iter_end, std::front_inserter(lst));
    return lst;
}

list<int> copy_reverse_range_2(const vector<int> &v, const vector<int>::size_type begin, const vector<int>::size_type end) {
    if (begin < 1 || end > v.size() || begin > end)
        throw invalid_argument("Invalid range");

    auto iter_beg = v.crbegin() + (v.size() - end);
    auto iter_end = v.crbegin() + (v.size() - begin + 1);

    list<int> lst(iter_beg, iter_end);
    return lst;
}