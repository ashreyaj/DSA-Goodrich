#include<iostream>
using namespace std;

template <typename A, typename B>
class Pair
{
    A first;
    B second;
    public:
        Pair() {};
        Pair(A a, B b) 
        {
            setFirst(a);
            setSecond(b);
        }
        void setFirst(A a) {first = a;}
        void setSecond(B b) {second = b;}
        A getFirst() {return first;}
        B getSecond() {return second;}
};

int main()
{
    Pair p1(1,2);
    Pair p2(1,2.34f);
    Pair p3(3,"abcd");
    Pair p4(1.324L,5.33f);
    Pair p5("abcd","ijkl");
    return 0;
}