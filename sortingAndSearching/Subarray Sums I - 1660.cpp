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

	ll n, x;
	cin >> n >> x;

	// array of prefix sum
	vector<ll> ps(n+1);
	ll a;
	ps[0] = 0;
	REP(i,0,n){
		cin >> a;
		ps[i+1] = ps[i] + a;
	}
	// ps is sorted and doesn't have repeated numbers, since all numbers read are positive (>=1)

	ll numSubArrays=0;
	REP(i,0,n){
		// found backwards the position where, removing the subarray behind, the remaining subarray's sum is equal to x
		vector<ll>::iterator it=lower_bound(ps.begin(), ps.begin()+i,ps[i+1]-x);

		// if it finds (not end's subarray and subarray's sum equals to x), count+1
		if(it!=ps.begin()+i+1 && ps[i+1]-*it==x){
			numSubArrays++;
		}
	}

	cout << numSubArrays << endl;
}