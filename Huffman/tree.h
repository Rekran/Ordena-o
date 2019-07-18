#ifndef _TREE_H_
#define _TREE_H_

#include "node.h"
#include "heap.h"


class tree
{
public:
    tree();
    void decode(char * filePath);
    tree(char * filePath);
    heap heap_t;
    int size;
    node *nodes;
    node *root;
    void print();
    void code_generetor(int i);

};


#endif