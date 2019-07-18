#ifndef _NODE_H_
#define _NODE_H_
#define BUFFER 50

#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include <fstream>
using namespace std;


struct code{

    int bits[BUFFER];
    int size;


};
struct node{

        code code_bi;
        node *parent;
        node *left;
        node *right;
        int index_heap;
        int frequency;
        bool leaves;
        char code_char;

};

#endif