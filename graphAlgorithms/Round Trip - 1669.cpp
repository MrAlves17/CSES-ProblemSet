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
list<int> route;
vector<int> parent;
bool found = false;
int first_city;
int last_city;

void dfs(int city, int p){

	visited[city] = true;
	parent[city] = p;

	for(int i=0; i<adj_list[city].size() && !found; i++){
		// if the next node was already visited and it's not the last one(parent)
		// then I found a Cycle that start at the next node, not necesserily 
		// the same of the dfs' beginning. That's why we save the first city. 
		if(visited[adj_list[city][i]] && adj_list[city][i] != parent[city]){
			found = true;
			first_city = adj_list[city][i];
			last_city = city;
		}else if(!visited[adj_list[city][i]]){
			dfs(adj_list[city][i],city);
		}
	}

	return;
}

int main(){
	FAST_I;

	cin >> n >> m;

	adj_list.resize(n+1);
	visited.resize(n+1, false);
	parent.resize(n+1);

	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj_list[a].PB(b);
		adj_list[b].PB(a);
	}

	// the reason because we don't erase the cities visited to 
	// restart dfs is that any of those cities would get a solution.
	// They are from the same component. Then, we can ignore them.
	for(int i=1; i<=n && !found; i++){
		if(!visited[i]){
			dfs(i,-1);
		}
	}

	if(found){
		route.push_back(first_city);
		route.push_back(last_city);
		while(last_city != first_city){
			int city = parent[last_city];
			route.push_back(city);
			last_city = city;
		}

		cout << route.size() << endl;
		for(int c : route){
			cout << c << " ";
		}
		cout << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}