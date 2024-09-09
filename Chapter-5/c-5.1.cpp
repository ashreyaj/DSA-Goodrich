#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue
{
    private:
        stack<T> s;
        stack<T> t;
    public:
        Queue();
        ~Queue();
        void enqueue(T& x);
        T dequeue();
        void display();
};

template <typename T>
Queue<T>::Queue() {};

template <typename T>
Queue<T>::~Queue()
{
    while (!s.empty()) {s.pop();}
    while (!t.empty()) {t.pop();}
}

template <typename T>
void Queue<T>::enqueue(T& x)
{
    s.push(x);
}

template <typename T>
T Queue<T>::dequeue()
{
    while (!s.empty())
    {
        t.push(s.top());
        s.pop();
    }
    T value = t.top();
    t.pop();
    while (!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
    return value;
}

template <typename T>
void Queue<T>::display()
{
    cout << "Front to back" << endl;
    while (!s.empty())
    {
        t.push(s.top());
        s.pop();
    }
    while (!t.empty())
    {
        cout << t.top() << " ";
        s.push(t.top());
        t.pop();
    }
    cout << endl;
}

template <typename T>
class Dequeue
{
    private:
        stack<T> front;
        stack<T> back;
        int size;
        int size_front;
        int size_back;
    public:
        Dequeue();
        ~Dequeue();
        void push_front(T& x);
        void push_back(T& x);
        void pop_front();
        void pop_back();
        T getFront() const;
        T getBack() const;
        bool isEmpty() const;
        void display();
};

template <typename T>
Dequeue<T>::Dequeue() {};

template <typename T>
Dequeue<T>::~Dequeue()
{
    while (size_front != 0)
    {
        pop_front();
    }
    while (size_back != 0)
    {
        pop_back();
    }
}

template <typename T>
void Dequeue<T>::push_front(T& x)
{
    for (int i=0; i<size_front; i++)
    {
        back.push(front.top());
        front.pop();
    }
    back.push(x);
    size_front++;
    for (int i=0; i<size_front; i++)
    {
        front.push(back.top());
        back.pop();
    }
}

template <typename T>
void Dequeue<T>::push_back(T& x)
{
    for (int i=0; i<size_back; i++)
    {
        front.push(back.top());
        back.pop();
    }
    front.push(x);
    size_back++;
    for (int i=0; i<size_back; i++)
    {
        back.push(front.top());
        front.pop();
    }
}

template <typename T>
void Dequeue<T>::pop_front()
{
    for (int i=0; i<size_front; i++)
    {
        back.push(front.top());
        front.pop();
    }
    back.pop();
    size_front--;
    for (int i=0; i<size_front; i++)
    {
        front.push(back.top());
        back.pop();
    }
}

template <typename T> 
void Dequeue<T>::pop_back()
{
    for (int i=0; i<size_back; i++)
    {
        front.push(back.top());
        back.pop();
    }
    front.pop();
    size_back--;
    for (int i=0; i<size_back; i++)
    {
        back.push(front.top());
        front.pop();
    }
}

template <typename T>
T Dequeue<T>::getFront() const
{
    for (int i=0; i<size_front; i++)
    {
        back.push(front.top());
        front.pop();
    }
    T value = back.top();
    for (int i=0; i<size_front; i++)
    {
        front.push(back.top());
        back.pop();
    }
    return value;
}


template <typename T>
T Dequeue<T>::getBack() const
{
    for (int i=0; i<size_back; i++)
    {
        front.push(back.top());
        back.pop();
    }
    T value = front.top();
    for (int i=0; i<size_back; i++)
    {
        back.push(front.top());
        front.pop();
    }
}

template <typename T>
bool Dequeue<T>::isEmpty() const
{
    return ((size_front+size_back)>0)?false:true;
}

template <typename T>
void Dequeue<T>::display()
{
    for (int i=0; i<size_front; i++)
    {
        back.push(front.top());
        front.pop();
    }
    cout << "From front to back:\n";
    for (int i=0; i<size_front; i++)
    {
        cout << back.top() << " ";
        front.push(back.top());
        back.pop();
    }
    for (int i=0; i<size_back; i++)
    {
        cout << back.top() << " ";
        front.push(back.top());
        back.pop();
    }
    cout << endl;
    for (int i=0; i<size_back; i++)
    {
        back.push(front.top());
        front.pop();
    }
}

int main()
{
    Queue<int> q;
    for (int i=0; i<6; i++) {q.enqueue(i);}
    q.display();
    cout << "Element removed after dequeueing: " << q.dequeue() << endl;
    q.display();

    Dequeue<int> q2;
    for (int i=0; i<6; i++) {q2.push_front(i);}
    for (int i=0; i<6; i++) {q2.push_back(i);}
    cout << "--- Double-ended queue ---" << endl;
    q2.display();
    q2.pop_front();
    q2.pop_back();
    cout << "After removing first and last element, the queue is" << endl;
    q2.display();
     
    return EXIT_SUCCESS;
}