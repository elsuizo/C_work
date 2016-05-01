/* -------------------------------------------------------------------------
@file read_txt_files.c

@date 05/01/16 12:30:22
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int STEPSIZE = 100;

char ** load_file(char *filename);

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        fprintf(stderr, "Must supply a filename to read\n");
        exit(1);
    }
    // load file into data structure
    char **words = load_file(argv[1]);
    
    for(int j = 0;words[j] != NULL; j++)
        printf("%s\n", words[j]);

    printf("Done!!!\n");

    return 0;
}


char **load_file(char *filename)
{
    FILE *f = fopen(filename, "r");
    // check the read file status
    if(!f)
    {
        fprintf(stderr, "Cant open %s for reading\n", filename);
        return NULL;
    }
    int arrlen = 0;
    // prealocate a chunk of memmory for the file the first 100  
    //  NOTE(elsuizo:realloc con el primer parametro=NULL es lo mismo que malloc)-->Sun 01 May 2016 04:44:29 PM ART
    char **lines = NULL; 

    char buffer[1000];
    int i = 0;
    while(fgets(buffer, 1000, f))
    {
        if(i == arrlen)
        {
            arrlen += STEPSIZE;
            // the buffer is full and then reallocate the new space 
            char **new_lines = realloc(lines, arrlen * sizeof(char *));
            if(!new_lines)
            {
                fprintf(stderr, "Can't realloc men!!!\n");
                exit(1);
            }
            lines = new_lines;
        }
        // skip the newline character "chop"
        buffer[strlen(buffer) - 1] = '\0'; // NOTE(elsuizo) ver si no hay otra manera de hacer esto
        // get the length of buffer
        int slen = strlen(buffer);
        // allocate space for the buffer
        char *str = (char *)malloc((slen + 1) * sizeof(char));
        // copy string from buffer to string
        strcpy(str, buffer);
        // attach str to the data structure
        lines[i] = str;
        i++;
        
    }
    
    if(i == arrlen)
    {
        char **new_arr = realloc(lines, (arrlen + 1) * sizeof(char *));
        if(!new_arr) 
        {
            fprintf(stderr, "Can't realocate the fucking pipe");
            exit(1);
        }
        lines = new_arr;
    }
    lines[i] = NULL; // put the fucking NULL at the end(whith this knows when is finish)
    return lines;
}
