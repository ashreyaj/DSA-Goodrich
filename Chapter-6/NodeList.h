#ifndef NODELIST_H
#define NODELIST_H

template <typename T>
class NodeList
{
    private:
        struct Node;
        int n;
        Node* header;
        Node* trailer;
    public:
        NodeList();
        class Iterator;
        int size() const;
        bool empty() const;
        Iterator begin() const;
        Iterator end() const;
        void insertFront(const T& e); 
        void insertBack(const T& e); 
        void insert(const Iterator& p, const T& e); 
        void eraseFront(); 
        void eraseBack(); 
        void erase(const Iterator& p);
};

#endif