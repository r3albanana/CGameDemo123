#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "macros.h"
#include "movement.h"

int main(int argc, char * argv[])
{
    
    /* checks that the argc argument contains 7 arguments) */

    if(argc != 7)
    {
        printf("usage : ./escape <map_row> <map_col> <player_row> <player_col> <goal_row> <goal_col>");
        return 0;
    }

    /* declaring and initalizaing variables that contain parameters for game and converting from string to integer data type using atoi */

    int rowSize = atoi(argv[1]) + 2; /* adds two extra lines to the grid */
    int colSize = atoi(argv[2]) + 2; /* adds two extra lines to the grid */
    int playerRow = atoi(argv[3]);
    int playerCol = atoi(argv[4]);
    int goalRow = atoi(argv[5]);
    int goalCol = atoi(argv[6]);
    
    /* valdiating user command arguments */
    /* checking whether a or b are less than 5, needs to be 5 or above to validate */

    if(rowSize < 5 || colSize < 5)
    {
        printf("Invalid data input"); 
        return 0;
    }
    if(playerRow + 2 > rowSize || playerRow + 2 > colSize || playerRow < 0)
    {
        printf("Invalid data input");
        return 0;
    }
    if(playerCol + 2 > rowSize || playerCol + 2 > colSize || playerCol < 0)
    {
        printf("Invalid data input");
        return 0;
    }
    if(goalRow + 2 > rowSize || goalRow + 2 > colSize || goalRow < 0)
    {
        printf("Invalid data input");
        return 0;
    }
    if(goalCol + 2 > rowSize || goalCol + 2 > colSize || goalCol < 0 )
    {
        printf("Invalid data input");
        return 0;
    }

   
    /* variable declartion for isSuccess */
    int isSuccess;

    /* allocating size of the game grid based on users number entry when starting game */
    
    char ** gameGrid = malloc2dArrayReturn(rowSize, colSize);

    /* filling gameGrid with X's on the outer edges*/
    
    fillCharArray(gameGrid, rowSize, colSize);

    /* fills the gameGrid with the Player */

    fillPlayer(gameGrid, playerRow, playerCol);
    
    /* fills the gameGrid with the Goal */

    fillGoal(gameGrid, goalRow, goalCol);

    do
    {
        
        /* prints gameGrid to screen */

        system("clear");
        printGameGrid(gameGrid, rowSize, colSize);

        /* prints movement controls to screen */

        printMovement();

        /* enables movement around 2d array grid */

        testMovement(gameGrid, &playerRow, &playerCol, &goalRow, &goalCol);

        /* checks to see if player and goal are on the same square then returns TRUE */

        isSuccess = checkPlayerGoal(gameGrid, &goalRow, &goalCol);

    } 
    while (isSuccess != TRUE);
    /* while loops ends when the winner moves onto the goal, however it does not update with 'P' on the map as it ends.
    I tryed to fix this, but could not come up with a solution. */

    
    /* attempts to frees the memory from the 2d array game grid */
    
    free(gameGrid);


    return 0;
}

