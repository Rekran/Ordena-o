#include "heap.h"

heap::heap(node * heap_bi){
    this->leaves = heap_bi;
    this->heap_index = new int[256];
    this->size = 0;

    for(int i = 0; i < 256; i++){

        if(this->leaves[i].frequency != 0)
        this->insertKey(i);
    }

}
void heap::minHeapfy(int index)
{
    int left , right;
    int menor ;

        left  = 2*index+1;
        right = 2*index+2;

    if((left < size) && (this->leaves[this->heap_index[left]].frequency < this->leaves[this->heap_index[index]].frequency))
        menor = left;
    else
        menor = index;

    if((right < size) && (this->leaves[this->heap_index[right]].frequency < this->leaves[this->heap_index[menor]].frequency))
        menor = right;

    if(menor != index){

        int aux = this->heap_index[index];
        this->heap_index[index] = this->heap_index[menor];
        this->heap_index[menor] = aux;

        this->leaves[heap_index[menor]].index_heap = menor;
        this->leaves[heap_index[index]].index_heap = index;

        this->minHeapfy(menor);

    }

}

int heap::extractMin(){

    int index = this->heap_index[0];
    
    this->heap_index[0] = this->heap_index[this->size - 1];

    this->leaves[heap_index[0]].index_heap = 0;


    this->size = this->size - 1;

    this->minHeapfy(0);

    return index;

}

void heap::minHeapfy_up(int i){
    int pai = (i - 1)/2;
    if(this->leaves[this->heap_index[pai]].frequency > this->leaves[this->heap_index[i]].frequency){
        int index = this->heap_index[i]; 
        this->heap_index[i]  = this->heap_index[pai];
        this->heap_index[pai] = index;
        
        this->leaves[this->heap_index[i]].index_heap = i;
        this->leaves[this->heap_index[pai]].index_heap = pai;
        
        if(pai != 0)
            this->minHeapfy_up(pai);   
    }
} 

void heap::insertKey(int key){
    this->size += 1;
    this->heap_index[this->size - 1] = key;
    this->leaves[key].index_heap = this->size - 1; 

    this->minHeapfy_up(this->size - 1);

}

int heap::getSize(){
    return this->size;
}
