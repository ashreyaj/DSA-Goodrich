#include <iostream>
#include "NodeList.h"
using namespace std;

template <typename T>
struct NodeList<T>::Node
{
    T elem;
    Node* next;
    Node* prev;
};

template <typename T>
class NodeList<T>::Iterator
{
    private:
        Iterator(Node* u);
        Node* v;
    public:
        T& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++(); // pre-increment
        Iterator& operator--();
        Iterator operator++(int); // post-increment
        friend class NodeList;
};

template <typename T>
class NodeSequence : public NodeList<T>
{
    public:
        typename NodeList<T>::Iterator atIndex(int i) const;
        int IndexOf(const typename NodeList<T>::Iterator& p) const;
};

template <typename T>
NodeList<T>::Iterator::Iterator(Node* u)
{
    v = u;
}

template <typename T>
T& NodeList<T>::Iterator::operator*()
{
    if (v->next == nullptr) {return v->prev->elem;}
    return v->elem;
}

template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
{
    cout << "Calling pre-increment function" << endl;
    v = v->next;
    return *this; // return reference to updated position
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator++(int)
{
    cout << "Calling post-increment function" << endl;
    Iterator u = *this;
    v = v->next;
    return u;
}

template <typename T>
NodeList<T>::NodeList() : n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
int NodeList<T>::size() const {return n;}

template <typename T>
bool NodeList<T>::empty() const {return n == 0;}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const {return Iterator(header->next);}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const {return Iterator(trailer);}

template <typename T>
void NodeList<T>::insertFront(const T& e) {insert(begin(), e);}

template <typename T>
void NodeList<T>::insertBack(const T& e) {insert(end(), e);}

template <typename T>
void NodeList<T>::insert(const Iterator& p, const T& e)
{
    Node* x = p.v;
    Node* u = x->prev;
    Node* v = new Node;
    v->elem = e;
    v->prev = u;
    v->next = x;
    x->prev = v;
    u->next = v;
    n++;
}

template <typename T>
void NodeList<T>::eraseFront() {erase(begin);}

template <typename T>
void NodeList<T>::eraseBack() {erase(--end());}

template <typename T>
void NodeList<T>::erase(const Iterator& p)
{
    Node* x = p.v;
    Node* u = x->prev;
    Node* v = x->next;
    delete x;
    u->next = v;
    v->prev = u;
    n--;
}

template <typename T>
typename NodeList<T>::Iterator NodeSequence<T>::atIndex(int i) const
{
    typename NodeList<T>::Iterator p;
    if ((i+1) < (NodeSequence<T>::size()-i))
    {
        p = NodeList<T>::begin();
        for (int j=0; j<i; j++)
        {
            ++p;
        }
    }
    else
    {
        p = NodeList<T>::end();
        for (int j=NodeSequence<T>::size(); j!=(NodeSequence<T>::size()-i+1); j--)
        {
            p--;
        }
    }
    return p;
}

template <typename T>
int NodeSequence<T>::IndexOf(const typename NodeList<T>::Iterator& p) const
{
    int i = 0;
    typename NodeList<T>::Iterator q = NodeList<T>::begin();
    while (q != p && q != NodeList<T>::end())
    {
        ++q;
        ++i;
    }
    return i;
}

int main()
{
    NodeList<int> l;
    l.insertBack(4);
    l.insertBack(5);
    l.insertFront(3);
    l.insertFront(2);
    l.insertFront(1);
    NodeList<int>::Iterator p = l.begin();
    cout << "First element: " << *p << endl;
    p = l.end();
    cout << "Last element: " << *p << endl;
    cout << "--- Check pre- and post-increment operator ---" << endl;
    NodeList<int>::Iterator f = l.begin();
    NodeList<int>::Iterator f1 = ++f;
    cout << "Element after pre-increment from begin(): " << *f1 <<endl;
    f = l.begin();
    f1 = f++;
    cout << "Element after post-increment from begin(): " << *f1 <<endl;

    // R 6.14
    NodeSequence<int> l1;
    l1.insertBack(4);
    l1.insertBack(5);
    l1.insertFront(3);
    l1.insertFront(2);
    l1.insertFront(1);
    typename NodeList<int>::Iterator p1 = l1.begin();
    p1++;
    cout << "Index of p1 is: " << l1.IndexOf(p1) << endl;

    return EXIT_SUCCESS;
}