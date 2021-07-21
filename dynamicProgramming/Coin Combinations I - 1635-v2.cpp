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

const ll mod = (ll) 1e9+7;

int main(){
	FAST_I;

	ll n,x;
	vector<ll> value;

	cin >> n >> x;
	value.resize(x+1,0);
	vector<ll> c(n);
	for (ll i = 0; i < n; ++i){
		cin >> c[i];
	}

	value[0] = 1;
	for(ll i=0; i<=x; i++){
		for(ll j=0; j<c.size(); j++){
			if(i - c[j] >= 0){
				value[i] += value[i - c[j]]; 
				value[i] %= mod;
			}
		}
	}

	cout << value[x] << endl;
	return 0;
}
