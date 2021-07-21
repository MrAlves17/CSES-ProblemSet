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

// I had to check this site:
// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

int main(){
	FAST_I;

	int n;
	cin >> n;

	vector<int> x(n);
	ll max_sum = 0;
	for(int i=0; i<n; i++){
		cin >> x[i];
		max_sum += x[i];
	}

	sort(x.begin(), x.end());

	ll res=1;

	/*
		At stage i, it's guaranteed that with the first i-1
		coins, I can get any result from 1 to res-1. With
		the ith coin, I can get any sum from 1 to res+x[i]-1
		because any y in [res, res+x[i]-1], I just need to take
		the combination of the i-1 first coins that gives z=y-x[i]
		and then add the ith coin.
	*/
	for(int i=0; i<n; i++){
		if(x[i] > res){
			cout << res << endl;
			return 0;
		}
		res += x[i];
	}

	cout << res << endl;

	return 0;
}


/*
	1 2 2 7 9


*/