#include<iostream>
using namespace std;

void checkBound(int index, int size)
{
    if (index >= size)
    {
        throw 101;
    }
}


int main()
{
    int s = 5;
    try
    {
        checkBound(6,s);
    }
    catch(int e)
    {
        cerr << "Index is out of bounds" << endl;
    }
    return 0;
}