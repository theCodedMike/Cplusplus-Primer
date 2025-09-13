//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void word_count_program();
void word_transform_program();

int main(int argc, char *argv[]) {
    //word_count_program();
    word_transform_program();
}

void word_count_program() {
    const vector<string> words = {"hello", "world", "love", "miss", "you", "hello", "you", "love", "bad"};
    unordered_map<string, unsigned> word_counter;

    for (auto word: words) {
        ++word_counter[word];
    }

    for (const auto & [key, cnt]: word_counter) {
        cout << key << " occurs " << cnt << (cnt > 1 ? " times" : " time") << endl;
    }
}


unordered_map<string, string> build_map(ifstream &fin_rule) {
    unordered_map<string, string> rule_map;
    string key;
    string line;

    while ( fin_rule >> key && getline(fin_rule, line)) {
        if (key.empty())
            continue;

        if (line.empty())
            throw runtime_error("no rule for " + key);

        rule_map[key] = line.substr(1);
    }

    return rule_map;
}

const string & transform(const string &key, const unordered_map<string, string> &map) {
    if (map.contains(key)) {
        return map.at(key);
    }

    return key;
}

void word_transform(ifstream &fin_rule, ifstream &fin_text) {
    const auto rule_map = build_map(fin_rule);

    string line, word;
    istringstream sin;
    while (getline(fin_text, line)) {
        sin.str(line);

        bool first_word = true;
        while (sin >> word) {
            if (first_word)
                first_word = false;
            else
                cout << " ";

            cout << transform(word, rule_map);
        }
        cout << endl;
        sin.clear();
    }
}

void word_transform_program() {
    const string rule_path = "./listing_rules.txt";
    ifstream fin_rule(rule_path);
    if (!fin_rule.is_open())
        throw runtime_error("cannot open file " + rule_path);

    const string text_path = "./listing_text.txt";
    ifstream fin_text(text_path);
    if (!fin_text.is_open())
        throw runtime_error("cannot open file " + text_path);

    word_transform(fin_rule, fin_text);
}