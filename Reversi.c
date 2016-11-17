/* 
 * File:   Lab7Part1.c
 * Author: user
 *
 * Created on November 7, 2015, 10:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 
 */

//checks if a given move is a valid move
bool checkLegalInDirection (char board[26][26], int dimension, int row, int col, char colour, int deltaRow, int deltaCol) {
    bool test = false;
    int rowNumber = row, colNumber = col;
    //check for valid moves based on color, hence if statements
    if(colour =='W')    {
        //if the space is empty, search around it for something of the opposite color
        if(board[rowNumber][colNumber] == 'U')  {
            for(int multiplier = 1; colNumber+deltaCol*multiplier<dimension && 
                    rowNumber+deltaRow*multiplier<dimension && 
                    colNumber+deltaCol*multiplier>=0 && 
                    rowNumber+deltaRow*multiplier>=0 ;multiplier++) {
                //If it finds something of the opposite colour, then keep searching in that direction until you find the color you started with
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='B')    {
                    if(board[rowNumber + multiplier*deltaRow+deltaRow][colNumber + (multiplier)*deltaCol+deltaCol]=='W')
                        return true;
                }
                else
                    return false;
            }
        }
        else
            return false;
    }
    //same logic as above
    if(colour =='B')    {
        if(board[rowNumber][colNumber] == 'U')  {
            for(int multiplier = 1; colNumber+deltaCol*multiplier<dimension && 
                    rowNumber+deltaRow*multiplier<dimension && 
                    colNumber+deltaCol*multiplier>=0 && 
                    rowNumber+deltaRow*multiplier>=0 ;multiplier++) {
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='W')    {
                    if(board[rowNumber + multiplier*deltaRow+deltaRow][colNumber + (multiplier)*deltaCol+deltaCol]=='B')
                        return true;
                }
                else
                    return false;
            }
        }
        else
            return false;
    }
    return false;
}


//this function prints the board in its current state
void printBoard(char board[26][26], int dimensions) {
    //print out the first line with appropriate letters of the alphabet
    printf("  ");
    char startLetter = 'a';
    for(int col = 0; col<dimensions; col++) {
        printf("%c", startLetter);
        startLetter++;
    }
    
    //print out the letter then the row of the board for every row in the board
    printf("\n");
    startLetter = 'a';
    for(int row = 0; row<dimensions; row++) {
        printf("%c ", startLetter);
        for(int col = 0; col<dimensions; col++) {
            printf("%c", board[row][col]);
        }
        startLetter++;
        printf("\n");
    }
}


//flips the pieces after a move has been chosen
void flipPieces(char board[26][26], int dimension, int row, int col, char colour, int deltaRow, int deltaCol) {
    //STARTS ON THE PIECE ENTERED BY THE USER caps lock lol
    int rowNumber = row, colNumber = col;
    if(colour == 'W')   {
        bool isItBlack = true;
        for(int multiplier = 1; multiplier<dimension && isItBlack == true; multiplier++) {
            //if it finds a piece in the given direction that is the opposite color from the piece in the starting point, then it will flip it
            if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='B')    {
                board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]='W';
            }
            else if (board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='W')
                isItBlack = false;
        }
    }
    //same logic as above
    if(colour == 'B')   {
        bool isItWhite = true;
        for(int multiplier = 1; multiplier<dimension && isItWhite == true; multiplier++) {
            if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='W')    {
                board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]='B';
            }
            else if (board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='B')
                isItWhite = false;
        }
    }
}


//counts how many pieces any given move will flip and returns that number
int flipPiecesCounter(char board[26][26], int dimension, int row, int col, char colour, int deltaRow, int deltaCol) {
    int counter = 0;
    int rowNumber = row, colNumber = col;
    //check for valid moves based on color, hence if statements
    if(colour =='W')    {
        //if the space is empty, search around it for something of the opposite color
        if(board[rowNumber][colNumber] == 'U')  {
            for(int multiplier = 1; colNumber+deltaCol*multiplier<dimension && 
                    rowNumber+deltaRow*multiplier<dimension && 
                    colNumber+deltaCol*multiplier>=0 && 
                    rowNumber+deltaRow*multiplier>=0 ;multiplier++) {
                //If it finds something of the opposite colour, then keep searching in that direction until you find the color you started with
                //otherwise, exit the loop because the move wont flip any pieces
                if(deltaRow==0&&deltaCol==0)
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='U')
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='W')
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='B')    {
                    if(board[rowNumber + multiplier*deltaRow+deltaRow][colNumber + (multiplier)*deltaCol+deltaCol]=='W')
                        //add one to the counter for every move thta gets flipped
                        counter+=1;
                }
                else
                    counter+=0;
            }
        }
        else
            counter+=0;
    }
    //same logic as above, just with the colours flipped
    if(colour =='B')    {
        if(board[rowNumber][colNumber] == 'U')  {
            for(int multiplier = 1; colNumber+deltaCol*multiplier<dimension && 
                    rowNumber+deltaRow*multiplier<dimension && 
                    colNumber+deltaCol*multiplier>=0 && 
                    rowNumber+deltaRow*multiplier>=0 ;multiplier++) {
                if(deltaRow == 0&&deltaCol == 0)
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='U')
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='B')
                    break;
                if(board[rowNumber + multiplier*deltaRow][colNumber + multiplier*deltaCol]=='W')    {
                    
                    
                    if(board[rowNumber + multiplier*deltaRow+deltaRow][colNumber + (multiplier)*deltaCol+deltaCol]=='B')    {
                        counter+=1;
                        //printf("%c%c%c\n%d\n",board[rowNumber + multiplier*deltaRow+deltaRow][colNumber + (multiplier)*deltaCol+deltaCol], rowNumber+'a', colNumber+'a', counter);
                    }
                    
                }
                else
                    counter+=0;
            }
        }
        else
            counter+=0;
    }
    return counter;
}

//computer decides which move to make
void computerMakesMove(char board[26][26], int dimension, char computerPlays) {
    int computerMoves[1][3] = {(0), (0), (0)};
    //chekcs how many pieces are flipped by the computers move
    for(int rows = 0; rows<dimension; rows++)  {
        for(int cols = 0; cols<dimension; cols++)  {
            int numberFlippedPieces = 0;
            for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
                for(int deltaCol = -1; deltaCol<2; deltaCol++){
                    numberFlippedPieces+=flipPiecesCounter(board, dimension, rows, cols, computerPlays, deltaRow, deltaCol);
                }
            }
            //takes the moce that flipps the most pieces
            if(numberFlippedPieces>computerMoves[0][0]) {
                computerMoves[0][0] = numberFlippedPieces;
                computerMoves[1][0] = rows;
                computerMoves[2][0] = cols;
                //printf("%c%c", rows+'a', cols+'a');
            }
        }
    }
    //actually makes the move and flips the pieces
    int rowNumber = computerMoves[1][0];
    int colNumber = computerMoves[2][0];
    for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
        for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
            bool test = checkLegalInDirection(board, dimension, rowNumber, colNumber, computerPlays, deltaRow, deltaCol);
            if(test == true)
                flipPieces(board, dimension, rowNumber, colNumber, computerPlays, deltaRow, deltaCol);
        }
    }
    board[rowNumber][colNumber] = computerPlays;
    
    char computerRow = 'a' + rowNumber;
    char computerCol = 'a' + colNumber;

    printf("Computer places %c at %c%c.\n", computerPlays, computerRow, computerCol);
}

//checks if an available move is good
int numberGoodMoves(char board[26][26], char playerColour, int dimension)  {
    int numberGoodMoves = 0;
    for(int rows = 0; rows<dimension; rows++)   {
        for(int cols = 0; cols<dimension; cols++)   {
            bool goodMove = false;
            for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
                for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
                    bool test = checkLegalInDirection(board, dimension, rows, cols, playerColour, deltaRow, deltaCol);
                    //set the variable to true if the move is a good move
                    if(test == true)
                        goodMove = true;
                    
                        }
                    }
            if(goodMove == true)
                numberGoodMoves++;
        }
    }
    //tell if the move is good or not
    return numberGoodMoves;
}

//checks who wins by seeing how many of each piece there is on the board
void detectWinner(char board[26][26], int dimension)   {
    int whitePieces = 0, blackPieces = 0;
    for(int row = 0; row<dimension; row++)  {
        for(int col = 0; col<dimension; col++)  {
            if(board[row][col] == 'B')
                blackPieces++;
            if(board[row][col] == 'W')
                whitePieces++;
        }
    }
    if(whitePieces>blackPieces)
        printf("W player wins.");
    if(blackPieces>whitePieces)
        printf("B player wins.");
    if(blackPieces == whitePieces)
        printf("Tie");
}

int main(void) {
    char computerPlays, userPlays;
    
        //declare arrays that will be used in the functions
    char board[26][26];
    char validMovesWhite[3][676];
    char validMovesBlack[3][676];
    char input[3][1];
    int dimension, elements;
    //ask user for baord dimension
    printf("Enter the board dimension: ");
    scanf("%d", &dimension);
    //fill the board array with U for as many as there are board dimensions
    for(int row = 0; row<dimension; row++)  {
        for(int col = 0; col<dimension; col++)  {
            board[row][col] = 'U';
        }
    }
    board[dimension/2-1][dimension/2-1] = 'W';
    board[dimension/2-1][dimension/2] = 'B';
    board[dimension/2][dimension/2-1] = 'B';
    board[dimension/2][dimension/2] = 'W';
    
    
    printf("Computer plays (B/W) : ");
    scanf(" %c", &computerPlays);
    
    if(computerPlays == 'B')    {
        userPlays = 'W';
        input[1][1] = userPlays;
    }
    if(computerPlays == 'W')    {
        userPlays = 'B';
        input[1][1] = userPlays;
    }
    printBoard(board, dimension);
    
    //if the the user decides to go first, it enters this loop
    if(userPlays == 'B')    {
        printf("Enter move for colour %c (RowCol): ", userPlays);
        scanf(" %c%c", &input[1][2], &input[1][3]);
        
        int rowNumber = input[1][2] - 'a';
        int colNumber = input[1][3] - 'a';
        //if they make an invalid move then they lose
        int validMove = 0;
            for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
                for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
                    validMove += flipPiecesCounter(board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
                }
            }
            if(validMove == 0)  {
                printf("Invalid move.\n");
                printf("W player wins.");
                return (EXIT_SUCCESS);
            }
        for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
            for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
                bool testDirection = checkLegalInDirection (board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
                if(testDirection == true)
                    //flip the pieces in that direction
                    flipPieces(board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
            }
        }
        //change the piece that the user wanted to change
        board[rowNumber][colNumber] = userPlays;
        printBoard(board, dimension);
    }
    
    int goodMovesComp = 4;
    int goodMovesUser = 4;
    

    
    while(goodMovesComp != 0 && goodMovesUser != 0) {
        goodMovesComp = numberGoodMoves(board, computerPlays, dimension);
        goodMovesUser = numberGoodMoves(board, userPlays, dimension);
        //if there are no more moves to make then detect a winner
        if(goodMovesComp == 0 && goodMovesUser == 0)    {
            detectWinner(board, dimension);
            return(EXIT_SUCCESS);
        }
        //only let the comp move if they have moves, but if they dont, tell them
        if(goodMovesComp ==0)
            printf("%c player has no valid move.\n", computerPlays);
        if(goodMovesComp>0) {
            computerMakesMove(board, dimension, computerPlays);
            printBoard(board, dimension);
        }
        //same as above, but for user
        if(goodMovesUser ==0)
            printf("%c player has no valid move.\n", userPlays);
        if(goodMovesUser>0) {
            printf("Enter move for colour %c (RowCol): ", userPlays);
            scanf(" %c%c", &input[1][2], &input[1][3]);
            int rowNumber = input[1][2] - 'a';
            int colNumber = input[1][3] - 'a';
            int validMove = 0;
            for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
                for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
                    validMove += flipPiecesCounter(board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
                }
            }
            //if the user makes an invalid move, they automatically lose
            if(validMove == 0)  {
                printf("Invalid move.\n");
                printf("%c player wins.", computerPlays);
                return (EXIT_SUCCESS);
            }
            //if the move is valid then flip the pieces that the move flips
            for(int deltaRow = -1; deltaRow<2; deltaRow++)  {
                for(int deltaCol = -1; deltaCol<2; deltaCol++)  {
                    bool testDirection = checkLegalInDirection (board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
                    if(testDirection == true)
                    //flip the pieces in that direction
                        flipPieces(board, dimension, rowNumber, colNumber, userPlays, deltaRow, deltaCol);
                }
            }
        //change the piece that the user wanted to change
            board[rowNumber][colNumber] = userPlays;
            printBoard(board, dimension);
            }
    }
    detectWinner(board, dimension);

    return (EXIT_SUCCESS);
}

