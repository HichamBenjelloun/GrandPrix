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
 * @file dijkstra.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "dijkstra.h"


Vertex *dijkstra(Graph *g,Vertex *start)
{
   Vertex *u,*end;

   u=NULL;
   end=NULL;

   refreshGraph(g);

   start->distance=0;
   fh_insertkey(g->heap,0,start);

   do
      {
	 u=fh_extractmin(g->heap);
	 if(u)
	    {
	       g->field->searchLevel=u->distance;

	       /* if path too long (ie not found), searches another path */
	       if(u->distance>=MAX_PATH_LENGTH)
		  {
		     continue;
		  }
	    }
	 else
	    {
	       return NULL;
	    }

	 end=updateNeighborhood(g,u);
      } while(end==NULL);

   return end; 
}
