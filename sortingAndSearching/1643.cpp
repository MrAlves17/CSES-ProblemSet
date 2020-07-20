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

	ll a;
	ll max_sum = -10e9;
	ll sum = -10e9;
	REP(i,1,n){
		cin >> a;
		sum = max(0ll+a,sum+a);
		max_sum = max(max_sum, sum);
	}

	cout << max_sum << endl;

}