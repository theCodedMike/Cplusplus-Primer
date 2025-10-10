//
// Created by lixia on 2025/10/10.
//
#include <iostream>
using namespace std;

void *operator new(const size_t size) {
    if (void *mem = malloc(size))
        return mem;

    throw bad_alloc();
}

void operator delete(void *mem) noexcept {
    free(mem);
}

int main(int argc, char *argv[]) {
    const auto p = new int;
    *p = 42;
    cout << *p << endl;
    delete p;
}
