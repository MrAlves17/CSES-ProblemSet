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

	cout << n;

	while(n!=1){
		if(n%2!=0){
			n = n*3+1;
		}
		else{
			n /= 2;
		}
		cout << " " << n;
	}

	cout << endl;
}