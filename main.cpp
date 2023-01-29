/**************************************************
* Tic Tac Toe Game cli app
* Gray dev
***************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void playGame();
void showBoard();
void scoring(int &win1, int &win2, int &lose1, int &lose2, int &draw);
void scoreBoard();
void save(int &win1, int &win2, int &lose1, int &lose2, int &draw);
void scoreBoard();

struct player{
	string name;
	int win;
	int draw;
	int lose;
};
player playerList[50];
char board[3][3];
int turn = 1;
int playerCount = 0;
string player1;
string player2;


int main(){
	ifstream reader("data.txt");
	string txt;
	int num = 0;
	int i = 0;
	stringstream ss;
	while(reader.peek()!=EOF){
		getline(reader, txt);
		playerList[i].name = txt;
		getline(reader, txt);
		ss << txt;
		ss >> num;
		playerList[i].win = num;
		getline(reader, txt);
		ss << txt;
		ss >> num;
		playerList[i].lose = num;
		getline(reader, txt);
		ss << txt;
		ss >> num;
		playerList[i].draw = num;
		playerCount++;
		i++;
	}

	string tmp;
	while(true){
		cout<<"-------------------------------------------------------------------\n"<<"--------------------------- Tic Tac Toe ---------------------------";
		cout<<"\n-------------------------------------------------------------------\n";
		cout<<"1. Start Game\n2. Scoreboard\n3.Exit\n";
		int toDo;
		cin>>toDo;
		switch (toDo){
			case 1:
				playGame();
				break;
			case 2:
				scoreBoard();
				break;
			case 3:
				exit(0);
				break;
			default:
				cout<<"Please enter a number between 1-3\n";
				break;
		}
	}
}


void showBoard(){
	for (int i = 0; i<3; i++){
		cout<<endl;
	for (int j = 0; j<3; j++){
			cout<<"|"<<board[i][j];
	}
		cout<<"|";
	}
}

void playGame(){
	//setting up the board
	int x = 49; //ascii code for 1 = 49
	for (int i = 0; i < 3; i++){
		for (int j = 0; j <3; j++){
			board[i][j] = x;
			x++;
		}
	}
	//players

	cout<<"first player name: ";
	cin>>player1;
	cout<<"second player name: ";
	cin>>player2;
	showBoard();
	//The actual game
	int cellNum = 1;
	int row;
	int column;
	turn = 1;
	int win1 = 0;
	int win2 = 0;
	int lose1 = 0;
	int lose2 = 0;
	int draw = 0;
	while(cellNum>0 && cellNum<10 && turn < 10){
		cout<<"\n\nEnter cell number: ";
		cin>>cellNum;
		row = (cellNum+2)/3;
		column = cellNum%3;
		if (column == 0) column = 3;
		switch(turn%2){
			case 1:
				if(board[row-1][column-1] != 'X' && board[row-1][column-1] != 'O') board[row-1][column-1] = 'X'; // X for player 1 and O for player 2
				turn++;
				break;
			case 0:
				if(board[row-1][column-1] != 'X' && board[row-1][column-1] != 'O') board[row-1][column-1] = 'O'; // X for player 1 and O for player 2	
				turn ++;
				break;		
		}
		showBoard();
		scoring(win1, win2, lose1, lose2, draw);
	}
	save(win1, win2, lose1, lose2, draw);
	cout<<win1;
	cout<<playerList[0].win; 
}


void scoring(int &win1, int &win2, int &lose1, int &lose2, int &draw){

	//player 1
	if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}
	else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
		win1++;
		lose2++;
		turn = 10;
	}

	//player 2
	else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		win2++;
		lose1++;
		turn = 10;
	}
	//draw
	else if(turn == 10) {
		draw ++;
	}

	if (win1 > win2){
		cout<<"\nPlayer 1 won!\n";
	}
	else if (win2 > win1){
		cout<<"\nPlayer 2 won!\n";
	}
	else if (draw == 1) {
		cout<<"\nDraw\n";
	}
}

void save(int &win1, int &win2, int &lose1, int &lose2, int &draw){
	bool x = true;
	bool y = true;
	for(int i = 0; i < playerCount; i++){
		if(player1 == playerList[i].name){
			playerList[i].win += win1;
			playerList[i].lose += lose1;
			playerList[i].draw += draw;
			x = false;
		}
	}
	if(x){
		playerList[playerCount].name = player1;
		playerList[playerCount].win += win1;
		playerList[playerCount].lose += lose1;
		playerList[playerCount].draw += draw;
		playerCount++;
	}
	for(int i = 0; i < playerCount; i++){
		if(player2 == playerList[i].name){
			playerList[i].win += win2;
			playerList[i].lose += lose2;
			playerList[i].draw += draw;
			y = false;
		}
	}
	if(y){
		playerList[playerCount].name = player2;
		playerList[playerCount].win += win2;
		playerList[playerCount].lose += lose2;
		playerList[playerCount].draw += draw;
		playerCount++;
	}
	ofstream Data("data.txt");
	for(int i = 0; i < playerCount; i++){
		Data << playerList[i].name << endl;
		Data << playerList[i].win << endl;
		Data << playerList[i].lose << endl;
		Data << playerList[i].draw << endl;
	}
	Data.close();
}

void scoreBoard(){
	cout << "Player \t\tWin \t\tLose \t\tDraw\n";
	for(int i = 0; i < playerCount; i++){
		cout << playerList[i].name << "\t\t";
		cout << playerList[i].win << "\t\t";
		cout << playerList[i].lose << "\t\t";
		cout << playerList[i].draw << "\t\t" <<endl;
	}
}