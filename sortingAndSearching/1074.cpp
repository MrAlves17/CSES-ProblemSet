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

	int n;
	cin >> n;
	vector<ll> v(n);

	REP(i,0,n-1){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll med = v[n/2];
	ll cost=0;
	REP(i,0,n-1){
		cost += abs(med-v[i]);
	}

	cout << cost << endl;

}