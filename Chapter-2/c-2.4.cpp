#include <iostream>
#include <string>
using namespace std;

class Parallel
{
    public:
        Parallel() {};
        Parallel(const string& err) {cout << err << endl;}
};

class Line
{
    private:
        double a, b;
    public:
        Line() {};
        Line(double a, double b);
        void setA(double a);
        void setB(double b);
        double getA();
        double getB();
        double intersect(Line& l);
};

Line::Line(double a, double b) 
{
    setA(a);
    setB(b);
}
void Line::setA(double a) {this->a = a;}
void Line::setB(double b) {this->b = b;}
double Line::getA() {return this->a;}
double Line::getB() {return this->b;}
double Line::intersect(Line& l)
{
    if (l.a == this->a)
    {
        throw Parallel("Lines are parallel");
    }
    else
    {
        return (l.b - this->b) / (this->a - l.a);
    }
}

int main()
{
    Line l1(1,3.2);
    Line l2(2,4.5);
    try
    {
        double x = l1.intersect(l2);
        cout << "The lines intersect at x = " << x << endl;
    }
    catch(Parallel& p){};
    
    return 0;
}