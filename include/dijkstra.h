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

#ifndef __DIJKSTRA_H
#define __DIJKSTRA_H

/**
 * @file dijkstra.h
 *  
 * Structures and methods for a Map
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "map.h"
#include "vertex.h"
#include "pilot.h"
#include "graph.h"
#include "fib.h"

#define MAX_PATH_LENGTH 200

Vertex *dijkstra(Graph *,Vertex *);

#endif
