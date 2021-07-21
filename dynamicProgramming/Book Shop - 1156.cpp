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


int main(){
	FAST_I;

	int n,x;
	cin >> n >> x;

	int h[n];
	int s[n];


	for(int i=0; i<n; i++){
		cin >> h[i];
	}

	for(int i=0; i<n; i++){
		cin >> s[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(x+1,0));

	for(int i=1; i<=n; i++){
		for(int j=0; j<=x; j++){
			int op1 = dp[i-1][j];
			int op2 = (j-h[i-1]>=0) ? (dp[i-1][j-h[i-1]] + s[i-1]) : 0;
			dp[i][j] = max(op1, op2);
		}
	}

	cout << dp[n][x] << endl;
	return 0;
}