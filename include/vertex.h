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

#ifndef __VERTEX_H
#define __VERTEX_H

/**
 * @file vertex.h
 *  
 * Structures and methods for Vertex
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITY INT_MAX

typedef void * Element;

typedef struct vertex{
   Element e;
   int distance;
   struct vertex *previous;
} Vertex;

Vertex *createVertex(Element);
void destroyVertex(Vertex *);

#endif
