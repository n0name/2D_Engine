#include "dlist.h"

#include <stdlib.h>
#include <string.h>

dList::dList()
{
    this->root = (node *)malloc(sizeof(node));

}

dList::~dList()
{
    node *curNode = this->root;
    while (curNode->nextNode)
    {
        free(curNode->data);

    }
}


