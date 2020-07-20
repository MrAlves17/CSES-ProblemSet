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

/*
	Based at iamprayush's solution:
		https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/movie-festival.cpp
*/

int main(){
	FAST_I;

	int n;
	cin >> n;

	vector<pair<ll,ll>> v;
	ll a,b;
	while(n--){
		cin >> a >> b;
		v.PB(MP(b,a));
	}

	sort(v.begin(), v.end()); // sort by endings, because as soon the movie ends, more movies will be watched

	int d=0;
	ll last_end=0;

	REP(i,0,v.size()-1){
		if(v[i].S >= last_end){
			last_end = v[i].F;
			d++;
		}
	}

	cout << d << endl;
	
}