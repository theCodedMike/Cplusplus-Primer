//
// Created by lixia on 2025/10/7.
//

namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}
int ivar = 0;
// 位置1
using namespace Exercise;
void manip() {
    // 位置2

    double dvar = 3.1416;
    int iobj = limit + 1;
    //++ivar;
    ++::ivar;
}

int main(int argc, char *argv[]) {

}
