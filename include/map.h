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

#ifndef __MAP_H
#define __MAP_H

/**
 * @file map.h
 *  
 * Structures and methods for a Map
 */

#include <stdio.h>
#include <stdlib.h>
#include "vect.h"
#include "vertex.h"
#include "list.h"

/* Structures */
typedef struct map{
   int h,w;
   char **cell;
   Vect **players;
   int searchLevel;

} Map;

/* Methods */
char **createEmptyMatrix(int,int);

void destroyMatrix(int **,int,int);

Map *createEmptyMap(int,int);

void destroyMap(Map *);

Map *getMapFromStream(FILE *);

void displayMap(Map *);

#endif
