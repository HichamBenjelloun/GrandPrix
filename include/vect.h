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

#ifndef __VECT_H
#define __VECT_H

/**
 * @file vect.h
 *  
 * Structures and methods for a Tree
 */

#include <stdio.h>
#include <stdlib.h>

/* Structures */

typedef struct vect{
   int x,y;

} Vect;

typedef struct vect4D{
   int x,y,z,b;

} Vect4D;

/* Methods */

Vect *createVect(int,int);
Vect4D *createVect4D(int,int,int,int);

Vect *copyVect(Vect *);

void destroyVect(Vect *);

int equalVect(Vect *,Vect *);

Vect *vectSum(Vect *,Vect *);
Vect *vectDiff(Vect *,Vect *);

int vectNorm(Vect *);
int vectNormIsLessThan(Vect *,int);

void displayVect(Vect *);

#endif
