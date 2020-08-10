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

	multiset<int> towers;
	int c;
	REP(i,0,n-1){
		cin >> c;
		multiset<int>::iterator lb = towers.lower_bound(c);
		multiset<int>::iterator ub = towers.upper_bound(c);
		// substitute stack's top cube
		if(lb != towers.end() && c < *lb){
			// normal case
			towers.erase(lb);
		}else if(lb != towers.end() && c == *lb && ub!=towers.end()){
			// special case
			towers.erase(ub);
		}
		// update stack
		towers.insert(c);
	}

	cout << towers.size() << endl;
}