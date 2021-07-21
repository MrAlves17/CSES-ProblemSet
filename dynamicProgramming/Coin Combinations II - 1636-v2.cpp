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

ll n,x;

const ll mod = (ll) 1e9+7;

int main(){
	FAST_I;

	cin >> n >> x;
	vector<ll> c(n);
	vector<vector<ll>> value;
	value.resize(n);

	for (ll i = 0; i < n; ++i){
		cin >> c[i];
		value[i].resize(x+1);
	}

	for(ll i=0; i<n; i++){
		value[i][0] = 1;
		for(ll j=1; j<=x; j++){
			value[i][j] = (j-c[i] >= 0) ? value[i][j-c[i]] : 0;
			value[i][j] %= mod;
			value[i][j] += (i==0) ? 0 : value[i-1][j];
			value[i][j] %= mod;
		}
	}

	cout << value[n-1][x] << endl;
	return 0;
}