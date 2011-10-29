#ifndef DLIST_H
#define DLIST_H


typedef struct node
{
    node *nextNode;
    node *prvNode;
    void *data;
}node;


template <class T>
class dList
{
public:
    dList();
    ~dList();
    void push(T element);
    T pop();

private:
    node *root;
};

#endif // DLIST_H
