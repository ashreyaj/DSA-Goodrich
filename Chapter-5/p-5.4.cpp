// Implement stack using vector

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
    private:
        vector<T> stack;
    public:
        Stack();
        ~Stack();
        void push(const T& x);
        void pop();
        T top();
        int getSize() const;
        bool isEmpty() const;
        void display() const;
};

template <typename T>
Stack<T>::Stack() {};

template <typename T>
Stack<T>::~Stack() {stack.clear();}

template <typename T>
void Stack<T>::push(const T& x)
{
    stack.push_back(x);
}

template <typename T>
void Stack<T>::pop()
{
    stack.pop_back();
}

template <typename T>
T Stack<T>::top()
{
    stack.back();
}

template <typename T>
int Stack<T>::getSize() const
{
    return stack.size();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return stack.empty();
}

template <typename T>
void Stack<T>::display() const
{
    for (int i=0; i<stack.size(); i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack<int> s;
    for (int i=0; i<6; i++) s.push(i+1);
    cout << "Current stack" << endl;
    s.display();

    s.pop();
    cout << "Stack after popping one element" << endl;
    s.display();

    return EXIT_SUCCESS;
}