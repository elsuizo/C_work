/* -------------------------------------------------------------------------
@file read_CSV.c

@date 03/27/17 11:10:25
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
   char buffer[1024] ;
   char *record;
   char *line;
   int i=0,j=0;
   int mat[100][100];
   FILE* fstream = fopen("/home/elsuizo/Dropbox/Freelance/ACC_filter/Acc_SampleFile_001.csv","r");
   if(fstream == NULL)
   {
      printf("\n file opening failed ");
      return -1 ;
   }
   while((line = fgets(buffer,sizeof(buffer),fstream)) != NULL)
   {
      record = strtok(line,",");
      while(record != NULL)
      {
         printf("record : %s",record) ;    //here you can put the record into the array as per your requirement.
         mat[i][j++] = atoi(record) ;
         record = strtok(NULL,",");
      }
      ++i ;
   }
   return 0 ;
 }

