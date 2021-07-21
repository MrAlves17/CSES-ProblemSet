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

const ll mod = 1e9 + 7;
int main(){
	FAST_I;

	ll n;
	cin >> n;
	char grid[n][n];

	ll dp[n][n];
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			cin >> grid[i][j]; 
			dp[i][j] = 0;
		}
	}


	dp[0][0] = 1;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(grid[i][j] != '*'){
				if(i-1 >= 0 && grid[i-1][j] != '*'){
					dp[i][j] = dp[i-1][j];
					dp[i][j] %= mod;
				}
				if(j-1 >= 0 && grid[i][j-1] != '*'){
					dp[i][j] += dp[i][j-1];
					dp[i][j] %= mod;
				}
			}
		}
	}

	if(n==1 && grid[0][0] == '*'){
		dp[0][0] = 0;
	}
	cout << dp[n-1][n-1] << endl;
	
}