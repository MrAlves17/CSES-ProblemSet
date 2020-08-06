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
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define SQ(a) a*a

using namespace std;

int main(){
	FAST_I;

	ll n,x;
	cin >> n >> x;

	vector<pair<ll,ll>> a(n);
	ll b;
	REP(i,0,n){
		cin >> b;
		a[i].F = b;
		a[i].S = i+1;
	}

	sort(a.begin(), a.end());

	ll i=-1,k=n-1;

	while(++i<k){
		ll j=i+1;
		ll k=n-1;
		// fixed i, j=i+1 -> <- k=n-1
		while(j<k){
			if(a[i].F + a[j].F + a[k].F == x){
				cout << a[i].S << " " << a[j].S << " " << a[k].S << endl;
				break;
			}else if(a[i].F + a[j].F + a[k].F < x){
				j++;
			}else{
				k--;
			}
		}

		if(j==k){
			continue;
		}else if(a[i].F + a[j].F + a[k].F == x){
			break;
		}

	}



	if(i>=k){
		cout << "IMPOSSIBLE" << endl;
	}
}