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
char mov[] = {'U','R','D','L'};
char dx[] = {0,1,0,-1};
char dy[] = {-1,0,1,0};
string s;
int steps=0;
bool board[7][7];

void paths(int x, int y){

	if(x==0 && y==6){
		if(steps==48){
			d++;
		}
		return;
	}

	bool cutoffs = board[y][x] ||
					(y==6 || y==0) && x>0 && x<6 && !board[y][x-1] && !board[y][x+1] ||
					(x==6 || x==0) && y>0 && y<6 && !board[y-1][x] && !board[y+1][x] ||
					y<6 && y>0 && board[y+1][x] && board[y-1][x] && y>0 && y<6 && !board[y][x-1] && !board[y][x+1] ||
					x<6 && x>0 && board[y][x+1] && board[y][x-1] && y>0 && y<6 && !board[y-1][x] && !board[y+1][x];

	if(cutoffs){
		return;
	}

	board[y][x] = true;

	if(s[steps] != '?'){
		REP(m,0,3){
			if(mov[m] == s[steps]){
				if(y + dy[m] >= 0 && y + dy[m] < 7 && x + dx[m] >= 0 && x + dx[m] < 7){
					if(!board[y+dy[m]][x+dx[m]]){
						steps++;
						paths(x+dx[m], y+dy[m]);
						steps--;
					}
				}
				break;
			}
		}
		board[y][x] = false;
		return;
	}

	REP(m,0,3){
		if(y + dy[m] >= 0 && y + dy[m] < 7 && x + dx[m] >= 0 && x + dx[m] < 7){
			if(!board[y+dy[m]][x+dx[m]]){
				steps++;
				paths(x+dx[m], y+dy[m]);
				steps--;
			}
		}
	}
	board[y][x] = false;

}

int main(){
	FAST_I;

	cin >> s;

	REP(i,0,6){
		REP(j,0,6){
			board[i][j] = false;
		}
	}

	int x=0,y=0;
	paths(x,y);
	cout << d << endl;
}