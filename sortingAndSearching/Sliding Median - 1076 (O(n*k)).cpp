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

	ll n,k;
	cin >> n >> k;

	multiset<ll> s;
	vector<ll> x(n);
	REP(i,0,n){
		cin >> x[i];
	}

	REP(i,0,n){
		if(s.size() < k){
			s.insert(x[i]);
		}else{
			cout << *next(s.begin(),(k-1)/2) << " ";
			s.erase(s.find(x[i-k]));
			s.insert(x[i]);
		}
	}
	cout << *next(s.begin(),(k-1)/2) << endl;

	return 0;
}

/*
	O(n*k)
*/