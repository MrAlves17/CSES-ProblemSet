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
		ll i,j;
		cin >> i >> j;

		ll lb = (max(i,j)-1)*(max(i,j)-1)+1;
		ll ub = max(i,j)*max(i,j);

		if(max(i,j)%2==0){
			if(i>=j){
				cout << ub-j+1 << endl;
			} else {
				cout << lb+i-1 << endl;
			}
		} else {
			if(i>=j){
				cout << lb+j-1 << endl;
			} else {
				cout << ub-i+1 << endl;
			}
		}

	}

}