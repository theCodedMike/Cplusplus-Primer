//
// Created by lixia on 2025/10/5.
//
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <numeric>
#include <random>
#include <regex>
#include <vector>

#include "../include/Sales_data.h"
#include "../include/Utils.h"

using namespace std;


void use_tuple();
void use_bitset();
void use_reg_exp();
void use_rand();
void revisit_io_lib();

int main(int argc, char *argv[]) {
    //use_tuple();
    //use_bitset();
    //use_reg_exp();
    //use_rand();
    revisit_io_lib();
}

void use_tuple() {
    // 定义和初始化
    tuple<size_t, string, int> t1;
    tuple<size_t, string, int> t2 = {5, "C++", 2025};
    tuple<size_t, string, int> t3(5, "C++", 2025);
    auto t4 = make_tuple(5, "C++", 2025);
    print_tuple(t1);
    print_tuple(t2);
    print_tuple(t3);
    print_tuple(t4);


    // 遍历
    constexpr auto len = tuple_size_v<decltype(t4)>;
    cout << "tuple size: " << len << endl; // 3
    /*
    // 不能这么遍历，因为get<i>的i是编译时常量，不能在运行时动态获取
    for (auto i = 0; i < len; ++i)
        cout << get<i>(t4) << endl;
    */
    cout << std::get<0>(t4) << " " << std::get<1>(t4) << " " << std::get<2>(t4) << endl;
    std::get<2>(t4) += 1;
    print_tuple(t4); // [5, C++, 2026]

    // 比较
    cout << "t1 == t2: " << (t1 == t2) << endl; // 0
    cout << "t2 == t3: " << (t2 == t3) << endl; // 1
    cout << "t3 < t4: " << (t3 < t4) << endl; // 1

    //unordered_map<decltype(t3), int> umap; //
    map<decltype(t3), int> map;
    map[t3] = 5;
    map[t3] = 10;
    cout << "map[t3]: " << map[t3] << endl; // 10
}

typedef tuple<
    vector<Sales_data>::size_type,
    vector<Sales_data>::const_iterator,
    vector<Sales_data>::const_iterator
> matches;

vector<matches> find_book(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;

    for (auto iter = files.cbegin(); iter != files.cend(); ++iter) {
        auto [fst, snd] =
            std::equal_range(iter->cbegin(), iter->cend(), book, compare_isbn);
        if (fst != snd)
            ret.emplace_back(iter - files.cbegin(), fst, snd);
    }

    return ret;
}

void report_results(istream &in, ostream &os, const vector<vector<Sales_data>> &files) {
    string s; // 要查找的书
    while (in >> s) {
        auto trans = find_book(files, s);
        if (trans.empty()) {
            cout << s << " not found in any stores" << endl;
            continue;
        }

        for (const auto &store: trans) {
            os << "store " << get<0>(store) << " sales: "
               << accumulate(get<1>(store), get<2>(store), Sales_data(s))
               << endl;
        }
    }
}


void use_bitset() {
    constexpr bitset<32> bitvec(1U); // 32位，低位为1，其他位为0
    cout << bitvec[0] << endl; // 1
    cout << bitvec[31] << endl;// 0
                            // 高位                         低位
    cout << bitvec << endl; // 00000000000000000000000000000001
    constexpr bitset<32> bitvec1(2); cout << bitvec1 << endl; // 00000000000000000000000000000010
    constexpr bitset<32> bitvec2(3); cout << bitvec2 << endl; // 00000000000000000000000000000011
    constexpr bitset<32> bitvec3(4); cout << bitvec3 << endl; // 00000000000000000000000000000100
    constexpr bitset<32> bitvec4(5); cout << bitvec4 << endl; // 00000000000000000000000000000101
    cout << endl;

    string str("1111111000000011001101"); // 在pos范围内不能出现除0/1之外的字符，否则会抛出异常
    bitset<32> bitvec5(str, 5, 4); cout << bitvec5 << endl; // 00000000000000000000000000001100
    bitset<32> bitset6(str, str.size() - 4); cout << bitset6 << endl; // 00000000000000000000000000001101
    string str2 = "2023";
    //bitset<32> bitset7(str2); cout << bitset7 << endl; // std::invalid_argument
    cout << endl;

    cout << bitvec3.any() << endl; // 1
    cout << bitvec3.all() << endl; // 0
    cout << bitvec3.none() << endl; // 0
    cout << bitvec3.count() << endl; // 1
    cout << bitvec3.size() << endl; // 32
    cout << bitvec3.test(0) << endl; // 0
    cout << bitvec3._Find_first() << endl; // 2
    cout << ~bitvec3 << endl; // 11111111111111111111111111111011
    bitset<8> bitvec7;
    cin >> bitvec7;
    cout << bitvec7 << endl;
}
void identify_file() {
    regex reg("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); // xxx.cpp/cxx/cc
    smatch results;
    string filename;

    while (cin >> filename) {
        if (filename == "quit")
            break;
        if (regex_search(filename, results, reg))
            cout << results.str() << endl;
    }
}
void identify_word() {
    string pattern("[^c]ei"); // 查找不在字符c之后的字符串ei
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    const string test_str = "receipt freind theif receive";
    try {
        const regex reg(pattern); // 构造一个用于查找模式的regex

        if (smatch results; regex_search(test_str, results, reg)) // 寻找第一个匹配的子序列
            cout << results.str() << endl; // 打印匹配的单词 freind
    } catch (regex_error &e) {
        cout << e.what() << ", code: " << e.code() << endl;
    }
}
void reg_iterator() {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    const string test_str = "receipt freind theif receive";

    for (sregex_iterator iter(test_str.begin(), test_str.end(), r), end_iter; iter != end_iter; ++iter)
        cout << iter->str() << " "; // freind theif
}
void sub_expr() {
    const regex reg("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase); // xxx.cpp/cxx/cc  由2个子表达式组成
    smatch results;
    const string filename = "main.cpp";

    if (regex_search(filename.cbegin(), filename.cend(), results, reg)) {
        cout << results.size() << endl; // 3
        cout << results.str(0) << endl; // main.cpp
        cout << results.str(1) << endl; // main
        cout << results[2] << endl; // cpp
    }
}
void reg_replace() {
    const string phone_pattern = "((\\()?(\\d{3}) (\\))?([-. ])?(\\d{3}) ([-. ])?(\\d{4}))";
    const regex r(phone_pattern);
    const string phone_num = "(908) 555-1800";
    const string fmt = "$2.$5.$7";
    cout << regex_replace(phone_num, r, fmt) << endl; // 没起作用???
}
void use_reg_exp() {
    //identify_word();
    //identify_file();
    //reg_iterator();
    sub_expr();
    //reg_replace();
}
vector<unsigned> gen_rand_ivec(const size_t size) {
    static default_random_engine e; // static是必须的，不然每次生成的都是一样的
    static uniform_int_distribution<unsigned> u(0, 9);
    //cout << e.min() << " " << e.max() << endl; // 1 2147483646
    vector<unsigned> ret;

    for (size_t i = 0; i < size; ++i)
        ret.push_back(u(e));
    return ret;
}
vector<double> gen_rand_fvec(const size_t size) {
    static default_random_engine e; // static是必须的，不然每次生成的都是一样的
    static uniform_real_distribution<> u(1, 2);
    //cout << u.min() << " " << u.max() << endl; // 1 2
    vector<double> ret;

    for (size_t i = 0; i < size; ++i)
        ret.push_back(u(e));
    return ret;
}
void gen_normal_distribution() {
    default_random_engine e;
    normal_distribution<> n(4, 1.5); // 均值为4，标准差为1.5
    vector<unsigned> vals(9); // 9个元素都为0
    for (size_t i = 0; i != 200; ++i) {
        if (const unsigned v = lround(n(e)); v < vals.size())
            ++vals[v];
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;
}
void gen_bernoulli_distribution() {
    string resp;
    default_random_engine e;
    bernoulli_distribution b; // 默认是50/50的机会
    //bernoulli_distribution b(0.55); // 55/45的机会
    do {
        const bool first = b(e);
        cout << (first ? "We go first" : "You get to go first") << endl;
        // play...
        cout << "play again? Enter 'yes' or 'no'" << endl;

    } while (cin >> resp && resp[0] == 'y');
}
void use_rand() {
    /*
    const auto vec1 = gen_rand_ivec(20);
    print_collection(vec1);
    const auto vec2 = gen_rand_ivec(20);
    print_collection(vec2);
    const auto vec3 = gen_rand_fvec(10);
    print_collection(vec3);
    */

    //gen_normal_distribution();
    gen_bernoulli_distribution();
}

void formatted_io() {
    // 操作符
    cout << "default bool values: " << true << " " << false << endl; // 1 0
    cout << "  alpha bool values: " << boolalpha << true << " " << false << endl; // true false

    cout << "default: " << 20 << " " << 1024 << endl; // 20 1024
    cout << "  octal: " << oct << 20 << " " << 1024 << endl; // 24 2000
    cout << "    hex: " << hex << 20 << " " << 1024 << endl; // 14 400
    cout << "decimal: " << dec << 20 << " " << 1024 << endl; // 20 1024

    cout << showbase; // uppercase可以改变16进制的大小写
    cout << "default: " << 20 << " " << 1024 << endl; // 20 1024
    cout << "  octal: " << oct << 20 << " " << 1024 << endl; // 024 02000
    cout << "    hex: " << hex << 20 << " " << 1024 << endl; // 0x14 0x400
    cout << "decimal: " << dec << 20 << " " << 1024 << endl; // 20 1024
    cout << noshowbase;


    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl; // 6  1.41421
    cout.precision(12); // cout << setprecision(12);
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl; // 12 1.41421356237

    const double fval = 100 * sqrt(2.0);
    cout << "default format: " << fval << endl // 141.421356237
         << "scientific: " << scientific << fval << endl // 1.414213562373e+02
         << "fixed: " << fixed << fval << endl // 141.421356237310
         << "hexa: " << hexfloat << fval << endl // 0x1.1ad7bc01366b8p+7
         << "defaults: " << defaultfloat << fval << endl; // 141.421356237
}
void unformatted_io() {}

int random_access_stream() {
    fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }

    const auto end_mark = inOut.tellg(); // 记住原文件尾位置
    inOut.seekg(0, fstream::beg); // 重定位到文件开始
    size_t cnt = 0; // 字节数累加器
    string line; // 保存输入中的每行
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
        cnt += line.size() + 1; // 加1表示换行符
        auto mark = inOut.tellg(); // 记住读取位置
        inOut.seekp(0, fstream::end); // 将写标记移动到文件尾
        inOut << cnt; // 输出累计的长度
        // 如果不是最后一行，打印一个分隔符
        if (mark != end_mark)
            inOut << " ";
        inOut.seekg(mark); // 恢复读位置
    }
    inOut.seekp(0, fstream::end); // 定位到文件尾
    inOut << "\n";
    return 0;
}
void revisit_io_lib() {
    formatted_io();
    //unformatted_io();
    //random_access_stream();
}