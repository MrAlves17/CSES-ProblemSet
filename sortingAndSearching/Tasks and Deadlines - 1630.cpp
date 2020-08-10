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

	vector<pair<ll,ll>> v(n);
	REP(i,0,n){
		cin >> v[i].F >> v[i].S;
	}

	sort(v.begin(), v.end());

	ll timer=0;
	ll reward=0;
	REP(i,0,n){
		timer += v[i].F;
		reward += v[i].S-timer;
	}

	cout << reward << endl;
}