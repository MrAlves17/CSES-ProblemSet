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
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) a*a

using namespace std;

int main(){
	FAST_I;

	ll n,m,c;
	cin >> n >> m;

	multiset<ll, greater<ll>> h;
	ll t;
	REP(i,0,n-1){
		cin >> t;
		h.insert(t);
	}

	REP(i,0,m-1){
		cin >> c;
		multiset<ll, greater<ll>>::iterator it = h.lower_bound(c);
		if(it == h.end()){
			cout << -1 << endl;
		}else{
			cout << *it << endl;
			h.erase(it);
		}
	}

}