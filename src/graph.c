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
 * @file graph.c
 *  
 */

#include "graph.h"

Graph *createEmptyGraph(void)
{
   Graph *g=(Graph *)malloc(sizeof(Graph));
   g->heap=fh_makekeyheap();
   
   return g;
}

Vertex *getVertexFromVect4D(Graph *g,Vect4D *v)
{
   return g->vertices[v->x][v->y][v->z][v->b]; 
}

Graph *createGraphFromMap(Map *m)
{
   int i,j,k,b;
   Graph *g=createEmptyGraph();
   g->field=m;
   
   g->vertices=(Vertex *****)calloc(g->field->w,sizeof(Vertex ****));
   for(i=0;i<g->field->w;i++)
      {
	 g->vertices[i]=(Vertex ****)calloc(g->field->h,sizeof(Vertex ***));
      }

   for(i=0;i<g->field->w;i++)
      {
	 for(j=0;j<g->field->h;j++)
	    {
	       if(g->field->cell[i][j]!='.')
		  {
		     g->vertices[i][j]=(Vertex ***)calloc(SPEEDCARD,sizeof(Vertex **));
		     for(k=0;k<SPEEDCARD;k++)
			{
			   g->vertices[i][j][k]=(Vertex **)calloc(BOOSTCARD,sizeof(Vertex *));
			   for(b=0;b<3;b++)
			      {
				 g->vertices[i][j][k][b]=createVertex(createVect4D(i,j,k,b));
			      }
			}
		  }
	    }
      }
   return g;
}

Graph *refreshGraph(Graph *g)
{
   int i,j,k,b;

   g->field->searchLevel=0;

   for(i=0;i<g->field->w;i++)
      {
	 for(j=0;j<g->field->h;j++)
	    {
	       if(g->field->cell[i][j]!='.')
		  {
		     for(k=0;k<SPEEDCARD;k++)
			{
			   for(b=0;b<3;b++)
			      {
				 g->vertices[i][j][k][b]->distance=INFINITY;
			      }
			}
		  }
	    }
      }
   return g;
}

void destroyGraph(Graph *g)
{
   int i,j,k,b;
   for(i=0;i<g->field->w;i++)
      {
	 for(j=0;j<g->field->h;j++)
	    {
	       if(g->vertices[i][j])
		  {
		     for(k=0;k<SPEEDCARD;k++)
			{
			   for(b=0;b<3;b++)
			      {
				 free(g->vertices[i][j][k][b]);
			      }
			   free(g->vertices[i][j][k]);
			}
		  }
	       free(g->vertices[i][j]);
	    }
	 free(g->vertices[i]);
      }
   free(g->vertices);
   destroyMap(g->field);
}
