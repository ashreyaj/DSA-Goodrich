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
        void removeFront();
        bool isEmpty() const;
        void addFront(const T& e);
        void display() const;
        int length() const;
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
void LinkedList<T>::addFront(const T& e)
{
    Node<T> *n = new Node<T>;
    n -> elem = e;
    n -> next = head;
    head = n;
    size++;
}

template <typename T>
void LinkedList<T>::display() const
{
    cout << "Elements of the list are: ";
    Node<T>* cursor = head;
    while (cursor -> next != nullptr)
    {
        cout << cursor -> elem << " ";
        cursor = cursor -> next;
    }
    cout << cursor -> elem << endl;
}

template <typename T>
int LinkedList<T>::length() const
{
    int n;
    Node<T>* cursor = head;
    while (cursor -> next != nullptr)
    {
        n++;
        cursor = cursor->next;
    }
    return n;
}

int main()
{
    LinkedList<int> l;
    l.addFront(95);
    l.addFront(63);
    l.addFront(10);
    l.addFront(23);
    l.addFront(89);
    l.display();
    cout << "Length of list is: " << l.length() << endl;
    return 0;
}