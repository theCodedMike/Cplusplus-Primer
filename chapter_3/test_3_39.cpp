//
// Created by lixia on 2025/8/22.
//

#include <iostream>
#include <string>
#include <cstring>
using std::string;
using std::cout;
using std::endl;
using std::size;
using std::strlen;

int cmp_string(const string &, const string &);
int cmp_char_array(const char *, size_t, const char *, size_t);

int main(int argc, char *argv[]) {
    string s1 = "hello";
    string s2 = "world";
    string s3 = "hello,";
    cout << s1.size() << " " << size(s1) << endl; // 5 5
    cout << "s1 s2: " << cmp_string(s1, s2) << std::endl; // -1
    cout << "s1 s3: " << cmp_string(s1, s3) << std::endl; // -1

    const char ca1[] = "hello";
    const char ca2[] = "world";
    const char ca3[] = "hello,";
    cout << size(ca1) << " " << strlen(ca1)<< endl; // 6 5
    cout << "ca1 ca2: " << cmp_char_array(ca1, strlen(ca1), ca2, strlen(ca2)) << std::endl; // -15
    cout << "ca1 ca3: " << cmp_char_array(ca1, strlen(ca1), ca3, strlen(ca3)) << std::endl; // -1
}

int cmp_string(const string &s1, const string &s2) {
    return s1.compare(s2);
}

int cmp_char_array(const char *c1, const size_t size1, const char *c2, const size_t size2) {
    size_t c_len = size1 <= size2 ? size1 : size2;

    for (int i = 0; i < c_len; ++i, ++c1, ++c2) {
        if (*c1 != *c2)
            return *c1 - *c2;
    }

    if (*c1 == '\0')
        return -1;

    return 1;
}