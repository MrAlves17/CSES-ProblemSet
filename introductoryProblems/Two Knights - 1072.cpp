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

	vector<ll> a(n),b;
	for(int i=1; i<=min(2,n); i++){
		a[i-1] = ((i*i)*(i*i-1))/2;
		cout << a[i-1] << endl;
	}
	b.push_back(0);
	for(ll i=3; i<=n; i++){
		a[i-1] = ((i*i)*(i*i-1))/2 - b[i-3] - 8*(i-2);
		b.push_back(b[i-3] + 8*(i-2));
		cout << a[i-1] << endl;
	}
}

/*

	((n*n)(n*n-1))/(2) - ?
	0 		1 -0
	6 		2 -0
	28 		3 -8	-8		8*(n-2)
	96 		4 -24 	-16 	8*(n-2)
	252 	5 -48 	-24		8*(n-2)
	550		6 -80 	-32		8*(n-2)
	1056	7 -120 	-40		8*(n-2)
	1848	8 -168	-48		8*(n-2)
			n	b 	 k		   k
*/
