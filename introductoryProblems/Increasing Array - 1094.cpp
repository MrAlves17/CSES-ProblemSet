#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int main(){
	FAST_I;

	int n;
	cin >> n;

	vector<ll> x(n);
	ll turns=0;
	for(int i=0; i<n; i++){
		cin >> x[i];

		if(i>0 && x[i]<x[i-1]){
			turns += x[i-1] - x[i];
			x[i] = x[i-1];
		}
	}

	cout << turns << endl;


}