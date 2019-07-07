#include "heap.h"

heap::heap(vertice *heap_bi, int size_h):size_h(size_h),size_now(size_h)
{
    this->heap_index = new int[size_h];
    this->heap_bi = heap_bi;

    for(int i = 0; i < this->size_h; i++ )
        this->heap_index[i] = i;

    for(int i = (this->size_h-1)/2; i >= 0; i-- )
        min_heapfy(this->heap_bi[this->heap_index[i]].index_heap);

}
void heap::print()
{

    for(int i = 0;i < this->size_now; i++){
        std::cout<<this->heap_index[i] <<" "<<this->heap_bi[this->heap_index[i]].distacia_s<<" "<<this->heap_bi[this->heap_index[i]].index_heap<<endl;

    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

}

void heap::min_heapfy(int index)
{
    int left , right;
    int menor ;

        left  = 2*index+1;
        right = 2*index+2;

    if((left < size_now) && (this->heap_bi[this->heap_index[left]].distacia_s < this->heap_bi[this->heap_index[index]].distacia_s))
        menor = left;
    else
        menor = index;

    if((right < size_now) && (this->heap_bi[this->heap_index[right]].distacia_s < this->heap_bi[this->heap_index[menor]].distacia_s))
        menor = right;

    if(menor != index){

        int aux = this->heap_index[index];
        this->heap_index[index] = this->heap_index[menor];
        this->heap_index[menor] = aux;

        this->heap_bi[heap_index[menor]].index_heap = menor;
        this->heap_bi[heap_index[index]].index_heap = index;

        min_heapfy(menor);

    }

}


int heap::remove()
{
    int index = this->heap_bi[heap_index[0]].index;

    this->heap_index[0] = this->heap_index[this->size_now - 1];

    this->heap_bi[heap_index[0]].index_heap = 0;


    this->size_now = this->size_now - 1;

    this->min_heapfy(0);

    return index;

}

void heap::decrease_key(int index){

    int Pai = (index - 1)/2;

    if(this->heap_bi[this->heap_index[index]].distacia_s < this->heap_bi[this->heap_index[Pai]].distacia_s){

        this->heap_bi[this->heap_index[index]].index_heap = Pai;
        this->heap_bi[this->heap_index[Pai]].index;

        int aux = this->heap_index[Pai];
        this->heap_index[Pai] = this->heap_index[index];
        this->heap_index[index] = aux;

        if(Pai != 0)
            this->decrease_key(Pai);

    }
}



bool heap::is_empyt()
{

    return (this->size_now == 0);

}
