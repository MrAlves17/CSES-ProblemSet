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
vector<ll> value;

const ll mod = (ll) 1e9+7;

ll find_all_combinations(vector<ll>& c, ll x_atual){
	if(x_atual == 0){
		return 1;
	}

	if(x_atual<0){
		return 0;
	}

	if(value[x_atual] >= 0){
		return value[x_atual];
	}

	ll qtd_possibilities = 0;
	for(ll i=0; i<c.size(); i++){
		qtd_possibilities += find_all_combinations(c,x_atual-c[i]);
		qtd_possibilities %= mod;
	}

	value[x_atual] = qtd_possibilities % mod;

	return qtd_possibilities;
}

int main(){
	FAST_I;

	cin >> n >> x;
	value.resize(x+1,-1);
	vector<ll> c(n);
	for (ll i = 0; i < n; ++i){
		cin >> c[i];
	}

	cout << find_all_combinations(c, x) << endl;
	return 0;
}
