//lecture 12
#include<iostream>
using namespace std;
template<class T>
class DLL;

template <class T>
class Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(const T& newdata = T(), Node<T>* newnext = nullptr, Node<T>* newprev = nullptr) : data(newdata), next(newnext), prev(newprev) {}
    friend class DLL<T>;
};
class EmptyListErr{};
template<class T>
class Itr{
        Node<T>* ptr;
    public:
        Itr(Node<T>* newptr = nullptr):ptr(newptr){}
        T& operator*() {return ptr->data;}
        T operator*() const {return ptr->data;}
        Itr operator++(int);
        Itr operator++();
        Itr operator--(int);
        Itr& operator--();
        bool operator==(const DLL<T>::Itr& self){return ptr == self.ptr;}
        bool operator!=(const DLL<T>::Itr& self){return ptr != self.ptr;}
    };
template<class T>
class DLL {
    Node<T>* head;
    Node<T>* tail;
    int sz;
public:
    Itr begin() {return head->next;}
    Itr end() {return tail;}
    DLL();
    virtual ~DLL();
    DLL& operator=(const DLL<T>& self);
    DLL(const DLL<T>& self);
    int size() const {return size;}
    bool isEmpty() const { return sz == 0; }
    void clear();
    void push_front(const T& newdata);
    void push_back(const T& newdata);
    T pop_front(){if (!isEmpty()) removeNode(head->next); else throw EmptyListErr();}
    T pop_back(){if (!isEmpty()) removeNode(tail->prev); else throw EmptyListErr;}
    void insertAfter(const T& newdata Itr<T> ptr);
    T removeNode(Itr itr);
};

template<class T>
DLL<T>::Itr DLL<T>::Itr::operator--(){
    if (ptr->prev != nullptr)
        ptr = ptr->prev;
    return *this;
}

template<class T> 
DLL<T>::Itr DLL<T>::Itr::operator--(int){
    DLL<T>::Itr temp = *this;
    if (ptr->next != nullptr)
        ptr = ptr->prev;
    return temp;
}
template<class T>
DLL<T>::Itr DLL<T>::Itr::operator++(){
    if (ptr->prev != nullptr)
        ptr = ptr->next;
    return *this;
}

template<class T> 
DLL<T>::Itr DLL<T>::Itr::operator++(int){
    DLL<T>::Itr temp = *this;
    if (ptr->next != nullptr)
        ptr = ptr->next;
    return temp;
}
template<class T>
T DLL<T>::removeNode(Itr itr){
    Node<T>* temp = itr.ptr;
    T data = temp->data;
    size--;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    return data;
}
template<class T>
void DLL<T>::insertAfter(const T& newdata, DLL<T>::Itr itr){
    Node<T>* temp = itr.ptr;
    sz++;
    temp->next = new Node<T>(newdata,temp->next, temp);
    temp->next->next->prev = temp->next;
}
template<class T>
DLL& DLL<T>::operator=(const DLL<T>& self){
    if (this == &self)
        return this;
    clear();
    for (Node<T>* temp = self.head->next; temp != self.tail; temp = temp->next)
        push_back(temp->data);
    return *this;
}
template<class T> 
void DLL<T>::push_front(const T& newdata){
    insertAfter(newdata,head);
}
template<class T>
void DLL<T>::push_back(const T& newdata){
    insertAfter(newdata,tail->prev);
}
template<class T>
void DLL<T>::clear(){
    while (!isEmpty())
        removeNode(head->next);
}
template<class T>
DLL<T>::DLL(const DLL<T>& self){
    sz = 0;
    head = new Node<T>(T(), new Node<T>);
    tail = head->next;
    tail->prev = head;
    *this = self;
}
template <class T>
DLL<T>::DLL(){
    sz = 0;
    head = new Node<T>(T(),new Node<T>); // creates the dummy nodes
    tail = head->next;
    tail-> prev = head;
}
template <class T>
DLL<T>::~DLL(){
    clear();
    delete head;
    delete tail;
}

int main(){
        
}
