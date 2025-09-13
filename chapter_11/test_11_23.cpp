//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <map>

using namespace std;


int main(int argc, char *argv[]) {
    map<string, multimap<string, string>> family;
    string family_name, first_name, birth_date;

    while (true) {
        cout << "Enter your family name('quit' to quit): ";
        cin >> family_name;
        if (family_name == "quit")
            break;


        while (true) {
            cout << "Enter your first name and birth date('quit' to quit): ";
            cin >> first_name;
            if (first_name == "quit")
                break;
            cin >> birth_date;
            if (birth_date == "quit")
                break;

            family[family_name].insert({first_name, birth_date});
        }
    }

    for (const auto &[fam_name, first_names]: family) {
        for (const auto & [fir_name, birth]: first_names) {
            cout << fir_name << " " << fam_name << ", birth date: " << birth << endl;
        }
    }
}
