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
#define REP(i,a,b) for(ull i=a;i<b;i++)
#define SQ(a) a*a

using namespace std;

/*
	solution from iamprayush:
		https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/factory-machines.cpp
*/

int main(){
	FAST_I;

	ull n,t;
	cin >> n >> t;

	vector<ull> v(n);
	ull slowest=0;
	REP(i,0,n){
		cin >> v[i];
		slowest = max(slowest,v[i]);
	}

	ull l=0,r=slowest*t+1,total_time,final_total_time=0,mid;
	while(l<=r){
		mid = l+(r-l)/2;
		total_time = 0;
		REP(i,0,n){
			total_time += mid/v[i];
		}

		if(total_time >= t){
			final_total_time = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}

	cout << final_total_time << endl;
}