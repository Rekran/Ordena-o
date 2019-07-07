#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "heap.h"
#include <fstream>
#include <iostream>
#include <float.h>
#include <math.h>
#include <vector>


class grafo {

	public:
		grafo(char *path);
		void print();
        void Dijkstra(int s);
        heap *fila;

	private:
        vertice *vertices;


		int n_vertices;
        float **arestas;

		void initialize_single_source(int s);
		void relax(int u ,int v);

};

#endif
