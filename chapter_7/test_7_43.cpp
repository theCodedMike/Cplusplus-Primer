//
// Created by lixia on 2025/9/3.
//

#include <vector>
using namespace std;

class NoDefault {
    int num;
public:
    NoDefault(const int i) : num(i) {}
};

class C {
    NoDefault nd;
public:
    C(const int i = 10) : nd(i) {}
};

int main(int argc, char *argv[]) {
    //vector<NoDefault> vec(10); // 报错，NoDefault没有默认构造函数
    vector<C> vec(10);
}
