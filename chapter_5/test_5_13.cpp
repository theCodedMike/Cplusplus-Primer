//
// Created by lixia on 2025/8/25.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {

}


char next_text() {
    char input;
    cin >> input;
    return input;
}
//
// unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
// char ch = next_text();
// switch (ch) {
//     case 'a': aCnt++;
//     case 'e': eCnt++;
//     default: iouCnt++;
// }
void snippet1() {
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        case 'i': case 'o': case 'u': iouCnt++; break;
    }

    cout << "aCnt: " << aCnt << " eCnt: " << eCnt << " iouCnt: " << iouCnt << endl;
}

unsigned some_value() {
    return 1;
}
int get_value() {

}
//
// unsigned index = some_value();
// switch (index) {
//     case 1:
//         int ix = get_value();
//         ivec[ix] = index;
//         break;
//     default:
//         ix = ivec.size() - 1;
//         ivec[ix] = index;
void snippet2() {
    unsigned index = some_value();
    vector<unsigned> ivec(10, 0);

    switch (index) {
        case 1: {
            int ix = get_value();
            ivec[ix] = index;
            break;
        }
        default: {
            size_t ix = ivec.size() - 1;
            ivec[ix] = index;
        }
    }

    cout << "index: " << index << endl;
}

int get_num() {
    return 10;
}
// unsigned evenCnt = 0, oddCnt = 0;
// int digit = get_num() % 10;
// switch (digit) {
//     case 1, 3, 5, 7, 9:
//         oddCnt++;
//         break;
//     case 2, 4, 6, 8, 0:
//         evenCnt++;
//         break;
// }
void snippet3() {
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddCnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evenCnt++;
            break;
    }
    cout << "evenCnt: " << evenCnt << " oddCnt: " << oddCnt << endl;
}


unsigned get_bufCnt() {
    return 1;
}
// unsigned ival = 512, jval = 1024, kval = 4096;
// unsigned bufsize;
// unsigned swt = get_bufCnt();
// switch (swt) {
//     case ival: bufsize = ival * sizeof(int); break;
//     case jval: bufsize = jval * sizeof(int); break;
//     case kval: bufsize = kval * sizeof(int); break;
// }
void snippet4() {
    const unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt) {
        case ival: bufsize = ival * sizeof(int); break;
        case jval: bufsize = jval * sizeof(int); break;
        case kval: bufsize = kval * sizeof(int); break;
    }

    cout << "bufsize: " << bufsize << endl;
}