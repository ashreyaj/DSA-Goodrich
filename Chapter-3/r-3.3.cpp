#include <iostream>
#include <vector>
using namespace std;

void transpose(vector< vector<float> > &v)
{
    float temp;
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<i; j++)
        {
            temp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = temp;
         }
    }
}

void printMatrix(vector< vector<float> > v)
{
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    vector< vector<float> > vec(n, vector<float>(n));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            vec[i][j] = i*2 + j; // random values
        }
    }
    cout << "Input matrix is: " << endl;
    printMatrix(vec);
    cout << "Transpose of the matrix is: " << endl;
    transpose(vec);
    printMatrix(vec);
    return 0;
}