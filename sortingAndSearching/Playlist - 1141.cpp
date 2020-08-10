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

	int n;
	cin >> n;

	vector<ll> k(n);

	REP(i,0,n-1){
		cin >> k[i];
	}

	map<ll,ll> s;

	ll m=0;

	// sequence starts at i
	for(int i=0,j=0; i<n; i++){
		// find next repeated number
		while(j<n && s[k[j]] == 0){
			// increment appereance and iterate
			s[k[j++]]++;
		}

		// j repeated, i start, j-i == sequence's size
		m = max((ll)m, (ll)j-i);
		// until i reaches the element repeated, the new sequence doesn't start
		s[k[i]]--;
		// no worry about changing m because i is increasing and j is fixed
	}

	cout << m << endl;
}