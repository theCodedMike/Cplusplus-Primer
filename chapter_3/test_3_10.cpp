//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main(int argc, char *argv[]) {
    string input;
    getline(cin, input);
    cout << "Before cut: " << input << endl;

    int r = 0;
    for (unsigned size = input.size(), idx = 0; idx <= size; idx++) {
        if (idx == size) {
            for (int j = r; j < size; j++)
                input[j] = '\0';
        } else {
            if (!ispunct(input[idx])) {
                input[r] = input[idx];
                r++;
            }
        }
    }

    cout << " After cut: " << input << endl;
}
