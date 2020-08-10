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

	vector<int> a(n-1);
	for(int i=0; i<n-1; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int i;
	for(i=1; i<=n-1; i++){
		if(a[i-1] != i){
			cout << i << endl;
			break;
		}
	}

	if(i==n){
		cout << i << endl;
	}
}