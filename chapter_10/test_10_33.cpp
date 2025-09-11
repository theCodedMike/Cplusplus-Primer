//
// Created by lixia on 2025/9/11.
//

#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
using namespace std;

void handle_nums(const string &, const string &, const string &);

int main(int argc, char *argv[]) {
    const string in_file = "./test_10_33.txt";
    const string out_file_odd = "./test_10_33_odd.txt";
    const string out_file_even = "./test_10_33_even.txt";

    handle_nums(in_file, out_file_odd, out_file_even);
}

void handle_nums(const string &in_file, const string &out_file_odd, const string &out_file_even) {
    // 从输入文件中读取数据
    ifstream fin(in_file);
    if (!fin.is_open())
        throw runtime_error("can't open " + in_file);
    istream_iterator<string> in_iter(fin), eof;

    // 打开输出奇数文件
    ofstream fout_odd(out_file_odd, ios_base::app);
    if (!fout_odd.is_open())
        throw runtime_error("can't open " + out_file_odd);

    // 打开输出偶数文件
    ofstream fout_even(out_file_even, ios_base::app);
    if (!fout_even.is_open())
        throw runtime_error("can't open " + out_file_even);

    // 处理逻辑
    ostream_iterator<int> os_iter_odd(fout_odd, " ");
    ostream_iterator<int> os_iter_even(fout_even, "\n");
    while (in_iter != eof) {
        int num = stoi(*in_iter);
        if (num % 2 == 1)
            *os_iter_odd = num;
        else
            *os_iter_even = num;

        ++in_iter;
    }
}