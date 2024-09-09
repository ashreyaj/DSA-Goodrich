 // Stack using two queues

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
    private:
        queue<T> stack;
        queue<T> aux;
        int size;
    public:
        Stack();
        ~Stack();
        void push(const T& x);
        void pop();
        T top();
        int getSize() const;
        bool isEmpty();
        void display();
};

template <typename T>
Stack<T>::Stack() : size(0) {};

template <typename T>
Stack<T>::~Stack()
{
    queue<T> empty;
    swap(stack, empty);
}

template <typename T>
void Stack<T>::push(const T& x)
{
    stack.push(x);
    size++;
}

template <typename T>
void Stack<T>::pop()
{
    for (int i=1; i<size; i++)
    {
        aux.push(stack.front());
        stack.pop();
    }
    stack.pop();
    size--;
    for (int i=0; i<size; i++)
    {
        stack.push(aux.front());
        aux.pop();
    }
}

template <typename T>
T Stack<T>::top()
{
    return stack.back();
}

template <typename T>
int Stack<T>::getSize() const {return size;}

template <typename T>
bool Stack<T>::isEmpty() {return size == 0;}

template <typename T>
void Stack<T>::display()
{
    cout << "From bottom to top" << endl;
    for (int i=0; i<size; i++)
    {
        cout << stack.front() << " ";
        aux.push(stack.front());
        stack.pop();
    }
    cout << endl;
    for (int i=0; i<size; i++)
    {
        stack.push(aux.front());
        aux.pop();
    }
}

int main()
{
    Stack<int> s;
    for (int i=0; i<6; i++) s.push(i+1);
    cout << "Initial stack" << endl;
    s.display();
    cout << "Top of stack: " << s.top() << endl;
    s.pop();
    cout << "Stack after popping one item" << endl;
    cout << "Top of stack: " << s.top() << endl;
    s.display();
    return EXIT_SUCCESS;
}