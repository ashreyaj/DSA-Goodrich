#include<iostream>
#include<vector>
using namespace std;

template <class T>
T dot(vector<T> a, vector<T> b)
{
    int c = 0;
    int size = a.size();
    for (int i=0; i<size; i++)
    {
        c += a[i] * b[i];
    }
    return c;
}

int main()
{
    vector<int> x{1,2,3,4};
    vector<int> y{1,2,3,4};
    cout << "Dot product is: " << dot(x,y);
    return 0;
}