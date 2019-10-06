#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 10 // # OF COLUMNS
#define ROWS 10 // # OF ROWS

int main(void)
{
   int column, row = 0;
   int direction, i, j;
   int bNum = 0;

   char path[ROWS][COLUMNS];
   char blocked;

   _Bool BLOCKED = false;

   // creates 10x10 matrix
   for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLUMNS; j++) {
         path[i][j] = '.';
      }
   }
   srand((unsigned) time(NULL));

   path[0][0] = 'A';  // initialize

  
   for (i = 'B'; i <= 'Z'; i++) {
      direction = ((rand() % ROWS) % 4); // go up, down, right, or left 

      switch(direction) { // switch 0: west, 1: east, 2: south, 3: north

	    case 0: // west
           
 	    if ((column - 1 >= 0) && (path[row][column - 1] == '.')) { 
               path[row][--column] = i;
               break;
            } else {
               bNum++;
            }

            if ((column + 1 <= 9) && (path[row][column + 1] == '.')) { 
               path[row][++column] = i;
               break;
            } else {
               bNum++;
            }

            if ((row - 1  >= 0) && (path[row - 1][column] == '.')) { 
               path[--row][column] = i;
               break;
            } else {
               bNum++;
            }

            if ((row + 1 <= 9) && (path[row + 1][column] == '.')) { 
               path[++row][column] = i;
               break;
            } else {
               bNum++;
            }
            break;

            case 1: // east
           
 	    if ((column + 1 <= 9) && (path[row][column + 1] == '.')) { 
               path[row][++column] = i;
               break;
            } else {
               bNum++;
            }

            if ((column - 1 >= 0) && (path[row][column - 1] == '.')) { 
               path[row][--column] = i;
               break;
            } else {
               bNum++;
            }

            if ((row - 1  >= 0) && (path[row - 1][column] == '.')) {
               path[--row][column] = i;
               break;
            } else {
               bNum++;
            }

            if ((row + 1 <= 9) && (path[row + 1][column] == '.')) { 
               path[++row][column] = i;
               break;
            } else {
               bNum++;
            }
            break;

            case 2: // south
            if ((row + 1 <= 9) && (path[row + 1][column] == '.')) { 
               path[++row][column] = i;
               break;
            } else {
               bNum++;
            }

            if ((row - 1  >= 0) && (path[row - 1][column] == '.')) { 
               path[--row][column] = i;
               break;
            } else {
               bNum++;
            }

            if ((column + 1 <= 9) && (path[row][column + 1] == '.')) { 
               path[row][++column] = i;
               break;
            } else {
               bNum++;
            }

            if ((column - 1 >= 0) && (path[row][column - 1] == '.')) { 
               path[row][--column] = i;
               break;
            } else {
               bNum++;
            }

            break;

            case 3: // north
            
 	    if ((row - 1  >= 0) && (path[row - 1][column] == '.')) { 
               path[--row][column] = i;
               break;
            } else {
               bNum++; 
            }

            if ((row + 1 <= 9) && (path[row + 1][column] == '.')) { 
               path[++row][column] = i;
               break;
            } else { 
               bNum++;
            }

            if ((column + 1 <= 9) && (path[row][column + 1] == '.')) { 
               path[row][++column] = i;
               break;
            } else { 
               bNum++;
            }

            if ((column - 1 >= 0) && (path[row][column - 1] == '.')) { 
               path[row][--column] = i;
               break;
            } else {
               bNum++;
            }
            break;

      }

      if (bNum == 4) { // blocked everywhere
         blocked = --i;
         BLOCKED = true;

         break;
      }

      bNum = 0;         // clear counter

   }


   printf("\n");

   for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLUMNS; j++) {
         printf("%c ", path[i][j]);
      }
      printf("\n");
   }

   return 0;
}
