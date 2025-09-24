//
// Created by lixia on 2025/9/24.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class StrSizeCmp {
public:
    explicit StrSizeCmp(const size_t sz) : size(sz) {}

    bool operator()(const string &s) const {
        return s.size() == size;
    }

    [[nodiscard]] size_t get_size() const {return size;}
private:
    size_t size = 0;
};

class WordsCounter {
public:
    WordsCounter() {
        for (int i = 1; i <= 11; ++i) {
            cmpers.emplace_back(StrSizeCmp(i), 0);
        }
    }

    void count(ifstream &fin) {
        if (!fin.is_open())
            throw runtime_error("cannot open file");

        string word;
        while (fin >> word) {
            for (auto& [cmper, count]: cmpers) {
                if (cmper(word)) {
                    ++count;
                    break;
                }
            }
        }
    }

    void print_result() {
        for (auto& [cmper, count]: cmpers) {
            if (count == 0)
                continue;

            cout << "words of size " << cmper.get_size() << ": " << count << endl;
        }
    }
private:
    vector<pair<StrSizeCmp, int>> cmpers;
};




int main(int argc, char *argv[]) {
    ifstream fin("./test_14_38.txt");
    WordsCounter counter;

    counter.count(fin);
    counter.print_result();
}
