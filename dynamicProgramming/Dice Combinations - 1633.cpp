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


int solve(ll sum, int sol[]){
	if(sol[sum]>0){
		return sol[sum];
	}else{
		for(int i=1; i<=6 && sum-i>=0; i++){
			(sol[sum] += solve(sum-i,sol)) %= (ll)1e9+7;
		}
	}

	return sol[sum];
}

int main(){
	FAST_I;

	ll n;
	cin >> n;

	int sol[n+1];
	memset(sol,0,sizeof(sol));
	sol[0] = 1;
	// sol[x-k] count the number of ways to have a sum x with last digit k, k={1,...,6}
	sol[n] = solve(n, sol);

	cout << sol[n] << endl;

	return 0;
}