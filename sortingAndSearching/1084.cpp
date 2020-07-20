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

	ll n,m,k;
	cin >> n >> m >> k;

	vector<ll> a(n),b(m);

	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<m; i++){
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int d=0;
	int j=0,i=0;
	while(j<b.size() && i<a.size()){
		if(abs(b[j]-a[i]) <= k){
			d++;
			i++;
			j++;
		}else if(b[j]>a[i]){
			i++;
		}else{
			j++;
		}
	}
	cout << d << endl;
}