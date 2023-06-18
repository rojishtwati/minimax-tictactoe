int row,col;
int max (int x,int y){
	int a=x;
	int b=y;
	if(a>b){return a;
	}
	else{
		return b;
	}
}	
int min (int x,int y){
	int a=x;
	int b=y;
	if(a<b){return a;
	}
	else{
		return b;
	}
}
int minimax(char board[3][3],int depth,bool Maximizing){
	int score=wincheck(board);
	if (score == 1)
        return score;
	if (score == -1)
		return score;
	if (isMoveAvailable(board)==false)
		return 0;
	if (Maximizing){
		int maxEval=-999;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j]=='_'){
					board[i][j]=player;
					int eval=minimax(board,depth+1,!Maximizing);
					maxEval=max(maxEval,eval);
					board[i][j] = '_';
				}
			}
		}	
	return maxEval;
	}
	else{
		int minEval=999;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j]=='_'){
					board[i][j]=ai;
					int eval=minimax(board,depth+1,!Maximizing);
					minEval=min(minEval,eval);
					board[i][j] = '_';
				}
			}
		}	
	return minEval;
	}
}
int findBestMove(char board[3][3]){
	int maxEval=999;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j]=='_'){
					board[i][j]=ai;
					int eval=minimax(board,0,true);
					board[i][j] = '_';
					if(maxEval>eval){
						row=i;
						col=j;
						maxEval=eval;
					}
				}
			}
		}	
		
	if(row==0 &&col==0)return 1;
	if(row==0 &&col==1)return 2;
	if(row==0 &&col==2)return 3;
	if(row==1 &&col==0)return 4;
	if(row==1 &&col==1)return 5;
	if(row==1 &&col==2)return 6;
	if(row==2 &&col==0)return 7;
	if(row==2 &&col==1)return 8;
	if(row==2 &&col==2)return 9;
	
}







