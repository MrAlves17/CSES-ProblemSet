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

	bool found = false;
	ll i,l=n;

	/*
		i j ------ k l
		  ->     <-
		i ---k j--- l
	    |->         |
			   	  <--			
		           
	*/
	while(--l>2 && !found){
		i=-1;
		while(++i<n-2 && !found){
			ll j=i+1;
			ll k=l-1;
			while(j<k){
				if(a[i].F + a[j].F + a[k].F + a[l].F == x){
					cout << a[i].S << " " << a[j].S << " " << a[k].S << " " << a[l].S << endl;
					found = true;
					break;
				}else if(a[i].F + a[j].F + a[k].F + a[l].F < x){
					j++;
				}else{
					k--;
				}
			}
		}
	}

	if(!found){
		cout << "IMPOSSIBLE" << endl;
	}
}