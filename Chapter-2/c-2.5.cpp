#include <iostream>
using namespace std;

class Progression
{
    protected:
        long first;
        long cur;
        virtual long reset() = 0;
        virtual long nextValue() = 0;
    public:
        Progression() {};
        Progression(long f) : first(f), cur(f) {};
        virtual ~Progression() {};
};

class AbsDiffProgression : public Progression
{
    private:
        long second;
        long prev;
        long absdiff = 0;
    public:
        AbsDiffProgression() : Progression(2), second(200), prev(2) {cur = 200;};
        AbsDiffProgression(long f, long s) : Progression(f), second(s), prev(f) {cur = s;};
        virtual long reset() {cur = second; prev = first; return cur;}
        virtual long nextValue()
        {
            absdiff = abs(cur - prev);
            prev = cur;
            cur = absdiff;
            return cur;
        }
};

int main()
{
    AbsDiffProgression p;
    cout << "Progression:" << endl;
    cout << p.nextValue() << " " << p.nextValue() << " " << p.nextValue() << endl;
    return 0;
}