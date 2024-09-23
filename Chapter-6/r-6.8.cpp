#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T sum_vector(vector<T> v)
{
    T sum = 0;
    typename vector<T>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
    {
        sum += *it;
    }
    return sum;
}

template <typename T>
void display(vector<T> v)
{
    typename vector<T>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    cout << "Input vector is: " << endl;
    display(v);
    cout << "Sum of elements of vector is: " << sum_vector(v) << endl;
    return EXIT_SUCCESS;
}