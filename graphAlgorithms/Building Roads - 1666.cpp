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

void dfs(int a){
	if(visited[a]) return;
	visited[a] = true;
	
	for(int i=0; i<adj_list[a].size(); i++){
		dfs(adj_list[a][i]);
	}

}

int main(){
	FAST_I;

	cin >> n >> m;

	adj_list.resize(n+1);
	visited.resize(n+1);

	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj_list[a].PB(b);
		adj_list[b].PB(a);
	}
	
	vector<int> representative; 
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			representative.PB(i);
			dfs(i);
		}
	}

	cout << representative.size()-1 << endl;
	for(int i=0; i<representative.size()-1; i++){
		cout << representative[i] << " " << representative[i+1] << endl;
	}

	return 0;
}