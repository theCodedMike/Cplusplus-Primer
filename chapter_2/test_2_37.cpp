//
// Created by lixia on 2025/8/17.
//

int main(int argc, char *argv[]) {
    int a = 3, b = 4;
    decltype(a) c = a; // int c = a;
    decltype(a = b) d = a; // int &d = a;
}
