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

/*
	Based at iamprayush's solution:
		https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/restaurant-customers.cpp
*/

int main(){
	FAST_I;

	int n;
	cin >> n;
	ll a,b;
	vector<pair<ll,bool>> v;
	while(n--){
		cin >> a >> b;
		v.PB(MP(a,true));// if customer is entering
		v.PB(MP(b,false));// if customer is leaving
	}

	sort(v.begin(), v.end()); // if times are equal, then false comes first

	int mx=0;
	int now=0;

	REP(i,0,v.size()-1){
		now += v[i].S ? 1:-1;
		mx = max(mx,now);
	}

	cout << mx << endl;

}