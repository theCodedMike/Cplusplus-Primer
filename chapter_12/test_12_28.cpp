//
// Created by lixia on 2025/9/16.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

pair<map<string, pair<size_t, set<size_t>>>, vector<string>> handle_text(const string &);
void query(const map<string, pair<size_t, set<size_t>>> &, const vector<string> &);

int main(int argc, char *argv[]) {
    const string text_path = "./Youth.txt";

    auto [data, text] = handle_text(text_path);

    query(data, text);
}

// 这里只是简单地去掉了标点符号
void trim(string &word) {
    auto end = word.end();
    const auto beg = word.begin();
    while (end != beg) {
        --end;
        if (ispunct(*end))
            break;
    }
    if (end != beg)
        word.erase(end);
}

void to_lower(string &word) {
    ranges::transform(word, word.begin(), ::tolower);
}

pair<map<string, pair<size_t, set<size_t>>>, vector<string>> handle_text(const string &text_path) {
    map<string, pair<size_t, set<size_t>>> data;
    vector<string> text;

    ifstream fin(text_path);
    if (!fin.is_open())
        throw runtime_error("can't open file " + text_path);

    string line, word;
    size_t line_num = 0;
    istringstream sin;
    while (getline(fin, line)) {
        text.push_back(line);

        if (line.empty()) {
            ++line_num;
            continue;
        }

        sin.str(line);
        while (sin >> word) {
            trim(word);
            if (word.empty())
                continue;

            to_lower(word);
            if (data.contains(word)) {
                auto &[total_occurs, occur_lines] = data[word];
                ++total_occurs;
                occur_lines.insert(line_num);
            } else {
                data[word] = make_pair(1, set<size_t>{line_num});
            }
        }

        sin.clear();
        ++line_num;
    }

    fin.close();
    return make_pair(data, text);
}

void query(const map<string, pair<size_t, set<size_t>>> &data, const vector<string> &text) {
    string word;

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        cin >> word;
        if (word == "q")
            break;

        to_lower(word);
        if (!data.contains(word)) {
            cout << "Sorry, we don't find '" + word + "', try again..." << endl;
            continue;
        }

        //auto [total_occurs, occurs_line_numbers] = data[word]; // 不知道为什么报错
        const auto total_occurs = data.at(word).first;
        auto & occurs_line_numbers = data.at(word).second;

        cout << word << " occurs " << total_occurs << " times" << endl;
        for (const auto line_num : occurs_line_numbers) {
            cout << "\t(line " << line_num + 1 << ") " << text[line_num] << endl;
        }
        cout << endl << endl;
    }
}