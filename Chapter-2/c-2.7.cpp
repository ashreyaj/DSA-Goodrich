#include <iostream>
using namespace std;

class A
{
    protected:
        int x = 1;
};

class B : public A
{
    protected:
        int x = 1;
};

class C : public B
{
    public:
        int x = 1;
        void setXinA(int a) {A::x = a; cout << "x in A: " << A::x << endl << "x in B: " << B::x << endl << "x in C: " << C::x << endl;}
};

int main()
{
    C c;
    c.setXinA(3);
    return 0;
}