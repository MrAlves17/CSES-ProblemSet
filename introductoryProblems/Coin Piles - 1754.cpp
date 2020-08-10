#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int main(){
	FAST_I;

	int t;
	cin >> t;

	while(t--){
		ll a,b;
		cin >> a >> b;
		if(max(a,b) > 2*min(a,b)){
			cout << "NO" << endl;
		} else {
			a%=3;
			b%=3;
			if(max(a,b)==2 && min(a,b) == 1 || a==0 && b==0){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}
/*
	move1:
	-1 -2
	-2 -1
*/