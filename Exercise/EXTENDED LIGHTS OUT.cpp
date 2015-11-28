#include<iostream>
#include<cstring>
using namespace std;

int board[35][35];
int ans[35];
int var = 30;

void Gauss(){
	int row, col, max;
	row = col = 0;
	while(row < 30 && col < 30){
		max = row;
		for(int i = row; i < 30; i++){
			if(board[i][col] > board[max][col]){
				max = i;
			}
		}
		if(!board[max][col]){
			col++;
			continue;
		}
		if(max != row){
			for(int i = row; i <= 30; i++){
				int temp = board[row][i];
				board[row][i] = board[max][i];
				board[max][i] = temp;
			}
		}
		for(int i = row + 1; i < 30; i++){
			if(!board[i][col]){
				continue;
			}
			for(int j = col; j <= 30; j++){
				board[i][j] = (board[i][j] - board[row][j] + 2) % 2;
			}
		}
		row++;
		col++;
	}
	for(int i = 29; i >= 0; i--){
		ans[i] = board[i][30];
		for(int j = i+1; j < 30; j++){
			ans[i]^=(board[i][j] && ans[j]);
		}
	}
}

void Init(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			int cur = i*6 + j;
			board[cur][cur] = 1;
			if(i < 4)board[(i+1)*6 + j][cur] = 1;
			if(i > 0)board[(i-1)*6 + j][cur] = 1;
			if(j < 5)board[i*6 + j+1][cur] = 1;
			if(j > 0)board[i*6 + j-1][cur] = 1;
		}
	}
}

int main(){
	int cases;
	int n = 1;
	cin >> cases;
	while(cases--){
		memset(board,0,sizeof(board));
		Init();
		for(int i = 0; i < 30; i++){
			cin >> board[i][30];
		}
		Gauss();
		cout << "PUZZLE #" << n++ << endl;
		for(int i = 0; i < 30; i++){
			if(i == 5 || i == 11 || i == 17 || i == 23 || i == 29){
				cout << ans[i] << endl;
			}
			else{
				cout << ans[i] << " ";
			}
		}
	}
	return 0;
}