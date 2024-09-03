#include <iostream>
using namespace std;

class Exception 
{
    private:
        string msg;
    public:
        Exception(const string& err) : msg(err) {};
        string getError() {return this->msg;}
};

template <typename T>
class CLL;

template <typename T>
class CNode
{
    private:
        T elem;
        CNode<T>* next;
        friend class CLL<T>;
};

template <typename T>
class CLL
{
    private:
        CNode<T>* cursor;
    public:
        CLL();
        ~CLL();
        bool isEmpty() const;
        T& getFront() const;
        T& getBack() const;
        void advance();
        void add(const T& e);
        void remove();
};

template <typename T>
CLL<T>::CLL() : cursor(nullptr) {};

template <typename T>
CLL<T>::~CLL()
{
    while (!isEmpty()) remove();
}

template <typename T>
bool CLL<T>::isEmpty() const
{
    return cursor == nullptr;
}

template <typename T>
T& CLL<T>::getFront() const // front element is element following cursor
{
    return cursor->next->elem;
}

template <typename T>
T& CLL<T>::getBack() const
{
    return cursor->elem; // back element is element at cursor
}

template <typename T>
void CLL<T>::advance()
{
    cursor = cursor->next;
}

template <typename T>
void CLL<T>::add(const T& e) // add element after cursor
{
    CNode<T>* n = new CNode<T>;
    if (cursor != nullptr)
    {
        CNode<T>* old = cursor->next;
        cursor->next = n;
        n->next = old;
    }
    else
    {
        cursor = n;
        n->next = n;
    }
    n->elem = e;
}

template <typename T>
void CLL<T>::remove() // remove element after cursor
{
    CNode<T>* old = cursor->next;
    if (cursor == old)
    {
        cursor = nullptr;
    }
    else
    {
        cursor->next = old->next;
    }
    delete old;
}

int main()
{
    CLL<string> list;
    list.add("Dear Winter");
    list.add("Hey Julie");
    list.add("Englishman in New York");
    list.add("Here Comes the Sun");
    list.remove();
    
    return 0;
}