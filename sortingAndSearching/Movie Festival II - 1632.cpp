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

	int n,k;
	cin >> n >> k;

	vector<pair<ll,ll>> m(n);
	ll a,b;
	REP(i,0,n){
		cin >> a >> b;
		m[i].F = b;
		m[i].S = a;
	}

	sort(m.begin(), m.end());

		

	ll w=0;
	multiset<ll> p;
	REP(i,0,k){
		p.insert(0);
	}
	REP(i,0,n){
		// choose the member that finishes his movie
		// the most late before the next movie
		// keep the sooner for the longer movies
		auto it = p.upper_bound(m[i].S);
		if(it != p.begin()){
			it--;
			p.erase(it);
			p.insert(m[i].F);
			w++;
		}
	}

	cout << w << endl;

	return 0;
}
