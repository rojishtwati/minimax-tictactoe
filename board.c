#include<stdio.h>
#include<conio.h>
#include <stdbool.h>
char player = 'X', ai = 'O',mark;
int move=1,box;
char board[3][3];	


void createBoard(){
	for( int row=0;row<3;row++){
			for(int col=0;col<3;col++){
				board[row][col]='_';
			}
	}
}


void showBoard(){
	system("cls");
		for( int row=0;row<3;row++){
			for(int col=0;col<3;col++){
				printf("%c\t",board[row][col]);
			}
			printf("\n");
		}
}


bool isMoveAvailable(char board[3][3]){
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (board[i][j]=='_')
				return true;
	return false;

} 

int wincheck(char board[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++) 
	{
		if (board[row][0]==board[row][1] &&
			board[row][1]==board[row][2])
		{
			if (board[row][0]==player)
				return +1;
			else if (board[row][0]==ai)
				return -1;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (board[0][col]==board[1][col] &&
			board[1][col]==board[2][col])
		{
			if (board[0][col]==player)
				return +1;

			else if (board[0][col]==ai)
				return -1;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
	{
		if (board[0][0]==player)
			return +1;
		else if (board[0][0]==ai)
			return -1;
	}

	if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
	{
		if (board[0][2]==player) 
			return +1;
		else if (board[0][2]==ai)
			return -1;
	}

	// Else if none of them have won then return 0
	return 0;

}


int makeMove(int box,char mark){
	  switch(box)
    {
        case 1:
        	if(board[0][0]=='_')
        	board[0][0]=mark;
        	else
        	move+=1;
			break;

        case 2:
        	if(board[0][1]=='_')
            board[0][1]=mark;
            else
        	move+=1;
            break;

        case 3:
        	if(board[0][2]=='_')
            board[0][2]=mark;
            else
        	move+=1;
            break;

        case 4:
        	if(board[1][0]=='_')
            board[1][0]=mark;
            else
        	move+=1;
            break;
		
        case 5:
        	if(board[1][1]=='_')
            board[1][1]=mark;
            else
        	move+=1;
            break;

        case 6:
        	if(board[1][2]=='_')
            board[1][2]=mark;
            else
        	move+=1;
            break;

        case 7:
        	if(board[2][0]=='_')
            board[2][0]=mark;
            else
        	move+=1;
            break;

        case 8:
        	if(board[2][1]=='_')
            board[2][1]=mark;
            else
        	move+=1;
            break;
			
		
        case 9:
        	if(board[2][2]=='_')
            board[2][2]=mark;
            else
        	move+=1;
            break;	
			        
        default:
            printf("Error! operator is not correct");
            move+=1;
    }
}


