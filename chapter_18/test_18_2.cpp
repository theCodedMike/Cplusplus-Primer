//
// Created by lixia on 2025/10/7.
//

#include <vector>
#include <fstream>
using namespace std;

void exercise(int *b, int *e) {
    vector<int> v(b, e);
    int *p = new int[v.size()];
    ifstream in("ints");
    // 此处发生异常  许多资源未被释放
    throw runtime_error("error...");
}

int main(int argc, char *argv[]) {

}
