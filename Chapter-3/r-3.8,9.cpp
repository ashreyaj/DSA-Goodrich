#include <iostream>
using namespace std;

// r-3.9
class Exception 
{
    private:
        string msg;
    public:
        Exception(const string& err) : msg(err) {};
        string getError() {return this->msg;}
};

template <typename T>
class DLL;

template <typename T>
class DNode
{
    private:
        T elem;
        DNode<T>* next;
        DNode<T>* prev;
        friend class DLL<T>;
};

template <typename T>
class DLL
{
    private:
        DNode<T>* header;
        DNode<T>* trailer;
    public:
        DLL();
        ~DLL();
        bool isEmpty() const;
        DNode<T>* getFront() const;
        DNode<T>* getBack() const;
        void add(const T& e, DNode<T>* u);
        void addFront(const T& e);
        void addBack(const T& e);
        void remove(DNode<T>* x);
        void removeFront();
        void removeBack();
        T& middle();
};

template <typename T>
DLL<T>::DLL() 
{
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
}

template <typename T>
DLL<T>::~DLL()
{
    while (!isEmpty())
    {
        removeBack();
    }
    delete header;
    delete trailer;
}

template <typename T>
bool DLL<T>::isEmpty() const
{
    return (header->next == trailer);
}

template <typename T> 
DNode<T>* DLL<T>::getFront() const
{
    return header->next;
}

template <typename T> 
DNode<T>* DLL<T>::getBack() const
{
    return trailer->prev;
}

template <typename T>
void DLL<T>::add(const T& e, DNode<T>* u)
{
    DNode<T>* v = u->next;
    DNode<T>* x = new DNode<T>;
    u->next = x;
    v->prev = x;
    x->elem = e;
    x->next = v;
    x->prev = u;
}

template <typename T> 
void DLL<T>::addFront(const T& e)
{
    add(e, header);
}

template <typename T> 
void DLL<T>::addBack(const T& e)
{
    add(e, getBack());
}

template <typename T>
void DLL<T>::remove(DNode<T>* x)
{
    DNode<T>* u = x->prev;
    DNode<T>* v = x->next;
    u->next = v;
    v->prev = u;
    delete x;
}

template <typename T>
void DLL<T>::removeFront()
{
    try
    {
        if (header->next != trailer)
        {
            remove(header->next);
        }
        throw Exception("Cannot remove front node from empty list.\n");
    }
    catch(Exception& err)
    {
        cerr << err.getError();
    }
}

template <typename T>
void DLL<T>::removeBack()
{
    try
    {
        if (header->next != trailer)
        {
            remove(trailer->prev);
        }
        throw Exception("Cannot remove back node from empty list.\n");
    }
    catch(Exception& err)
    {
        cerr << err.getError();
    }
}
 
 // r-3.10
template <typename T>
T& DLL<T>::middle()
{
	try 
    {
		if (!isEmpty()) 
        {
			DNode<T>* walker = header;
			DNode<T>* jumper = header;
			while (jumper->next != nullptr) 
            {
				walker = walker->next;
				jumper = jumper->next->next;
            }
        return walker->elem;
        }
		throw Exception("Cannot find middle element of empty list.");
	}
	catch(Exception& err) 
    {
		cerr << err.getError();
	}
}

int main()
{
    DLL<int> d;
    d.addFront(45);
    d.addFront(65);
    d.addFront(13);
    d.addFront(23);
    d.addFront(98);
    cout << "Middle element is: " << d.middle() << endl;

    DLL<int> d2;
    d2.removeFront();
    
    return 0;
}