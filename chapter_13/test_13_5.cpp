//
// Created by lixia on 2025/9/17.
//

#include <string>
using namespace std;

class HasPtr {
    string *ps;
    int i;

public:
    explicit HasPtr(const string &s = string())
        : ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &hp);
    HasPtr& operator=(const HasPtr &hp);
    ~HasPtr() {delete ps;}
};

HasPtr::HasPtr(const HasPtr &hp) :
    ps(new string(*hp.ps)),
    i(hp.i)
{ }

HasPtr& HasPtr::operator=(const HasPtr &hp) {
    const auto new_ps = new string(*hp.ps);
    delete ps;
    ps = new_ps;
    i = hp.i;
    return *this;
}


int main(int argc, char *argv[]) {

}
