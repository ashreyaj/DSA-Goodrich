// Implement queue with a singly linked list
#include <iostream>
#include <forward_list>
using namespace std;

template <typename T>
class Queue
{
    private:
        forward_list<T> q;
        int size;
    public:
        Queue();
        ~Queue();
        void push(const T& x);
        void pop();
        T front() const;
        T back() const;
        int getSize() const;
        bool isEmpty() const;
        void display() const;
};

template <typename T>
Queue<T>::Queue() : size(0) {};

template <typename T>
Queue<T>::~Queue() {q.clear();}

template <typename T>
void Queue<T>::push(const T& x)  // change
{
    if (size != 0)
    {
        auto before_end = q.before_begin();
        for (auto& _ : q) before_end++;
        q.insert_after(before_end, x);
    }
    else {q.push_front(x);}
    size++;
}

template <typename T>
void Queue<T>::pop()
{
    q.pop_front();
    size--;
}

template <typename T>
T Queue<T>::front() const
{
    return q.front();
}

template <typename T>
T Queue<T>::back() const
{
    return *(q.end());
}

template <typename T>
int Queue<T>::getSize() const
{
    return size;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
void Queue<T>::display() const
{
    for (auto it=q.begin(); it!=q.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    Queue<int> q;
    for (int i=0; i<6; i++) q.push(i+1);
    cout << "Initial queue" << endl;
    q.display();

    cout << "Queue after dequeueing one element" << endl;
    q.pop();
    q.display();
    
    return EXIT_SUCCESS;
}