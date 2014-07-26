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

#ifndef __PILOT_H
#define __PILOT_H

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
#include "fib.h"

#define MAXSPEED 25

typedef struct pilot{
   Vect *pos;
   Vect *speed;
   
} Pilot;

Pilot *createEmptyPilot(void);
Pilot *createPilot(Vect *,Vect *);
void destroyPilot(Pilot *);

int isValidPosition(Pilot *,Map *);
int isValidMove(Pilot *,Pilot *,Map *);
Pilot *getPilotFromVertex(Vertex *);

Vect **getPositions(FILE *);

int getSpeedIndex(Vect *);
Vect *getSpeedFromIndex(int);

Pilot *createPilotFromVertex(Vertex *);
Vertex *getVertexFromPilot(Graph *,Pilot *);

Vertex *updateNeighborhood(Graph *,Vertex *);

#endif
