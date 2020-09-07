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

/*
	Solution O(n*log(n))
	References:
		https://discuss.codechef.com/t/help-with-maximum-subarray-sum-ii-from-cses/73404/2
*/

int main(){
	FAST_I;

	int n,a,b;
	cin >> n >> a >> b;

	vector<ll> ps(n+1);
	ll x;
	ps[0] = 0;
	REP(i,0,n){
		cin >> x;
		ps[i+1] = ps[i] + x;
	}
	// -1 3 -2 5 3 -5 2 2
	//  0 -1  2  0  5  8  3  5  7

	// this multiset will keep the smallest ps between i-b <-> i-a
	multiset<ll> s;

	ll ans=-LLONG_MAX;
	REP(i,a,n+1){
		if(i>b){
			s.erase(s.find(ps[i-b-1]));
		}
		s.insert(ps[i-a]);
		ans = max(ans,ps[i]-*s.begin());
	}

	cout << ans << endl;

	return 0;
}