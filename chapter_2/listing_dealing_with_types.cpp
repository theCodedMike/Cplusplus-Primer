//
// Created by lixia on 2025/8/17.
//


int main(int argc, char *argv[]) {
    auto i = 0, *p = &i; // ✔
    //auto sz = 0, pi = 3.14;   // ❌ sz和pi类型不一致

    int j = 0, &r = j;
    auto a = r; // a is int type

    // auto
    {
        int m = 10;
        const int ci = m, &cr = ci;
        auto b = ci;         // b是一个int，ci的顶层const特性被忽略
        auto c = cr;         // c是一个int，cr是ci的别名，ci本身是一个顶层const
        auto d = &m;       // d是一个int*
        auto e = &ci;  // e是一个const int*
    }

    // decltype
    {
        int i = 42, *p = &i, &r = i;
        decltype(r + 0) b; // ✔ b是一个未初始化的int
        //decltype(*p) c; // ❌ c是int&，必须初始化
        //decltype((i)) d; // ❌ d是int&，必须初始化
        decltype(i) e;  // ✔ e是一个未初始化的int
    }
}
