//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
    map<string, vector<pair<string, string>>> family;
    string family_name;
    string first_name;
    string birth_date;

    while (true) {
        cout << "Enter your family name('quit' to quit): ";
        cin >> family_name;
        if (family_name == "quit")
            break;

        cout << "Enter your children's first name and birth date, 'done' to quit." << endl;
        while (cin >> first_name) {
            if (first_name == "done")
                break;

            cin >> birth_date;
            if (birth_date == "done")
                break;

            family[family_name].emplace_back(first_name, birth_date);
        }
    }

    for (const auto &[fam_name, children]: family) {
        for (const auto &[fir_name, bd]: children) {
            cout << fir_name << " " << fam_name << ", birth date: " << bd << endl;
        }
        cout << endl;
    }
}
