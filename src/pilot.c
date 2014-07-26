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
 * @file pilot.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "pilot.h"


Pilot *createEmptyPilot(void)
{
   Pilot *np=(Pilot *)calloc(1,sizeof(Pilot));
   return np;
}

Pilot *createPilot(Vect *pos,Vect *speed)
{
   Pilot *np=createEmptyPilot();
   np->pos=pos;
   np->speed=speed;

   return np;
}

void destroyPilot(Pilot *p)
{
   free(p->pos);
   free(p->speed);
   free(p);
}


int isValidPosition(Pilot *p,Map *m)
{
  
   if(p->pos->x >= m->w ||
      p->pos->y >= m->h ||
      p->pos->x < 0 ||
      p->pos->y < 0
      ) return 0;
   
   if(vectNorm(p->speed)>MAXSPEED) return 0;
   
   if(m->searchLevel==0 && ( (equalVect(p->pos,m->players[0]) || equalVect(p->pos,m->players[1])) ) )
      {
	 return 0;
      }

   switch(m->cell[p->pos->x][p->pos->y])
      {
      case '.':
	 return 0; 
	 break;
      case '~':
	 if(vectNorm(p->speed)>1) return 0;
	 break;
      case '=':
	 if(equalVect(p->pos,m->players[0]) || equalVect(p->pos,m->players[1])) return 0;
	 break;
      }

   return 1;
}


int isValidMove(Pilot *p,Pilot *np,Map *m)
{
   if(!isValidPosition(np,m)) return 0;
   if(m->cell[p->pos->x][p->pos->y]=='~' && vectNorm(np->speed)>1) return 0;
   return 1;
}


Pilot *getPilotFromVertex(Vertex *v)
{
   Vect *speed=getSpeedFromIndex(((Vect4D *)v->e)->z);
   if(speed)
      {
	 return createPilot(createVect(((Vect4D *)v->e)->x,((Vect4D *)v->e)->y),speed);
      }
   else
      {
	 perror("Vitesse (NULL)");
      }
}

Vect **getPositions(FILE *f)
{
   char c;
   int i;
   Vect **pos=(Vect **)calloc(3,sizeof(Vect *));
   for(i=0;i<3;i++)
      {
	 pos[i]=(Vect *)malloc(sizeof(Vect));
      }
   
   fscanf(f,"%d %d\t%d %d\t%d %d",
	  &pos[0]->y,
	  &pos[0]->x,
	  &pos[1]->y,
	  &pos[1]->x,
	  &pos[2]->y,
	  &pos[2]->x
	  );
   return pos;
}

int getSpeedIndex(Vect *v)
{
   int i,j;
   int k=0;
   for(i=-5;i<=5;i++)
      {
	 for(j=-5;j<=5;j++)
	    {
	       if(i*i+j*j<=25)
		  {
		     if(v->x==i && v->y==j) return k;
		     k++;
		  }
	    }
      }
   return -1;
}

Vect *getSpeedFromIndex(int index)
{
   int i,j;
   int k=0;
   for(i=-5;i<=5;i++)
      {
	 for(j=-5;j<=5;j++)
	    {
	       if(i*i+j*j<=25)
		  {
		     if(k==index) return createVect(i,j);
		     k++;
		  }
	    }
      }
   return NULL;
}

Vertex *getVertexFromPilot(Graph *g,Pilot *p)
{
   return g->vertices[p->pos->x][p->pos->y][getSpeedIndex(p->speed)][2]; 
}

Pilot *createPilotFromVertex(Vertex *u)
{
   Pilot *p=createEmptyPilot();
   Vect4D *v=u->e;
   p->pos=createVect(v->x,v->y);
   p->speed=getSpeedFromIndex(v->z);

   return p;
}


Vertex *updateNeighborhood(Graph *g,Vertex *u)
{
   int i,j;
   Vertex *v;
   Pilot *np, *p;
   Vect *nextAcc;
   int boost=((Vect4D *)u->e)->b;
   int l=boost>0?2:1;

   p=createPilotFromVertex(u);

   for(i=-l;i<=l;i++)
      {
	 for(j=-l;j<=l;j++)
	    {  
	       np=createEmptyPilot();
	       nextAcc=createVect(i,j); 
	       np->speed=vectSum(p->speed,nextAcc); 
	       np->pos=vectSum(p->pos,np->speed);
		     
	       if(isValidMove(p,np,g->field))
		  {
		     boost=(i==-2||i==2||j==-2||j==2)?((Vect4D *)u->e)->b-1:((Vect4D *)u->e)->b;
		     
		     v=g->vertices[np->pos->x][np->pos->y][getSpeedIndex(np->speed)][boost];
		     
		     if(v->distance>u->distance+1)
			{
			   v->previous=u;
			   v->distance=u->distance+1;
			   fh_insertkey(g->heap,v->distance,v);
			}

		     if(g->field->cell[np->pos->x][np->pos->y]=='=')
			{
			   return v;
			}
		  }
	       else 
		  {
		     destroyPilot(np);
		     destroyVect(nextAcc);
		     continue;
		  }

	       destroyVect(nextAcc);
	    }
      }

   return NULL;
}
