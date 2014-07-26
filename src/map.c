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
 * @file map.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "map.h"

char **createEmptyMatrix(int w,int h)
{
   int i,j;
   char **m=(char **)calloc(w,sizeof(char *));
   for(i=0;i<w;i++)
      {
	 m[i]=(char *)calloc(h,sizeof(char));
      }

   return m;
}

void destroyMatrix(int **m,int w,int h)
{
   int i;
   for(i=0;i<w;i++)
      {
	 free(m[i]);
      }
   free(m);
}

Map *createEmptyMap(int w,int h)
{
   int i;
   Map *m=(Map *)malloc(sizeof(Map));
   m->searchLevel=0;
   m->w=w;
   m->h=h;

   m->players=(Vect **)malloc(sizeof(Vect));
   for(i=0;i<2;i++)
      {
	 m->players[i]=(Vect *)malloc(sizeof(Vect));
      }

   m->cell=(char **)malloc(w*sizeof(char *));
   
   for(i=0;i<w;i++)
      {
	 m->cell[i]=(char *)malloc(h*sizeof(char));
      }
   
   return m;
}


void destroyMap(Map *m)
{
   int i;
   for(i=0;i<m->w;i++)
      {
	 free(m->cell[i]);
      }
   free(m->cell);
   free(m);
}

Map *getMapFromStream(FILE *f)
{
   Map *m;
   int i,j,h,w;
   char c;
   fscanf(f,"%d %d\n",&h,&w);
   m=createEmptyMap(w,h);
   
   for(i=0;i<w;i++)
      {
	 for(j=0;j<h;j++)
	    {
	       m->cell[i][j]=fgetc(f);
	    }
	 fgetc(f);
      }

   return m;
}

void displayMap(Map *m)
{
   int i,j;
   FILE *f=fopen("map.txt","a+");
   fprintf(f,"\033[33mAffichage de la carte\033[0m\n");
   for(i=0;i<m->w;i++)
      {
	 for(j=0;j<m->h;j++)
	    {
	       fprintf(f,"%c",m->cell[i][j]);
	    }
	 fprintf(f,"\n");
      }
   fclose(f);
}
