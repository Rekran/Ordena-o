#ifndef HEAP_H
#define HEAP_H

#include "vertice.h"
#include <iostream>
#include <math.h>
class grafo;

class heap{

    private:

        int size_h;
        int size_now;
        vertice *heap_bi;
        int *heap_index;
        void min_heapfy(int index);
        void decrease_key(int index);

    public:
        bool is_empyt();
        int remove();
        void print();

        heap(vertice *heap_bi , int size_h);
        heap(){};
        friend class grafo;

};

#endif
