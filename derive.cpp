#include <iostream>
#include <string>
using std::string;
struct B {
    string s;
    virtual ~B() {}
};
struct D: public B {
    string t;
};

int main()
{
    B* bp = new D;
    delete  bp;
    return 0;
}

