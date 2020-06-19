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

	if(n<=2){
		cout << "NO" << endl;
	} else {
		ll sum = ((1+n)*n)/2;
		if(sum%2==0){
			cout << "YES" << endl;
			ll sum1=0;
			vector<ll> p1;
			for(ll i=n; i>=n-ceil(n/2.0)+1; i--){
				p1.push_back(i);
				sum1 += i;
			}
			for(ll i=p1.size()-1; i>=0; i--){
				if(max(sum/2,sum1-(ll)(p1[i]-p1.size()+i)) > sum/2){
					sum1 -= (p1[i]-p1.size()+i);
					p1[i] = p1.size()-i;
				} else {
					p1[i] -= sum1-sum/2;
					sum1 = sum/2;
					break;
				}
			}
			cout << p1.size() << endl;
			for(ll i=p1.size()-1; i>=0; i--){
				cout << p1[i] << " ";
			}
			cout << endl;

			cout << n-p1.size() << endl;
			for(ll i=1,j=0; i<=n; i++){
				if(p1[p1.size()-1-j]==i){
					j++;
				} else {
					cout << i << " ";
				}
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
}

/*
	1

	1
	no

	2
	no

	3
	yes
	1 2 | 3

	4
	yes
	1 4 | 2 3

	5
	no
	
	6
	no

	7
	yes
	1 2 4 7 | 3 5 6

	8
	yes
	1 2 7 8 | 3 4 5 6

	9
	no

	10
	no

	11
	yes
	1 2 4 7 8 11 | 3 5 6 9 10

	11+

	12
	yes
	1 2 4 8 11 12
*/