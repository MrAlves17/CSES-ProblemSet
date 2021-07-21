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

const int mod = 1e9 + 7;

int main(){
	FAST_I;

	int n,m;
	cin >> n >> m;

	vector<int> x(n);
	for(int i=0; i<n; i++){
		cin >> x[i];
	}

	// dp[i][j] -> number of ways we can fill the vector up to i elements
	// with j at the ith position(i.e. last position),
	vector<vector<int>> dp(n);

	// if it's a unknown value, we can put any element from 1 to m
	if(x[0] == 0){
		dp[0].resize(m+1,1);
	}else{
	// else we the just put 1 in dp[í][x[0]]
		dp[0].resize(m+1,0);
		dp[0][x[0]] = 1;
	}
	for(int i=1; i<n; i++){
		dp[i].resize(m+1,0);
		// the last element (ith position) must look the previous (i-1)
		// d[i][j] will be the sum of dp[i-1][j-1], dp[i-1][j] and dp[i-1][j+1]
		if(x[i] == 0){
			// as we can put any of the m integers, we need to calculate for 
			// each one all the possibilities based on the integer chose.
			for(int j=1; j<=m; j++){
				(dp[i][j] += (j-1 >= 1) ? dp[i-1][j-1] : 0) %= mod;
				(dp[i][j] += dp[i-1][j]) %= mod;
				(dp[i][j] += (j+1 <= m) ? dp[i-1][j+1] : 0) %= mod;
			}
		}else{
			// but when it's fixed, we see only for him.
			(dp[i][x[i]] += (x[i]-1 >= 1) ? dp[i-1][x[i]-1] : 0) %= mod;
			(dp[i][x[i]] += dp[i-1][x[i]]) %= mod;
			(dp[i][x[i]] += (x[i]+1 <= m) ? dp[i-1][x[i]+1] : 0) %= mod;
		}
	}

	
	int res = 0;
	for(int i=1; i<=m; i++){
		(res += dp[n-1][i]) %= mod;
	}
	cout << res << endl;
}

/*
	2 1 2 1 2

	2 1 2 1 2
	2 2 2 1 2
	2 1 2 2 2
	2 2 2 2 2

	2 1 2 1 2
	2 2 2 1 2
	2 1 2 2 2
	2 2 2 2 2
	2 3 2 1 2
	2 3 2 2 2
	2 3 2 3 2
	2 1 2 3 2
	2 2 2 3 2

*/