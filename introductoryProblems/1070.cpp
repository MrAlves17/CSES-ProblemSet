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

	if(n<4 && n!=1){
		cout << "NO SOLUTION" << endl;
	} else {
		for(int i=2; i<=n; i+=2){
			cout << i << " ";
		}
		for(int i=1; i<=n; i+=2){
			cout << i << " ";
		}
		cout << endl;
	}

}