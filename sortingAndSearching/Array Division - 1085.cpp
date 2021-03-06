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
	Complexity: O(n*log(sum))
*/

int main(){
	FAST_I;

	ll n,k;
	cin >> n >> k;

	vector<ll> x(n);
	ll sum=0;
	REP(i,0,n){
		cin >> x[i];
		sum += x[i];
	}

	ll i=0,j=sum, best=sum;
	// find in range 0 <-> sum the limit of the largest sum
	while(i<=j){
		ll mid = (i+j)/2;

		ll count=1, cur_sum=0;
		for(ll l=0; l<n; l++){
			if(x[l] > mid){
				count = k+1;
				break;
			}
			if(cur_sum + x[l] > mid){
				count++;
				cur_sum=0;
			}
			cur_sum += x[l];
		}

		// if solution has k subarrays, the best solution can be setted
		// otherwise, keep looking.
		if(count <= k){
			j = mid-1;
			best = mid;
		}else{
			i = mid+1;
		}
	}

	cout << best << endl;

	return 0;
}