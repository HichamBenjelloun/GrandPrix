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

#include "io.h"

void send(Vect *a)
{
   fprintf(stdout, "%d %d\n", a->y, a->x);
   fflush(stdout);
}

Vertex *createVertexFromPosition(Vect *v,Vect *speed, int boost)
{
   Vertex *nv=createVertex(createVect4D(v->x,v->y,getSpeedIndex(speed),boost));
   return nv;
}

Vect *getNextAcceleration(Vertex *current,Path *p)
{
   return vectDiff(getPilotFromVertex(pop(p->path))->speed,getPilotFromVertex(current)->speed);
}

void updatePlayers(Map *m,Vect **pos)
{
   m->players[0]=pos[1];
   m->players[1]=pos[2];
}

int isValidPath(Path *p,Map *m)
{
   if(p)
      {
	 Vertex *a=pop(p->path);
	 int temp= ( (((Vect4D *)a->e)->x==m->players[0]->x && ((Vect4D *)a->e)->y==m->players[0]->y) ||
		     (((Vect4D *)a->e)->x==m->players[1]->x && ((Vect4D *)a->e)->y==m->players[1]->y)
		     );
	 push(p->path,a);
	 return !temp;
      }
   return 0;
}

void play(FILE *in)
{
   Vertex *currentPosition;
   Graph *g;
   Vect **positions;
   Vect *myPosition,*myPreviousPosition=NULL;
   Vect *nextAcc;
   Path *path=NULL;
   Vect *speed;

   Vect *dummy=createVect(0,0);

   int remainingBoosts=2;

   g=createGraphFromMap(getMapFromStream(in));
   speed=createVect(0,0);

   char t1,t2;
   int wait;

   while(1)
      {
	 positions=getPositions(in);
	 myPosition=positions[0];
	 speed=myPreviousPosition?vectDiff(myPosition,myPreviousPosition):dummy;
	 currentPosition=createVertexFromPosition(myPosition,speed,remainingBoosts);

	 updatePlayers(g->field,positions);

	 if(((Vect4D *)currentPosition->e)->z == 40 || !isValidPath(path,g->field))
	    {
	       path=buildPathFromVertex(dijkstra(g,currentPosition));
	       if(!isValidPath(path,g->field))
		  {
		     path=NULL;
		     myPreviousPosition=NULL;
		     speed=dummy;
  		     send(dummy);
		     
		     srand(time(NULL));
		     wait=1+rand()%5;
		     while(wait--)
			{
			   fflush(stdin);
			   send(dummy);
			}

		     continue;
		  }
	    }	 

	 nextAcc=getNextAcceleration(currentPosition,path);
	 if(nextAcc->x==-2 || nextAcc->x==2) remainingBoosts--;
      
	 send(nextAcc);

	 myPreviousPosition=myPosition;
      }
}
