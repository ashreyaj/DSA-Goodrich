#include <iostream>
using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    private:
        T elem;
        Node<T>* next;
        friend class LinkedList<T>;
};

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
        int size = 0;
    public:
        LinkedList();
        ~LinkedList();
        T& getFront() const;
        void addFront(const T& e);
        void removeFront();
        bool isEmpty() const;
        int getSize() const;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {};

template <typename T>
LinkedList<T>::~LinkedList() 
{
    while(!isEmpty()) 
    {
        removeFront();
    }
}

template <typename T>
T& LinkedList<T>::getFront() const {return head -> elem;}

template <typename T>
void LinkedList<T>::addFront(const T& e)
{
    Node<T> *n = new Node<T>;
    n -> elem = e;
    n -> next = head;
    head = n;
    size++;
}

template <typename T>
void LinkedList<T>::removeFront()
{
    Node<T>* old = head;
    head = old -> next;
    delete old;
    size--;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {return head == nullptr;}

template <typename T>
int LinkedList<T>::getSize() const {return size;}

int main()
{
    LinkedList<int> l;
    l.addFront(10);
    l.addFront(23);
    l.addFront(89);
    cout << "Size of linked list after adding three elements is: " << l.getSize() << endl;
    l.removeFront();
    cout << "Size of linked list after removing one element is: " << l.getSize() << endl;
    return 0;
}