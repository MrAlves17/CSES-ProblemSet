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

	ll n, x;
	cin >> n >> x;

	vector<pair<ll,ll>> v;
	ll a;
	REP(i,0,n-1){
		cin >> a;
		v.PB(MP(a,i+1));
	}

	sort(v.begin(), v.end());

	int i=0,j=v.size()-1;

	while(i<j){
		if(v[i].F+v[j].F == x){
			cout << v[i].S << " " << v[j].S << endl;
			break;
		}else if(v[i].F+v[j].F > x){
			j--;
		}else{
			i++;
		}
	}

	if(i>=j){
		cout << "IMPOSSIBLE" << endl;
	}



}