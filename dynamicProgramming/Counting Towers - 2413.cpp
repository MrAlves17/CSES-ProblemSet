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

// help from Kartik Arora (amazing explanation):
// https://www.youtube.com/watch?v=pMEYMYTX-r0

int main(){
	// FAST_I;

	ll t;
	cin >> t;

	vector<pair<ll,ll>> dp;
	ll n;
	while(t--){
		cin >> n;

		if(dp.size() >= n+1){
			cout << (dp[n].F + dp[n].S)%mod << endl;
			continue;
		}

		dp.resize(n+1);

		dp[1].F = 1; // divided
		dp[1].S = 1; // not divided
		for(ll i=2; i<=n; i++){
			// first, the blocks not divided
			ll no_extends = dp[i-1].F + dp[i-1].S;
			no_extends %= mod;
			ll both_extends = dp[i-1].F;
			ll one_extends = 2*dp[i-1].F;
			one_extends %= mod;
			
			dp[i].F = (no_extends + both_extends + one_extends)%mod;

			// second, the blocks not divided
			both_extends = dp[i-1].S;

			dp[i].S = (no_extends + both_extends)%mod;
		}

		cout << (dp[n].F + dp[n].S)%mod << endl;
	}
}