#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector< vector<int> > v)
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

int sum_row(vector<int> r, int col)
{
    if (col == 0) return r[col];
    else
    {
        return r[col] + sum_row(r, col-1);
    }
}

int sum(vector< vector<int> > v, int rows, int cols)
{
    if (rows == 0) return v[0][cols];
    else
    {
        return sum_row(v[rows], cols) + sum(v, rows-1, cols);
    }
}

int main()
{
    int rows = 5;
    int cols = 4;
    vector< vector<int> > v(5, vector<int>(cols));
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            v[i][j] = i;
        }
    }
    cout << "Input matrix: " << endl;
    printMatrix(v);
    cout << "Sum of all elements of matrix is " << sum(v, rows-1, cols-1) << endl;
    return 0;
}