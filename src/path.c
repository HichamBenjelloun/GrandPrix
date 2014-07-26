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
 * @file path.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "path.h"

Path *createEmptyPath(void)
{
   Path *p=(Path *)malloc(sizeof(Path));
   p->path=createEmptyList();
   p->length=0;

   return p;
}

Path *buildPathFromVertex(Vertex *v)
{
   if(v)
      {
	 Path *p=createEmptyPath();
	 Vertex *current=v;
	 
	 while(current && current->previous)
	    {
	       push(p->path,current);
	       p->length++;
	       current=current->previous;
	    }
	 return p;
      }
   
   return NULL;
}
