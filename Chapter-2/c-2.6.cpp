#include <iostream>
#include <cmath>
using namespace std;

class Progression
{
    protected:
        double first;
        double cur;
        virtual double reset() = 0;
        virtual double nextValue() = 0;
    public:
        Progression() {};
        Progression(double f) : first(f), cur(f) {};
        virtual ~Progression() {};
};

class SqrtProgression : public Progression
{
    public:
        SqrtProgression() : Progression(65536){};
        SqrtProgression(double f) : Progression(f){};
        virtual double reset() {cur = first; return cur;}
        virtual double nextValue()
        {
            cur = sqrt(cur);
            return cur;
        }
};

int main()
{
    SqrtProgression p;
    cout << "Progression:" << endl;
    cout << p.nextValue() << " " << p.nextValue() << " " << p.nextValue() << endl;
    return 0;
}