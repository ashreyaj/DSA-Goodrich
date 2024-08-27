#include<iostream>
using namespace std;

void printArray(int ** A, int m, int n)
{
    for (int _m=0; _m<m; _m++)
    {
        for (int _n=0; _n<n; _n++)
        {
            cout << A[_m][_n] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int m = 5;
    int n = 4;
    int** A;
    A = new int*[m];
    for (int _m=0; _m<m; _m++)
    {
        A[_m] = new int[n];
    }
    // populate array
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            A[i][j] = i;
        }
    }

    printArray(A, m, n);
    return 0;
}