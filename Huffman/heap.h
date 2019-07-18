#ifndef _HEAP_H_
#define _HEAP_H_
#include "node.h"


class heap
{
    private:
        int *heap_index;
        node *leaves;
        
        int size;        

    public:
        int extractMin();
        void minHeapfy(int i);
        void minHeapfy_up(int i);
        void insertKey(int key);
        int getSize();
        
        heap(node * heap_bi);
        heap(){};
};


#endif