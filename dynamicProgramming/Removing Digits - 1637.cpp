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

	ll n;
	cin >> n;

	vector<ll> dp(n+1);

	dp[0] = 0;
	for(ll i=1; i<=n; i++){
		string n_str = to_string(i);
		dp[i] = LLONG_MAX;
		for(int k=0; k<n_str.size(); k++){
			ll digit = (int)n_str[k] - '0';
			if(i-digit >= 0){
				dp[i] = min(dp[i],dp[i-digit]+1);
			}
		}
	}

	cout << dp[n] << endl;
	
}