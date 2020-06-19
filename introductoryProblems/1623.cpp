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

void test(vector<ll>& p, ll& minAll, vector<ll>& px){
	int k=0;
	ll m=0;
	REP(j,0,p.size()-1){
		if(k<px.size() && px[k]==p[j]){
			m += p[j];
			k++;
		} else {
			m -= p[j];
		}
	}

	minAll = min(abs(m), minAll);
}

void testAll(vector<ll>& p, ll& minAll, int i, vector<ll>& px){

	if(i==p.size()){
		test(p, minAll, px);
		return;
	}

	px.PB(p[i]);
	testAll(p, minAll, i+1, px);
	px.pop_back();
	testAll(p, minAll, i+1, px);
}

int main(){
	FAST_I;

	int n;
	cin >> n;

	vector<ll> p(n);

	REP(i,0,n-1){
		cin >> p[i];
	}

	ll minAll=LLONG_MAX;
	vector<ll> px;
	testAll(p,minAll,0,px);

	cout << minAll << endl;
}