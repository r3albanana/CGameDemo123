#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "macros.h"

/* 
* Function: malloc2dArray
* Import: integer, integer
* Export: none
* Assertion: mallocs a 2d array with the two integer arguments inputted by user to decide the size
 */
void malloc2dArray(int a, int b)
{
    int r;
    /* creates the rows */
    char ** twoD = (char **) malloc(sizeof(char*) * a);

    /* malloc each row to create the columns */
    for(r = 0; r < a; r++)
    {
        twoD[r] = (char *) malloc(sizeof(char) * b);
    }
}

/* 
* Function: malloc2dArrayReturn
* Import: integer, integer
* Export: char ** array
* Assertion: mallocs a 2d array with the two integer arguments inputted by user to decide the size
 */
char ** malloc2dArrayReturn(int a, int b)
{
    int r;

    /* creates the rows */
    char ** twoD = (char **) malloc(sizeof(char*) * a);

    /* malloc each row to create the columns */
    for(r = 0; r < a; r++)
    {
        twoD[r] = (char *) malloc(sizeof(char) * b);
    }
    return twoD;
}

/* 
* Function: printBoundary
* Import: char ** array, integer, integer
* Export: none
* Assertion: prints outer edges of the array displaying X
 */
void printBoundary(char ** arr, int row, int col)
{
    int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            if(r == 0 || c == 0 || r == row - 1 || c == row - 1)
            {
                printf("%c", arr[r][c]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }   
   
}

/* 
* Function: fillcharArray
* Import:  char** array, integer, integer
* Export: none
* Assertion: fills 2d character array with X's on the outer edges and fills the rest with blank spaces
 */
void fillCharArray(char ** arr, int row, int col)
{
    int r, c;
    /*char border = '*';*/ 
    /*char empty = ' ';*/
    
    for(r = 0; r < row; r++)
    {  
        for(c = 0; c < col; c++)
        {
            if(r == 0 || c == 0 || r == row - 1 || c == col -1)
            {
                arr[r][c] = BORDER;
            }
            else
            {
                arr[r][c] = EMPTY;
            }   
        }
    }
}

/* 
* Function: fillPlayer
* Import: char** array, integer, integer
* Export: not sure yet
* Assertion: fills the 2d array with player represented as P
 */
void fillPlayer(char ** arr, int row, int col)
{
    /*char player = 'P';*/

    arr[row][col] = PLAYER;
    
}

/* 
* Function: fillGoal
* Import: char** array, integer, integer
* Export: none
* Assertion: Fills the 2d array with the goal represented as G
 */
void fillGoal(char ** arr, int row, int col)
{
    /*char goal = 'G';*/

    arr[row][col] = GOAL;
    
}

/* 
* Function: fillEmpty
* Import: char** array, integer, integer
* Export: none
* Assertion: Fills the 2d array with an empty space
 */
void fillEmpty(char ** arr, int row, int col)
{
    arr[row][col] = EMPTY;
}

/* 
* Function: printGameGrid
* Import: char ** array, integer, integer
* Export: none
* Assertion: prints out the whole game grid (hopefully)
 */
void printGameGrid(char ** arr, int row, int col)
{
    int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            printf("%c", arr[r][c]); 
        }
        printf("\n");
    }   
   
}

/* 
* Function: collapsingFloor
* Import: char ** array, integer, integer
* Export: none
* Assertion: just a placeholder for collapsing floor at the moment
 */
void collapsingFloor(char ** arr, int row, int col)
{
    arr[row][col] = FLOOR;
}

/* 
* Function: printMovement
* Import: none
* Export: none
* Assertion: prints out the controls for player movement
 */
void printMovement()
{
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go right\n");
}