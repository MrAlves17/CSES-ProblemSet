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
char dir[] = {'R','D','L','U'};
pair<int,int> beg;
int length = INT_MAX;
string solution = "";

void solve(vector<vector<char>>& map, int i, int j, string path){
	map[i][j] = '@';

	if(path.size() > length){
		return;
	}

	// for(int p=0; p<n; p++){
	// 	for(int q=0; q<m; q++){
	// 		cout << map[p][q] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	for(int k=0; k<4; k++){
		if(i+dx[k] >= 0 && i+dx[k] < n &&
			j+dy[k] >= 0 && j+dy[k] < m){

			if(map[i+dx[k]][j+dy[k]] == 'B'){
				path.push_back(dir[k]);
				if(path.size() < length){
					// cout << "\n\n\n\n\nFOUND\n\n\n\n\n" << endl;
					length = path.size();
					solution = path;
				}
				return;	
			}
			else if(map[i+dx[k]][j+dy[k]] == '.'){
				path.push_back(dir[k]);
				solve(map, i+dx[k], j+dy[k], path);
				path.pop_back();
		   	}

		}
	}

	return;
}

int main(){
	FAST_I;

	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == 'A'){
				beg = make_pair(i,j);
			}
		}
	}

	solve(map, beg.F, beg.S, "");
	if(solution.size()>0){
		cout << "YES\n";
		cout << length << endl;
		cout << solution << endl;
	}else{
		cout << "NO\n";
	}

	return 0;
}