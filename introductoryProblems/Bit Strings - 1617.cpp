#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int main(){
	FAST_I;

	ll n;
	cin >> n;

	ll x=1;
	for(ll i=0; i<n; i++){
		x = (x << 1);
		if(x>1000000007){
			x = x%1000000007;
		}
	}
	cout << x << endl;
}
