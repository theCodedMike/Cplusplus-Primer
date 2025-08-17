//
// Created by lixia on 2025/8/17.
//

int main(int argc, char *argv[]) {
    // 在这种情况下，两者都是int类型
    {
        int i = 42;
        auto a = i;        // a的类型是int
        decltype(i) b = i; // b的类型是int
    }

    // 在这种情况下，两者不同
    {
        int i = 42;
        int& r = i;

        auto a = r;          // a的类型是int (auto忽略引用)
        decltype(r) b = r;   // b的类型是int& (decltype保留引用)

        const int ci = 0;
        auto c = ci;         // c的类型是int (auto忽略顶层const)
        decltype(ci) d = ci; // d的类型是const int (decltype保留顶层const)

        int j = 0;
        auto e = (j);        // e的类型是int (括号不影响auto)
        decltype((j)) f = j; // f的类型是int& (decltype将表达式j视为左值，返回引用)
    }
}
