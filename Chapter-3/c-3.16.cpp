#include <iostream>
using namespace std;

int max(int arr[], int n)
{
    if (n == 1) return arr[0];
    else return max(arr[n-1], max(arr,n-1));
}

int min(int arr[], int n)
{
    if (n == 1) return arr[0];
    else return min(arr[n-1], min(arr,n-1));
}

void display(int arr[], int n)
{
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int a[] = {1,2,3,4,5};
    cout << "Input array:" << endl;
    display(a,5);
    cout << "Maximum element: " << max(a,5) << endl;
    cout << "Minimum element: " << min(a,5) << endl;
    return EXIT_SUCCESS;
}