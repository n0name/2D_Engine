#ifndef DLIST_H
#define DLIST_H
#include <stdlib.h>

template <typename T>
class double_linked
{
    struct node
    {
        T data;
        node* prev;
        node* next;
        node(T t, node* p, node* n) : data(t), prev(p), next(n) {}
    };
    node* head;
    node* tail;
public:
    double_linked()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    template<int N>
    double_linked( T (&arr) [N]) : head( NULL ), tail ( NULL )
    {
        for( int i(0); i != N; ++i)
            push_back(arr[i]);
    }

    bool empty() const { return ( !head || !tail ); }
    operator bool() const { return !empty(); }
    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();
    T get_next();
    T get_head();


    ~double_linked()
    {
        while(head)
        {
            node* temp(head);
            head=head->next;
            delete temp;
        }
    }
};
#endif // DLIST_H
