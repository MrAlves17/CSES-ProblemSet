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
vector<int> dist;

bool solve(int f_pupil){
	queue<int> q;

	q.push(f_pupil);

	visited[f_pupil] = true;
	dist[f_pupil] = 0;

	while(!q.empty()){
		int pupil = q.front();
		q.pop();
		for(int i=0; i<adj_list[pupil].size(); i++){
			if(!visited[adj_list[pupil][i]]){
				visited[adj_list[pupil][i]] = true;
				q.push(adj_list[pupil][i]);
				dist[adj_list[pupil][i]] = dist[pupil]+1;
			}else if(dist[adj_list[pupil][i]]%2 == dist[pupil]%2){
				return false;
			}
		}
	}

	return true;
}

int main(){
	FAST_I;

	cin >> n >> m;

	adj_list.resize(n+1);
	visited.resize(n+1, false);
	dist.resize(n+1);

	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj_list[a].PB(b);
		adj_list[b].PB(a);
	}
	
	bool possible = true;
	for(int i=1; i<=n && possible; i++){
		if(!visited[i]){
			possible = solve(i);
		}
	}
	if(possible){
		for(int i=1; i<dist.size(); i++){
			if(dist[i]%2==0){
				cout << "1 ";
			}else{
				cout << "2 ";
			}
		}
		cout << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}


	return 0;
}