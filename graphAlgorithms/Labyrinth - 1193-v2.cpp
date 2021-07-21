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
pair<int,int> beg_p,end_p;
vector<vector<char>> mat;
vector<vector<bool>> visited;

bool is_valid(pair<int,int> cell, int i){
	if (cell.F+dx[i] >= 0 && cell.F+dx[i] < n
			&& cell.S+dy[i] >= 0 && cell.S+dy[i] < m
			&& mat[cell.F+dx[i]][cell.S+dy[i]] != '#'
			&& !visited[cell.F+dx[i]][cell.S+dy[i]]){
		return true;
	}
	return false;
}

string solve(pair<int,int> beg_p, pair<int,int> end_p){

	visited.resize(n, vector<bool>(m));
	vector<vector<int>> previous_move(n, vector<int>(m));
	queue<pair<int,int>> q;
	q.push(beg_p);
	visited[beg_p.F][beg_p.S] = true;
	while(!q.empty()){
		pair<int,int> cell = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			if(is_valid(cell,i)){
				q.push(MP(cell.F+dx[i],cell.S+dy[i]));
				previous_move[cell.F+dx[i]][cell.S+dy[i]] = i;
				visited[cell.F+dx[i]][cell.S+dy[i]] = true;
			}
		}
	}

	string solution = "";
	if(visited[end_p.F][end_p.S]){
		while(end_p != beg_p){
			int d = previous_move[end_p.F][end_p.S];
			solution += dir[previous_move[end_p.F][end_p.S]];

			end_p = MP(end_p.F - dx[d], end_p.S - dy[d]);
		}

		reverse(solution.begin(), solution.end());
	}

	return solution;
}

int main(){
	FAST_I;

	cin >> n >> m;

	mat.resize(n, vector<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 'A'){
				beg_p = MP(i,j);
			}else if(mat[i][j] == 'B'){
				end_p = MP(i,j);
			}
		}
	}



	string solution = solve(beg_p, end_p);
	if(solution.size()>0){
		cout << "YES\n";
		cout << solution.size() << endl;
		cout << solution << endl;
	}else{
		cout << "NO\n";
	}

	return 0;
}