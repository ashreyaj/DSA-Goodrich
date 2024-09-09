// Implement deque with doubly-linked list
#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Dequeue
{
    private:
        list<T> dq;
    public:
        Dequeue();
        ~Dequeue();
        void push_front(const T& x);
        void push_back(const T& x);
        void pop_back();
        void pop_front();
        T getFront() const;
        T getBack() const;
        void display();
};

template <typename T>
Dequeue<T>::Dequeue() {};

template <typename T>
Dequeue<T>::~Dequeue() {dq.clear();};

template <typename T>
void Dequeue<T>::push_front(const T& x) {dq.push_front(x);}

template <typename T>
void Dequeue<T>::push_back(const T& x) {dq.push_back(x);}

template <typename T>
void Dequeue<T>::pop_front() {dq.pop_front();}

template <typename T>
void Dequeue<T>::pop_back() {dq.pop_back();}

template <typename T>
T Dequeue<T>::getFront() const {return dq.front();}

template <typename T>
T Dequeue<T>::getBack() const {return dq.back();}

template <typename T>
void Dequeue<T>::display()
{
    auto it = dq.begin();
    for (;it != dq.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    Dequeue<int> q;
    for (int i=0; i<6; i++) q.push_back(i+1);
    cout << "Initial dequeue" << endl;
    q.display();

    cout << "After one pop_front and pop_back" << endl;
    q.pop_front();
    q.pop_back();
    q.display();
    
    return EXIT_SUCCESS;
}