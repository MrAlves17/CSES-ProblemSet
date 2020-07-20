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
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define SQ(a) a*a

using namespace std;

int main(){
	FAST_I;

	ll n, x;
	cin >> n >> x;

	vector<ll> p(n), b(n);
	REP(i,0,n-1){
		cin >> p[i];
	}

	sort(p.begin(), p.end(), greater<ll>());


	ll d=0;
	int i=0,j=p.size()-1;
	while(i<=j){
		if(p[j]+p[i] <= x){
			j--;
		}
		d++;
		i++;
	}

	cout << d << endl;
}