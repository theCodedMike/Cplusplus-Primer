//
// Created by lixia on 2025/8/25.
//
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string input;
    getline(cin, input);

    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    for (const char & ch: input) {
        if (ch == 'a')
            ++aCnt;
        if (ch == 'e')
            ++eCnt;
        if (ch == 'i')
            ++iCnt;
        if (ch == 'o')
            ++oCnt;
        if (ch == 'u')
            ++uCnt;
    }

    cout << "Number of vowel a: " << aCnt << '\n'
         << "Number of vowel e: " << eCnt << '\n'
         << "Number of vowel i: " << iCnt << '\n'
         << "Number of vowel o: " << oCnt << '\n'
         << "Number of vowel u: " << uCnt << '\n';
}
