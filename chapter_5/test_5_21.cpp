//
// Created by lixia on 2025/8/26.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string curr, prev;

    while (cin >> curr && curr != "done") {
        if (islower(curr[0]) || curr != prev) {
            prev = curr;
            continue;
        }

        cout << "Repeated word: " << curr << endl;
        break;
    }

    if (curr == "done")
        cout << "No repeated words." << endl;
}
