#include <iostream>
using namespace std;

template <typename T>
class ArrayVector
{
    private:
        int capacity;
        int n;
        T* A;
    public:
        ArrayVector();
        ArrayVector(ArrayVector& other);
        ~ArrayVector();
        int size() const;
        bool empty() const;
        const T& operator[](int i);
        T& at(int i);
        void erase(int i);
        void insert(int i, const T& e);
        void reserve(int N);
};

template <typename T>
ArrayVector<T>::ArrayVector() : capacity(0), n(0), A(nullptr) {};

template <typename T>
ArrayVector<T>::ArrayVector(ArrayVector& other)
{
    int s = other.size();
    A = new T[s];
    for (int i=0; i<s; i++)
    {
        A[i] = other[i];
    }
    n = s;
    capacity = other.capacity;
}

template <typename T>
ArrayVector<T>::~ArrayVector()
{
    delete[] A;
    A = nullptr;
}

template <typename T>
int ArrayVector<T>::size() const {return n;}

template <typename T>
bool ArrayVector<T>::empty() const {return n==0;}

template <typename T>
const T& ArrayVector<T>::operator[](int i) {return A[i];}

template <typename T>
T& ArrayVector<T>::at(int i)
{
    if (i<0 || i>(n-1))
    {
        cout << "Illegal index in function at()" << endl;
        exit(1);
    }
    return A[i];
}

template <typename T>
void ArrayVector<T>::erase(int i)
{
    for (int j=i+1;j<n;j++)
    {
        A[j-1] = A[j];
    }
    n--;
}

template <typename T>
void ArrayVector<T>::insert(int i, const T& e)
{
    if (n >= capacity) {reserve(2 * capacity + 1);}
    for (int j=n-1; j>=i; j--)
    {
        A[j+1] = A[j];
    }
    A[i] = e;
    n++;
}

template <typename T>
void ArrayVector<T>::reserve(int N)
{
    if (capacity >= N) {return;}
    T* arr = new T[N];
    for (int i=0; i<n; i++)
    {
        arr[i] = A[i];
    }
    delete[] A;
    A = arr;
    capacity = N;
}

// template <typename T>

int main()
{
    ArrayVector<int> a1; // a1 = {2,1}
    a1.insert(0,1);
    a1.insert(0,2);
    cout << a1.at(0) << endl;

    ArrayVector<int> a2(a1);
    cout << a2.at(0) << endl;

    return EXIT_SUCCESS;
}