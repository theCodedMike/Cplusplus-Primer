//
// Created by lixia on 2025/8/18.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

void cin_string();
void getline_string();
void string_cmp();
void string_add();

int main(int argc, char *argv[]) {
    string s1; // 默认初始化，s1是一个空字符串
    if (s1 == "") {
        cout << "s1 is empty string, not nullptr" << endl; // 会被执行
    }
    string s2(s1); // s2是s1的副本    直接初始化
    string s3 = s1; // s3是s1的副本，等价于s2(s1)   拷贝初始化
    string s4("value"); // s4是value的副本，除了字面值最后的那个空字符外
    string s5 = "value";  // 等价于s5("value")
    string s6(5, 'x'); // 等价于s6 = "xxxxx"  直接初始化
    cout << s4 << endl; // value
    cout << s5 << endl; // value
    cout << s6 << endl; // xxxxx

    string name = "1王祖安ha";
    const unsigned int size = name.size();
    cout << size << " " << name.length() << endl; // 12 12
    /* // 这种遍历字符串的方式是有问题的
    for (int i = 0; i < size; i++)
        cout << name[i] << " " << endl;
    */

    //cin_string();
    //getline_string();
    string_cmp();
    //string_add();
}

// 按单词读取
void cin_string() {
    string name;
    cin >> name; // 从第1个非空白字符开始读入，直到遇到下一个空白字符为止
    cout << name << endl;
}

// 按行读取
void getline_string() {
    string name;
    std::getline(cin, name);// 每次读入一整行，直到到达文件末尾
    cout << name << endl;
}

// 字符串比较
void string_cmp() {
    string s1 = "Hello";
    string s2 = "Hello world";
    string s3 = "Hiya";
    cout << s1.compare(s2) << endl; // -6  s1 < s2
    cout << s2.compare(s3) << endl; // -1  s2 < s3
    cout << (s1 > s2) << endl;      // 0
    cout << (s3 >= s2) << endl;     // 1
    string s4 = "Hello";
    cout << (s1 == s4) << endl; // 1
}

// 字符串相加  必须保证+号两侧至少有一个是string对象
void string_add() {
    string s1 = "hello, ";
    string s2 = "world\n";
    string s3 = s1 + s2;
    cout << s3 << endl; // hello, world
    s1 += s2; // 等价于s1 = s1 + s2
    cout << s1 << endl; // hello, world

    //string s4 = "what" + "the"; // ❌ +号的两侧至少有一个是string对象
    //string s5 = "hello" + ", " + s1; // ❌
    string s6 = "what" + s1;
}