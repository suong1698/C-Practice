#include <iostream>
void view_board();
bool gameover();
void player_case();
char turn;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool draw =false;

using namespace std;
int main(int argc, char** argv) {
	cout<<"Welcome To Tic-tac-toe game! Play with your way! "<<endl<<"If you find any problem, please contact john.nguyen@gameloft.com";
	turn='X';
	//
	
	while(!gameover()){
		view_board();
		player_case();
		gameover();
	}
	if(turn=='O'&& !draw){
		view_board();
		cout<<endl<<endl<<endl<<"Play 1 Wins!\n";
	}
	else if (turn=='X' && !draw){
		view_board();
		cout<<endl<<endl<<endl<<"Play 2 Wins!\n";
	}
	else{
		view_board();
		cout<<endl<<endl<<endl<<"DRAW!\n";
	}
	return 0;
}
void view_board(){
	cout<<endl<<endl;
	cout<<"  __________________"<<endl;
	cout<<"  |     |     |     |"<< endl;
	cout<<"  |  "<< board[0][0] <<"  |  "<< board[0][1] << "  |  "<< board[0][2]<<"  |" <<endl;
	cout<<"  |_____|_____|_____|"<< endl;
	cout<<"  |     |     |     |"<< endl;
	cout<<"  |  "<< board[1][0] <<"  |  "<< board[1][1] << "  |  "<< board[1][2]<<"  |"<< endl;
	cout<<"  |_____|_____|_____|"<< endl;
	cout<<"  |     |     |     |"<< endl;
	cout<<"  |  "<< board[2][0] <<"  |  "<< board[2][1] << "  |  "<< board[2][2]<<"  |"<< endl;
	cout<<"  |     |     |     |"<< endl;
	cout<<"  -------------------";
}
void player_case(){
	int choice;
	int row=0,colum=0;
	if(turn == 'X'){
		cout<<"player1 case X : ";
	}
	else if (turn =='O'){
		cout<<"player2 case O : ";
	}
	cin>>choice;
	switch (choice){
		case 00: row=0; colum=0; break;
		case 01: row=0; colum=1; break;
		case 02: row=0; colum=2; break;
		case 10: row=1; colum=0; break;
		case 11: row=1; colum=1; break;
		case 12: row=1; colum=2; break;
		case 20: row=2; colum=0; break;
		case 21: row=2; colum=1; break;
		case 22: row=2; colum=2; break;
		default:
			cout<< "Try again\n";
			player_case();
	}
	if (turn=='X'&& board[row][colum]!= 'X'&&board[row][colum] !='O'){
		board[row][colum]='X';
		turn='O';
	}
	else if(turn =='O'&& board[row][colum]!= 'X'&&board[row][colum] !='O'){
		board[row][colum]='O';
		turn='X';
	}
	else{
		cout<<" try again\n";
		player_case();
	}
}
bool gameover(){
	//win
	for(int i=0;i<3;i++){
		if((board[0][i]==board[1][i]&&board[1][i]==board[2][i])//corlum
		 || (board[i][0]==board[i][1]&&board[i][1]==board[i][2])//row
		 || ((board[i][i]==board[i+1][i+1]&&board[i+1][i+1]==board[i+2][i+2]))){//diagonal
		 	return true;
		 }
	}
	//draw
	for (int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			if (board[i][j]!='X'&& board[i][j] !='O'){
				return false;
			}
		}
	}
	draw =true;
	return true;
}
