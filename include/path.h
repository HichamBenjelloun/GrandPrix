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

#ifndef __PATH_H
#define __PATH_H

/**
 * @file path.h
 *  
 * Structures and methods for path
 * 
 */

#include <stdio.h>
#include <stdlib.h> 
#include "vertex.h"
#include "list.h"
#include "vect.h"

typedef struct path{
   List *path;
   int length;
} Path;

Path *createEmptyPath(void);
Path *buildPathFromVertex(Vertex *v);

#endif
