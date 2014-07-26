/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Hicham Benjelloun <benjelloun@ecole.ensicaen.fr> 
 * @version     1.0 - Apr 24, 2013
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

#ifndef __GRAPH_H
#define __GRAPH_H

/**
 * @file graph.h
 *  
 * Structures and methods for Vertex
 * 
 */

#include <stdio.h>
#include <stdlib.h> 
#include "list.h"
#include "vertex.h"
#include "map.h"
#include "vect.h"
#include "fib.h"

#define SPEEDCARD 81
#define BOOSTCARD 3

typedef struct graph{
   Map *field;
   Vertex *****vertices;
   struct fibheap *heap;

} Graph;

/* Methods */
Graph *createEmptyGraph(void);
Graph *createGraphFromMap(Map *);
Graph *refreshGraph(Graph *);
Vertex *getVertexFromVect4D(Graph *,Vect4D *);
void destroyGraph(Graph *);

#endif
