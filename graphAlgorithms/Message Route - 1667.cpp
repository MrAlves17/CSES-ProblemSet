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
vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> previous_computer;

vector<int> solve(int uolevi, int maija){
	queue<int> q;

	q.push(uolevi);

	visited[uolevi] = true;
	while(!q.empty()){
		int computer = q.front();
		q.pop();
		for(int i=0; i<adj_list[computer].size(); i++){
			if(!visited[adj_list[computer][i]]){
				visited[adj_list[computer][i]] = true;
				q.push(adj_list[computer][i]);
				previous_computer[adj_list[computer][i]] = computer;
			}
		}
	}

	vector<int> route;
	if(visited[maija]){
		route.PB(maija);
		while(maija != uolevi){
			int c = previous_computer[maija];
			route.PB(c);
			maija = c;
		}
		reverse(route.begin(), route.end());
	}

	return route;
}

int main(){
	FAST_I;

	cin >> n >> m;

	adj_list.resize(n+1);
	visited.resize(n+1, false);
	previous_computer.resize(n+1);

	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj_list[a].PB(b);
		adj_list[b].PB(a);
	}
	
	vector<int> route = solve(1,n);
	if(route.size()>0){
		cout << route.size() << endl;
		for(int i=0; i<route.size(); i++){
			cout << route[i] << " ";
		}
		cout << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}


	return 0;
}