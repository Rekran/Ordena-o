#include "grafo.h"
int main(int argc, char** argv) {

    grafo *g10 = new grafo("dij10.txt");
    g10->Dijkstra(0);

    grafo *g20 = new grafo("dij20.txt");
    g20->Dijkstra(0);

    grafo *g40 = new grafo("dij40.txt");
    g40->Dijkstra(0);

    grafo *g50 = new grafo("dij50.txt");
    g50->Dijkstra(0);



	return 0;
}
