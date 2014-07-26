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

#ifndef __IO_H
#define __IO_H

/**
 * @file pilot.h
 *  
 */

#include <stdio.h>
#include <stdlib.h> 
#include "vect.h"
#include "map.h"
#include "vertex.h"
#include "graph.h"
#include "list.h"
#include "path.h"
#include "pilot.h"
#include "dijkstra.h"

void send(Vect *a);

Vertex *createVertexFromPosition(Vect *,Vect *,int);

Vect *getNextAcceleration(Vertex *,Path *);

int isValidPath(Path *,Map *);

void play(FILE *);



#endif
