#include "board.c"
#include "minimax.c"

int main(){
	
	createBoard();
	showBoard();
	while(isMoveAvailable(board)==true&&wincheck(board)==0){
		if (move%2==0) {
			mark=ai;
		box=findBestMove(board);
		}
		else{
			mark=player;
		scanf("%d",&box);
		}
		move+=1;
		makeMove(box,mark);
		showBoard();
	}
	int winner=wincheck(board);
	if (winner==1) printf("%c is winner",player);
	if (winner==-1) printf("%c is winner",ai);
	if (winner==0) printf("tie game");
	
}
