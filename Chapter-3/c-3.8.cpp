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
        Node();
        Node(T e);
};

template <typename T>
Node<T>::Node() {};

template <typename T>
Node<T>::Node(T e) : elem(e) {};

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size = 0;
    public:
        LinkedList();
        ~LinkedList();
        void addFront(const T& e);
        void addBack(const T& e);
        void removeFront();
        bool isEmpty() const;
        void display() const;
        int getSize() const;
        Node<T>* getTail() const;
        Node<T>* getHead() const;
        void concat(const LinkedList<T>* l);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {};

template <typename T>
LinkedList<T>::~LinkedList() 
{
    while(!isEmpty()) 
    {
        removeFront();
    }
}

template <typename T>
void LinkedList<T>::addFront(const T& e)
{
    Node<T> *n = new Node<T>(e);
    n -> next = head;
    if (head == nullptr) tail = n;
    head = n;
    size++;
}

template <typename T>
void LinkedList<T>::addBack(const T& e)
{
    Node<T> *n = new Node<T>(e);
    if (tail == nullptr)
    {
        addFront(e);
    }
    else
    {
        tail -> next = n;
        tail = n;
        size++;
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
void LinkedList<T>::display() const
{
    Node<T>* cursor = head;
    while(cursor != nullptr)
    {
        cout << cursor->elem << " ";
        cursor = cursor->next;
    }
    cout << endl;
}

template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() const
{
    return tail;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const
{
    return head;
}

template <typename T>
void LinkedList<T>::concat(const LinkedList<T>* list)
{ 
    tail->next = list->getHead();
}


int main()
{
    LinkedList<int>* l = new LinkedList<int>;
    l->addBack(1);
    l->addBack(2);
    l->addBack(3);
    l->addBack(4);
    l->addBack(5);
    cout << "First list: " << endl;
    l->display();

    LinkedList<int>* l2 = new LinkedList<int>;
    l2->addBack(6);
    l2->addBack(7);
    l2->addBack(8);
    l2->addBack(9);
    l2->addBack(10);
    cout << "Second list: " << endl;
    l2->display();

    l->concat(l2);
    cout << "Concatenated list: " << endl;
    l->display();
    return EXIT_SUCCESS;
}