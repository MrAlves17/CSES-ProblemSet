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

// based  William Lin solution:
// 		https://youtu.be/dZ_6MS14Mg4?t=6160


int main(){
	FAST_I;

	ll n,x;
	cin >> n >> x;

	vector<ll> a(n);
	REP(i,0,n){
		cin >> a[i];
	}

	map<ll,ll> m;
	// the second member tells us the number of times the first member subarray sum was found including now
	m[0] = 1;

	ll sum_now = 0, numSubArrays = 0;
	REP(i,0,n){
		sum_now += a[i];
		map<ll,ll>::iterator it=m.find(sum_now - x);
		if(it != m.end()){
			numSubArrays += it->S;
		}

		if(m.count(sum_now)){
			m[sum_now]++;
		}else{
			m[sum_now] = 1;
		}
	}

	cout << numSubArrays << endl;

	return 0;
}