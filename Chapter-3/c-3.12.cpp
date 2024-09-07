#include <iostream>
using namespace std;

void hanoi(int n, char src, char dest, char help)
{
    if (n == 0) return;
    else
    {
        hanoi(n-1, src, help, dest);
        cout << "Move from rod " << src << " to rod " << dest << endl;
        hanoi(n-1, help, dest, src);
    }
}

int main()
{
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return EXIT_SUCCESS;
}