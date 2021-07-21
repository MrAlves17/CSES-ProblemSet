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
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define SQ(a) a*a

using namespace std;

int n,m;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void fill(vector<vector<char>>& map, int i, int j){
	for(int k=0; k<4; k++){
		if(i+dx[k] >= 0 && i+dx[k] < n &&
		   j+dy[k] >= 0 && j+dy[k] < m &&
		   map[i+dx[k]][j+dy[k]] == '.'){
			map[i+dx[k]][j+dy[k]] = 'F';
			fill(map, i+dx[k], j+dy[k]);
		}
	}
}

int main(){
	FAST_I;

	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}

	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == '.'){
				count++;
				fill(map, i, j);
			}
		}
	}

	cout << count << endl;
	
	return 0;
}