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
    public:
        T getElem() const;
};

template <typename T>
T Node<T>::getElem() const {return elem;}

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
        Node<T>* penultimate() const;
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
Node<T>* LinkedList<T>::penultimate() const
{
    Node<T>* n1;
    Node<T>* n2;
    n2 = head;
    while (n2->next != nullptr) 
    {
        n1 = n2;
        n2 = n1->next;
    }
    return n1;
}

int main()
{
    LinkedList<int> l;
    l.addFront(95);
    l.addFront(63);
    l.addFront(10);
    l.addFront(23);
    l.addFront(89);
    Node<int>* pen = l.penultimate();
    cout << "Penultimate element is: " << pen->getElem() << endl;
    return 0;
}