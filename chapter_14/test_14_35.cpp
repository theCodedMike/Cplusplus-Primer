//
// Created by lixia on 2025/9/24.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class ReadString {
public:
    explicit ReadString(istream &is = cin) : is(is) {}

    string operator()() const {
        string input;
        getline(is, input);
        if (is)
            return input;
        return {};
    }
private:
    istream & is;
};


int main(int argc, char *argv[]) {
    const ReadString rs;
    const auto input = rs();
    cout << input << endl;

    cout << "Enter anything you want, 'quit' to quit" << endl;
    vector<string> lines;
    while (true) {
        const auto line = rs();
        if (line == "quit")
            break;
        lines.push_back(line);
    }

    std::ranges::for_each(lines, [](const auto &line) {
        cout << line << endl;
    });
}
