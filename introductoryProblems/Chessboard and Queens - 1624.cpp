#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) a*a

using namespace std;

ull d=0;
int n=8;

bool feasible(vector<vector<char>> &chessboard, int y, int x){
	int posi,posj;
	for(posi=y, posj=x; posi>0 && posj>0; posi--,posj--);
	for(int i=posi, j=posj; i<n && j<n; i++,j++){
		if(chessboard[i][j]=='r'){
			return false;
		}
	}

	for(posi=y, posj=x; posi>0 && posj<n-1; posi--,posj++);
	for(int i=posi, j=posj; i<n && j>=0; i++,j--){
		if(chessboard[i][j]=='r'){
			return false;
		}
	}
	for(int i=0; i<n; i++){
		if(chessboard[i][x]=='r'){
			return false;
		}
	}

	return true;
}

void fill(vector<vector<char>> chessboard, int i){
	
	if(i==n){
		d++;
		return;
	}

	for(int x=0; x<n; x++){
		if(chessboard[i][x]!='*' && feasible(chessboard,i,x)){
			chessboard[i][x] = 'r';
			fill(chessboard,i+1);
			chessboard[i][x] = '.';
		}
	}
}

int main(){
	FAST_I;

	vector<vector<char>> chessboard;
	char cell;
	REP(i,0,n-1){
		chessboard.resize(n);
		REP(j,0,n-1){
			cin >> cell;
			chessboard[i].PB(cell);
		}
	}

	fill(chessboard,0);

	cout << d << endl;
}