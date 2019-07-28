#include "tree.h"

void printbincharpad(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
    putchar('\n');
}

tree::tree(){

   
}


tree::tree(char * filePath){

this->nodes = new node[512];
char buffer;
this->size = 256;

FILE *file_in;
FILE *file_out;

file_in = fopen(filePath,"rb");

while(fread(&buffer,sizeof(char),1,file_in) == 1){

   this->nodes[buffer].frequency += 1;
}

this->heap_t = heap(this->nodes);

while(this->heap_t.getSize() != 1){

    this->size +=1; 

    node *n1 = &nodes[this->heap_t.extractMin()];
    node *n2 = &nodes[this->heap_t.extractMin()];

    (*n1).parent = &nodes[this->size - 1];
    (*n2).parent = &nodes[this->size - 1];

    this->nodes[this->size - 1].frequency = (*n1).frequency + (*n2).frequency;
    this->nodes[this->size - 1].left = n1;
    this->nodes[this->size - 1].right = n2;

    this->heap_t.insertKey(this->size - 1);
}

this->root = &nodes[this->heap_t.extractMin()];
(*this->root).parent = NULL;
    
    for(int i = 0; i < 256; i++){
        if(this->nodes[i].frequency > 0)
        {
            this->code_generetor(i);
        }
    }
fclose(file_in);

char mainBuffer[1024];
    
    file_in = fopen(filePath,"rb");
    file_out = fopen("teste.bin","wb");

    for(int k = 0; k < 256;k++)
        fwrite(&this->nodes[k].frequency,sizeof(int),1,file_out);

int index = 0;
char buffer_char = 0;
int pos = 1;
int total = 0;

while(fread(&buffer,sizeof(char),1,file_in) == 1){
    int i = (BUFFER - this->nodes[buffer].code_bi.size);

    while(i < BUFFER){
    char aux = 0;
        if(this->nodes[buffer].code_bi.bits[i] == 1){
            aux = 1 << (8 - pos);
            pos+= 1;
        }else
        {
            pos += 1;
        }

    buffer_char = buffer_char | aux;
    if(pos == 9){
        mainBuffer[index] = buffer_char;
        pos = 1;
        buffer_char = 0;
        index += 1;

    
        if(index == 1024){
            fwrite(&mainBuffer,sizeof(char),index,file_out);
            index = 0;
    }
    }
    i += 1;
    }
    total += 1;
}
if(index > 0){
    fwrite(&mainBuffer[0],sizeof(char),index,file_out);
}

fclose(file_out);
cout<<total<<endl;
}

void tree::code_generetor(int i){

    node *aux = this->nodes[i].parent;
    node *aux2 = &this->nodes[i];

    while (aux != NULL)
    {
        if( aux->left == aux2){

            this->nodes[i].code_bi.size += 1;
            this->nodes[i].code_bi.bits[BUFFER - this->nodes[i].code_bi.size] = 0;   

        }else{
        
            if(aux->right == aux2){

                this->nodes[i].code_bi.size += 1;
                this->nodes[i].code_bi.bits[BUFFER - this->nodes[i].code_bi.size] = 1;  
            }
        }

        aux2 = aux;
        aux = aux2->parent;

    }
        

}


void tree::print(){
    
    for(int i = 0; i < 256 ; i++){
        if(this->nodes[i].frequency > 0){
            for(int j = (BUFFER - this->nodes[i].code_bi.size) ; j < BUFFER; j++){
                cout<<this->nodes[i].code_bi.bits[j]<<" ";
            }
            cout<<endl;
        }

    }
    
}