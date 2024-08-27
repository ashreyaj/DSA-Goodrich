#include<iostream>
using namespace std;

bool hasDuplicates(vector<int>& arr) 
{
    for (int i = 0; i < arr.size(); ++i) 
    {
        for (int j = i + 1; j < arr.size(); ++j) 
        {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

int main()
{
    int size;
    cout << "Enter size of vector: " << endl;
    cin >> size;
    vector<int> A(size);
    cout << "Enter sequence of integers: " << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> A[i];
    }
    cout << "Does the array have duplicates? " << hasDuplicates(A) << endl;
    return 0;
}