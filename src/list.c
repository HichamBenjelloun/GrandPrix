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
 * @todo
 * @bug
 */

/**
 * @file list.c
 *  
 * Queue/Stack/DoubleLinked List all-in-one structure
 *
 */

#include "list.h"

Cell *createCell(Element e)
{
   Cell *newCell = (Cell *)calloc(1,sizeof(Cell));
   newCell->content=e;

   return newCell;
}

Cell *copyCell(Cell *c)
{
   return createCell(c->content);
}

void destroyCell(Cell *c)
{
   free(c->content);
   free(c);
}

List *createEmptyList(void)
{
   List *newList=(List *)calloc(1,sizeof(List));
   return newList;
}

int isEmptyList(List *q)
{
   return (!q->first);
}

void enqueue(List *q,Element e)
{
   push(q,e);
}

Element dequeue(List *q)
{
   Cell *temp;
   if(!q->first)
      {
	 return NULL;
      }
   
   if(!q->last)
      {
	 temp=q->first;
	 q->first=NULL;
	 return temp->content;
      }
   
   if(q->first->next==q->last)
      {
	 temp=q->first;
	 q->first=q->first->next;
	 q->last=NULL;
	 return temp->content;
      }

   temp=q->first;
   q->first=q->first->next;
   temp->previous=NULL;
   return temp->content;
}


void push(List *q, Element e)
{
   if(e)
      {
	 Cell *newCell=createCell(e);

	 if(!q->first)
	    {
	       q->first=newCell;
	       newCell->next=q->last;
	       return;
	    }
   
	 if(!q->last)
	    {
	       q->last=newCell;
	       q->first->next=newCell;
	       newCell->previous=q->first;
	       return;
	    }

	 q->last->next=newCell;
	 newCell->previous=q->last;
	 q->last=newCell;
      }
}

Element pop(List *q)
{
   Cell *temp;

   if(!q->first)
      {
	 return NULL;
      }
   
   if(!q->last)
      {
	 temp=q->first;
	 q->first=NULL;
	 return temp->content;
      }

   if(q->first->next==q->last)
      {
	 q->first->next=NULL;
	 temp=q->last;
	 q->last=NULL;
	 return temp->content;
      }

   temp=q->last;
   q->last->previous->next=NULL;
   q->last=q->last->previous;

   return temp->content;
}

List *copyList(List *q)
{
   List *newList=createEmptyList();
   Cell *current=q->first;
   
   while(current)
      {
	 push(newList,current->content);
	 current=current->next;
      }

   return newList;
}

void destroyList(List *q)
{
   Cell *current=q->first;
   Cell *temp=current;

   while(current)
      {
	 temp=current;
	 current=current->next;
	 destroyCell(temp);
      }

   free(q);
}
