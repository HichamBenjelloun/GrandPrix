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
 * @version     1.0 - Fev 08, 2013
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file vertex.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "vertex.h"

Vertex *createVertex(Element e)
{
   Vertex *newVertex = (Vertex *)calloc(1,sizeof(Vertex));
   newVertex->e=e;
   newVertex->distance=INFINITY;
   newVertex->previous=NULL;
   
   return newVertex;
}

void destroyVertex(Vertex *v)
{
   free(v);
}


