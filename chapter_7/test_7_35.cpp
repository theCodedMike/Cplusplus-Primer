//
// Created by lixia on 2025/9/2.
//

#include <string>
using namespace std;

typedef string Type;
Type initVal();

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    static Type initVal();
private:
    int val = 0;
};

Exercise::Type Exercise::setVal(const Type parm) {
    val = static_cast<int>(parm + initVal());
    return val;
}

Exercise::Type Exercise::initVal() {
    return 0;
}


int main(int argc, char *argv[]) {

}
