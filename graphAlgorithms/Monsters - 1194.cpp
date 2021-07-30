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
pair<int,int> beg_p;
vector<vector<char>> mat;
vector<pair<int,int>> monsters_pos, exits;
vector<vector<int>> previous_move;

bool is_valid(pair<int,int> cell, int i, vector<vector<bool>>& visited){
	if (cell.F+dx[i] >= 0 && cell.F+dx[i] < n
			&& cell.S+dy[i] >= 0 && cell.S+dy[i] < m
			&& mat[cell.F+dx[i]][cell.S+dy[i]] != '#'
			&& !visited[cell.F+dx[i]][cell.S+dy[i]]){
		return true;
	}
	return false;
}

void solve(vector<vector<int>>& distance, vector<vector<bool>>& visited, vector<pair<int,int>> beg_points){

	previous_move.resize(n, vector<int>(m));
	queue<pair<int,int>> q;
	for(int i=0; i<beg_points.size(); i++){
		q.push(beg_points[i]);
		visited[beg_points[i].F][beg_points[i].S] = true;
	}
	while(!q.empty()){
		pair<int,int> cell = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			if(is_valid(cell,i,visited)){
				q.push(MP(cell.F+dx[i],cell.S+dy[i]));
				previous_move[cell.F+dx[i]][cell.S+dy[i]] = i;
				visited[cell.F+dx[i]][cell.S+dy[i]] = true;
				distance[cell.F+dx[i]][cell.S+dy[i]] = distance[cell.F][cell.S]+1;
			}
		}
	}
}

string construct_path(pair<int,int> exit, vector<vector<bool>>& visited){
	string solution = "";
	if(visited[exit.F][exit.S]){
		while(exit != beg_p){
			int d = previous_move[exit.F][exit.S];
			solution += dir[previous_move[exit.F][exit.S]];

			exit = MP(exit.F - dx[d], exit.S - dy[d]);
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
			
			if(mat[i][j] == '.' && (i==0 || j==0 || i==n-1 || j==m-1)){
				mat[i][j] = 'E';
				exits.PB(MP(i,j));
			}else if(mat[i][j] == 'A'){
				beg_p = MP(i,j);
				if(i==0 || j==0 || i==n-1 || j==m-1){
					cout << "YES\n0\n";
					return 0;
				}
			}else if(mat[i][j] == 'M'){
				monsters_pos.PB(MP(i,j));
			}

		}
	}

	vector<vector<int>> monsters_dist(n,vector<int>(m,0));
	vector<vector<bool>> monsters_visits(n,vector<bool>(m,false));

	solve(monsters_dist, monsters_visits, monsters_pos);

	vector<vector<int>> my_distance(n,vector<int>(m));
	vector<vector<bool>> my_visits(n,vector<bool>(m,false));

	solve(my_distance, my_visits, {beg_p});

	string solution = "";
	for(int i=0; i<exits.size(); i++){
		if(my_distance[exits[i].F][exits[i].S] < monsters_dist[exits[i].F][exits[i].S] && 
			my_visits[exits[i].F][exits[i].S] && monsters_visits[exits[i].F][exits[i].S] ||
			my_visits[exits[i].F][exits[i].S] && !monsters_visits[exits[i].F][exits[i].S]
			){

			solution = construct_path(exits[i], my_visits);
			break;
		}
	}

	if(solution.size()>0){
		cout << "YES\n";
		cout << solution.size() << endl;
		cout << solution << endl;
	}else{
		cout << "NO\n";
	}

	return 0;
}