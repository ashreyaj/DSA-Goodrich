#include <iostream>
using namespace std;

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
        int nNodes();
        void display();
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
    if (cursor != nullptr) return cursor->next->elem;
    throw runtime_error("Cannot return front element of empty list.\n");
}

template <typename T>
T& CLL<T>::getBack() const // back element is the cursor
{
    if (cursor != nullptr) return cursor->elem;
    throw runtime_error("Cannot return back element of empty list.\n");
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
    if (cursor != nullptr) 
    {	
        CNode<T>* old = cursor->next;
        if (old != cursor) 
        {	
            cursor->next = old->next;
            delete old;
            return;
        }
        cursor = nullptr;
        delete old;
        return;
    }
    throw runtime_error("Cannot remove element from empty list.\n");
}

template <typename T>
int CLL<T>::nNodes()
{
    int count = 0;
    CNode<T>* head = new CNode<T>;
    head = cursor;
    if (head == nullptr) return count;
    else
    {
        do
        {
            head = head->next;
            count++;
        } while (head != cursor);
    }
    return count;
}

template <typename T>
void CLL<T>::display()
{
    cout << "Songs in the playlist:" << endl;
    CNode<T>* head = new CNode<T>;
    head = cursor;
    if (head == nullptr) cout << "No songs in the playlist.\n";
    else
    {
        do
        {
            cout << head->elem << endl;
            head = head->next;
        } while (head != cursor);
    }
}

int main()
{
    CLL<string> list;
    list.add("Dear Winter");
    list.add("Hey Julie");
    list.add("Englishman in New York");
    list.add("Here Comes the Sun");
    list.remove();
    
    cout << "Number of songs in the playlist is: " << list.nNodes() << endl;
    list.display();

    return 0;
}