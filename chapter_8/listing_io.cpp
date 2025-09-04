//
// Created by lixia on 2025/9/4.
//

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    cout << "hi!" << endl;  // 输出hi和一个换行，然后刷新缓冲区
    cout << "hi!" << flush; // 输出hi，然后刷新缓冲区
    cout << "hi!" << ends;  // 输出hi和一个空字符，然后刷新缓冲区

    cout << unitbuf; // 所有输出都立即刷新，无缓冲
    cout << nounitbuf; // 回到正常缓冲模式
}

void tie() {
    cin.tie(&cout); // 标准库将cin和cout关联在一起
    ostream * old_tie = cin.tie(nullptr); // cin不再与其他流关联
    cin.tie(old_tie); // 重建cin和cout的正常关联
}