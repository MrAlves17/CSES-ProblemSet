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
vector<vector<ll>> value;

const ll mod = (ll) 1e9+7;

ll find_ordered_combinations(vector<ll>& c, ll x_atual, ll k){
	if(x_atual == 0){
		return 1;
	}

	if(x_atual<0 || k == c.size()){
		return 0;
	}

	if(value[k][x_atual] >= 0){
		return value[k][x_atual];
	}

	ll qtd_possibilities = find_ordered_combinations(c, x_atual-c[k], k);
	qtd_possibilities %= mod;
	qtd_possibilities += find_ordered_combinations(c, x_atual, k+1);
	qtd_possibilities %= mod;

	value[k][x_atual] = qtd_possibilities % mod;

	return qtd_possibilities;
}

int main(){
	FAST_I;

	cin >> n >> x;
	value.resize(n);
	vector<ll> c(n);
	for (ll i = 0; i < n; ++i){
		cin >> c[i];
	}

	for(ll i=0; i<n; i++){
		value[i].resize(x+1,-1);
		value[i][0] = 1;
	}
	cout << find_ordered_combinations(c, x, 0) << endl;
	return 0;
}


/*
	value[2] = 1
	value[3] = 1
	value[4] = 1
	value[5] = 1
	value[6] = 2
	value[7] = 
*/