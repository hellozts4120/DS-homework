#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 35;
int board[MAX][MAX];
int sta[MAX];
int ans[MAX];

int Gauss(int n){
	int row, col, max;
	row = col = 0;
	while(row < n && col < n){
		max = row;
		for(int i = row; i < n; i++){
			if(board[i][col] > board[max][col]){
				max = i;
			}
		}
		if(!board[max][col]){
			col++;
			continue;
		}
		if(max != row){
			for(int i = col; i <= n; i++){
				int temp = board[row][i];
				board[row][i] = board[max][i];
				board[max][i] = temp;
			}
		}
		for(int i = row + 1; i < n; i++){
			if(!board[i][col]){
				continue;
			}
			for(int j = col; j <= n; j++){
				board[i][j] = (board[row][j] - board[i][j] + 2) % 2;
			}
		}
		row++;
		col++;
	}
	for(int i = row; i < n; i++){
		if(board[i][n]){
			return -1;
		}
	}
	if(row == n){
		return 1;
	}
	else{
		return (1 << (n - row));
	}
}

int main(){
	int n, cases;
	cin >> cases;
	while(cases--){
		memset(sta,0,sizeof(sta));
		memset(ans,0,sizeof(ans));
		memset(board,0,sizeof(board));
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> sta[i];
		}
		for(int i = 0; i < n; i++){
			cin >> ans[i];
		}
		int x,y;
		while(cin >> x >> y){
			if(!x && !y){
				break;
			}
			board[y-1][x-1] = 1;
		}
		for(int i = 0; i < n; i++){
			board[i][i] = 1;
			board[i][n] = (ans[i] - sta[i] + 2) % 2;
		}
		int result = Gauss(n);
		if(result < 0){
			cout << "Oh,it's impossible~!!" << endl;
		}
		else{
			cout << result << endl;
		}
	}
	return 0;
}