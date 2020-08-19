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

/*
	solution based at geeksforgeeks solution:
		https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
*/

int main(){
	FAST_I;

	ll n;
	cin >> n;

	ll a;
	ll sum_now = 0, numSubDiv = 0;
	ll mod[n];
	memset(mod,0,sizeof(mod));
	REP(i,0,n){
		cin >> a;
		sum_now += a;
		// save all rests quantities
		// 	it sums n because of the negative numbers.
		// 		because of this sum, it's necessary to do mod again for the positive numbers
		mod[(sum_now%n+n)%n]++;
	}

	REP(i,0,n){
		// make combination of n choose 2
		if(mod[i]>1){
			numSubDiv += (mod[i]*(mod[i]-1))/2;
		}
	}

	numSubDiv += mod[0];


	cout << numSubDiv << endl;

	return 0;
}