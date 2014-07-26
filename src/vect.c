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
 * @file vect.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "vect.h"

Vect *createVect(int x,int y)
{
   Vect *newVect=(Vect *)calloc(1,sizeof(Vect));
   newVect->x=x;
   newVect->y=y;

   return newVect;
}

Vect4D *createVect4D(int x,int y,int z,int b)
{
   Vect4D *newVect=(Vect4D *)malloc(sizeof(Vect4D));
   newVect->x=x;
   newVect->y=y;
   newVect->z=z;
   newVect->b=b;

   return newVect;
}

Vect *copyVect(Vect *v)
{
   return createVect(v->x,v->y);
}

void destroyVect(Vect *v)
{
   free(v);
}

int equalVect(Vect *a,Vect *b)
{
   return (a->x==b->x && a->y==b->y);
}

Vect *vectSum(Vect *a,Vect *b)
{
   return createVect(a->x+b->x,a->y+b->y);
}

Vect *vectDiff(Vect *a,Vect *b)
{
   return createVect(a->x-b->x,a->y-b->y);
}

int vectNorm(Vect *v)
{
   return (v->x)*(v->x)+(v->y)*(v->y);
}

int vectNormIsLessThan(Vect *v,int m)
{
   return(vectNorm(v)<=m);
}

void displayVect(Vect *v)
{
   if(v) printf("(%d,%d)",v->x,v->y);
}
