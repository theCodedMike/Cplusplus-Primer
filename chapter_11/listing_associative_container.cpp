//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Sales_data.h"
#include "../include/Utils.h"
using namespace std;

void use_map();
void use_set();
void initialize();
void use_pair();
void operate_ass_container();
void traverse_ass_container();
void insert_elem();
void erase_elem();
void word_transform_program();
void word_transform(ifstream &, ifstream &);
map<string, string> build_map(ifstream &);
const string & transform(const string &, const map<string, string> &);

int main(int argc, char *argv[]) {
    //use_map();
    //use_set();
    //initialize();
    //use_pair();
    //operate_ass_container();
    //traverse_ass_container();
    //insert_elem();
    //erase_elem();
    word_transform_program();
}

void use_map() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        if (word == "quit")
            break;
        ++word_count[word];
    }

    for (const auto &[fst, snd]: word_count) {
        cout << fst << " occurs " << snd << (snd > 1 ? " times" : " time") << endl;
    }
}

void use_set() {
    map<string, size_t> word_count;
    const set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word) {
        if (word == "quit")
            break;
        if (!exclude.contains(word))
            ++word_count[word];
    }

    for (const auto &[fst, snd]: word_count) {
        cout << fst << " occurs " << snd << ((snd > 1) ? " times" : " time") << endl;
    }
}

void initialize() {
    const map<string, string> authors = {
        {"Joyce", "James"},
        {"Austen", "Jane"},
        {"Dickens", "Charles"}
    };

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl; // 20
    cout << iset.size() << endl; // 10
    cout << miset.size() << endl; // 20

    // 严格弱序
    multiset<Sales_data, decltype(compare_isbn) *> bookstore(compare_isbn);
}

void use_pair() {
    pair<string, string> anon;
    pair<string, string> author("Hello", "Json");
    pair<string, string> author2{"Tom", "Jack"};
    pair<string, string> author3 = {"Lee", "Zhang"};
}

void operate_ass_container() {
    set<string>::key_type v2; // v2是一个string
    set<string>::value_type v1; // v1是一个string

    map<string, int>::value_type v3; // v3是一个pair<const string, int>
    map<string, int>::key_type v4; // v4是一个string
    map<string, int>::mapped_type v5; // v5是一个int
}

void traverse_ass_container() {
    map<string, int> map_data = {
        {"first", 1},
        {"second", 2},
        {"third", 3},
        {"fourth", 4}
    };

    auto map_iter = map_data.cbegin();
    while (map_iter != map_data.cend()) {
        cout << map_iter->first << " " << map_iter->second << endl;
        ++map_iter;
    }

    set<int> iset = {0, 1, 2, 3, 4, 5};
    auto set_iter = iset.cbegin();
    while (set_iter != iset.cend()) {
        cout << *set_iter << " ";
        ++set_iter;
    }
    cout << endl;
}

void insert_elem() {
    vector<int> ivec = {2, 4, 5, 8, 2, 4, 6, 8};
    set<int> set1;
    set1.insert(ivec.cbegin(), ivec.cend());
    set1.insert({1, 3, 5, 7, 1, 3, 5, 7});
    print_collection(set1); // [1, 2, 3, 4, 5, 6, 7, 8]

    map<string, int> map_data;
    map_data.insert({"hello", 1});
    map_data.insert(make_pair("world", 2));
    map_data.insert(pair<string, int>("json", 3));
    map_data.insert(map<string, int>::value_type("toml", 4));
    if (auto [target_iter, is_success] = map_data.insert({"hello", 5}); !is_success) {
        cout << "insert failed" << endl;
        target_iter->second = 5;
    }

    multimap<string, string> authors;
    authors.insert({"Lu Xun", "1st order"});
    authors.insert({"Lu Xun", "2nd dinner"});
    authors.insert({"Lu Xun", "3rd water"});
}

void erase_elem() {
    multimap<string, int> person = {
        {"Mike", 22},
        {"Tom", 25},
        {"Mike", 25},
        {"Mike", 30},
    };
    size_t erase_count = person.erase("Aron");
    cout << erase_count << endl; // 0
    erase_count = person.erase("Mike");
    cout << erase_count << endl; // 3
}

void find_elem() {
    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = iset.find(1); // 返回一个迭代器，指向key == 1的元素
    iter = iset.find(11);     // 返回iset.end()
    auto cot = iset.count(1); // 返回1
    cot = iset.count(11);          // 返回0
}

void word_transform_program() {
    ifstream map_file("./listing_rules.txt");
    ifstream input("./listing_text.txt");
    word_transform(map_file, input);
}
void word_transform(ifstream &map_file, ifstream &input) {
    const auto trans_map = build_map(map_file);
    string text;

    while (getline(input, text)) {
        istringstream sin(text);
        string word;
        bool first_word = true;

        while (sin >> word) {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }

        cout << endl;
    }
}

map<string, string> build_map(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &m) {
    if (const auto map_iter = m.find(s); map_iter != m.cend())
        return map_iter->second;

    return s;
}