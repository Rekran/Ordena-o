#include "grafo.h"

grafo::grafo(char *path){

	ifstream grafo_file;
	grafo_file.open (path);

	grafo_file >> this->n_vertices;

	this->arestas = new float*[this->n_vertices];

	for(int i = 0 ; i < this->n_vertices; i++)
		this->arestas[i] = new float[this->n_vertices];


	this->vertices = new vertice[this->n_vertices];


	for(int i = 0 ; i < this->n_vertices ; i++){
		for(int j = i; j < this->n_vertices; j++){
		    if(i == j){
                this->arestas[i][j] = 0;
		    }
		    else{
                float peso;
                grafo_file >> peso;
                this->arestas[i][j] = peso;
                this->arestas[j][i] = peso;
		    }
		}
	}
}


void grafo::initialize_single_source(int s){


	for (int i = 0;i < this->n_vertices;i++){
		this->vertices[i].distacia_s = FLT_MAX;
		this->vertices[i].pai = -1;
		this->vertices[i].index = i;
		this->vertices[i].index_heap = i;
		this->vertices[i].processed = false;

	}

	this->vertices[s].distacia_s = 0;

	this->fila = new heap(this->vertices,this->n_vertices);
}

void grafo::relax(int u ,int v){


	if (this->vertices[v].distacia_s > (this->vertices[u].distacia_s + this->arestas[u][v])){

		this->vertices[v].distacia_s =  this->vertices[u].distacia_s+ this->arestas[u][v];

		this->fila->decrease_key(this->vertices[v].index_heap);

		this->vertices[v].pai = u;
	}

}

void grafo::Dijkstra(int s){

    this->initialize_single_source(s);

    while(!this->fila->is_empyt()){

        int index = this->fila->remove();

        for(int i = 0 ; i < this->n_vertices; i++){

            if(this->arestas[index][i] != 0 ){

                this->relax(index,i);

            }

        }



        this->vertices[index].processed = true;


    }
vector <int> caminho;

int pai = this->vertices[this->n_vertices - 1].pai;
caminho.push_back(this->n_vertices - 1);

if(pai == -1)
    caminho.push_back(pai);

while(pai != -1){

caminho.push_back(pai);

pai = this->vertices[pai].pai;
}

for(int i = caminho.size() - 1; i > 0; i-- )
    cout<<caminho[i]<<" --> ";

cout<<caminho[0]<<" Distancia = "<<this->vertices[this->n_vertices-1].distacia_s<<endl<<endl;
}


void grafo::print(){

	for(int i = 0 ; i < this->n_vertices ; i++){

        cout << this->vertices[i].index<<" "<< this->vertices[i].distacia_s<<" Pai->"<<this->vertices[i].pai<<endl;

	}
}
