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
 * @version     1.0 - May 19, 2013
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

#ifndef __LIST_H
#define __LIST_H

/**
 * @file list.h
 *  
 * Structures and methods for a List
 * Queue, stack combination
 */

#include <stdio.h>
#include <stdlib.h> 

typedef void * Element;

typedef struct cell{
   Element content;
   struct cell *previous;
   struct cell *next;

} Cell;

typedef struct list{
   Cell *first;
   Cell *last;

} List;

Cell *createCell(Element);

Cell *copyCell(Cell *);

void destroyCell(Cell *);

List *createEmptyList(void);

int isEmptyList(List *);

void enqueue(List *,Element);

Element dequeue(List *);

void push(List *, Element);

Element pop(List *);

List *copyList(List *);

void destroyList(List *);

#endif
