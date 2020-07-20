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

	int x,n;
	cin >> x >> n;
	int t;
	set<int> p;
	multiset<int> lenghts;
	// the first passage has the street's length
	lenghts.insert(x);

	// it's impossible to insert traffic light in 0 and x points
	p.insert(0); p.insert(x);
	REP(i,0,n-1){
		cin >> t;
		set<int>::iterator bfr,aft;
		aft = bfr = p.lower_bound(t);
		int va,vb;
		bfr--;
		vb = *bfr;
		va = *aft;

		// remove one of the lengths (passage's length)
		lenghts.erase(lenghts.lower_bound(va-vb));

		// insert the lengths created by the passage's division
		lenghts.insert(t-vb);
		lenghts.insert(va-t);

		// insert the new traffic light
		p.insert(t);

		// print biggest actual length
		cout << *lenghts.rbegin() << " ";
	}
	cout << endl;
}