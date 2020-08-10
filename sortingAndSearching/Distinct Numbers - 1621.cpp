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

	set<ll> x;
	ll a;
	for(int i=0; i<n; i++){
		cin >> a;
		x.insert(a);
	}

	cout << x.size() << endl;
}