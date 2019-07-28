#include "decoder.h"

decoder::decoder(char * filePath){
    this->freqTotal = 0;
    this->mytree.nodes = new node[512];
    this->mytree.size = 256;
    FILE * file_in;
    file_in = fopen(filePath,"rb");
    int freq;
    
    for(int i = 0; i < 256 ; i++){
        
        fread(&freq,sizeof(int),1,file_in);
        this->mytree.nodes[i].frequency = freq;
        this->mytree.nodes[i].leaves = true;
        this->mytree.nodes[i].code_char = i;
        this->freqTotal +=  this->mytree.nodes[i].frequency;
    }

    
    this->mytree.heap_t = heap(this->mytree.nodes);

    while(this->mytree.heap_t.getSize() != 1){

    this->mytree.size +=1; 

    node *n1 = &this->mytree.nodes[this->mytree.heap_t.extractMin()];
    node *n2 = &this->mytree.nodes[this->mytree.heap_t.extractMin()];

    (*n1).parent = &this->mytree.nodes[this->mytree.size - 1];
    (*n2).parent = &this->mytree.nodes[this->mytree.size - 1];

    this->mytree.nodes[this->mytree.size - 1].frequency = (*n1).frequency + (*n2).frequency;
    this->mytree.nodes[this->mytree.size - 1].left = n1;
    this->mytree.nodes[this->mytree.size - 1].right = n2;

    this->mytree.heap_t.insertKey(this->mytree.size - 1);
}

this->mytree.root = &mytree.nodes[this->mytree.heap_t.extractMin()];
(*this->mytree.root).parent = NULL;
    
 FILE * file_out;
 file_out = fopen("fib25","wb");

 int buffer[8];
 char byte;
 char mainBuffer[1024];
 int index = 0;
 node *aux = this->mytree.root;
 int total = 0;
while (fread(&byte,sizeof(char),1,file_in) == 1)
{

     for (int i = 7; i >= 0; i--)
     {
         (byte & (1 << i)) ? buffer[8 - (i+1)] = 1 : buffer[8 - (i+1)] = 0;
     }

     for (int i = 0; i < 8; i++)
    {
        if(buffer[i] == 0){
            aux = aux->left;
        }else
        {        
            aux = aux->right;
        }

        if(aux->leaves){
            mainBuffer[index] = aux->code_char;
            aux = this->mytree.root;
            index += 1;
            total+=1;

            if(index == 1024){
                fwrite(&mainBuffer,sizeof(char),index,file_out);
                index = 0;
            }
        }
    }

}

if(index > 0)
    fwrite(&mainBuffer,sizeof(char),index,file_out);

fclose(file_in);
fclose(file_out);
cout<<total<<" "<<this->freqTotal<<endl;
}