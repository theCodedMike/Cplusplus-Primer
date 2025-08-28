//
// Created by lixia on 2025/8/28.
//

#include "./../include/Chapter6.h"

string chinese_names[10] = {"张三", "李四", "王五", "赵六", "孙七", "周八", "吴九", "郑十", "王十一", "王十二"};
string english_names[10] = {"Alice", "Bob", "Charlie", "David", "Edward", "Frank", "George", "Helen", "Ivan", "James"};

using strArr = string[10];

int main(int argc, char *argv[]) {

}

// 原始
string (&get_names(const int num))[10] {
    return num % 2 == 0 ? chinese_names : english_names;
}
// 类型别名
strArr &get_names2(const int num) {
    return num % 2 == 0 ? chinese_names : english_names;
}
// 尾置
auto get_names3(const int num) -> string(&)[10] {
    return num % 2 == 0 ? chinese_names : english_names;
}
// decltype
decltype(chinese_names) &get_names4(const int num) {
    return num % 2 == 0 ? chinese_names : english_names;
}