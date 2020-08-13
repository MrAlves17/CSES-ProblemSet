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

	vector<ll> x(n);
	REP(i,0,n){
		cin >> x[i];
	}

	stack<pair<ll,ll>> s;
	REP(i,0,n){
		bool found = false;
		ll j;

		while(!s.empty() && s.top().F >= x[i]){
			s.pop();
		}
		
		if(!s.empty()){
			cout << s.top().S << " ";
		}else{
			cout << 0 << " ";
		}

		s.push(make_pair(x[i],i+1));
	}
	cout << endl;
}