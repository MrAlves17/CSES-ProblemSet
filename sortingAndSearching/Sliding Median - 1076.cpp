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
	Reference:
		https://www.geeksforgeeks.org/median-of-sliding-window-in-an-array/
*/

int main(){
	FAST_I;

	ll n,k;
	cin >> n >> k;

	vector<ll> x(n);
	REP(i,0,n){
		cin >> x[i];
		if(k==1) cout << x[i] << " ";
	}
	if(k==1){
		cout << endl;
		return 0;
	}

	// the idea is to break the array in the middle, having the smallest numbers in minSet,
	// and the biggest numbers in maxSet, ordered. To preserve the middle, it's necessary to 
	// organize the numbers in the sets for each insertion.

	// PART 0: create multisets(because we have repeated numbers) and stablish the 1º window
	multiset<ll> minSet, maxSet;

	ll window[k];
	REP(i,0,k){
		window[i] = x[i];
	}

	// PART 1: construct sets: maxSet always have k/2 elem and minSet k-k/2
	REP(i,0,k/2){
		maxSet.insert(window[i]);
	}

	REP(i,k/2,k){
		if(x[i] < *maxSet.begin()){
			minSet.insert(window[i]);
		}else{
			minSet.insert(*maxSet.begin());
			maxSet.erase(maxSet.begin());
			maxSet.insert(window[i]);
		}
	}

	// PART 2: print the result of the median
	cout << *minSet.rbegin() << " ";

	// PART 3: apply for the rest of windows
	REP(i,k,n){
		// here we lose one element, but it is reset
		if(window[i%k] <= *minSet.rbegin()){
			minSet.erase(minSet.find(window[i%k]));

			window[i%k] = x[i];

			if(window[i%k] < *maxSet.begin()){
				minSet.insert(window[i%k]);
			}else{
				minSet.insert(*maxSet.begin());
				maxSet.erase(maxSet.begin());
				maxSet.insert(window[i%k]);
			}
		}else{
			maxSet.erase(maxSet.find(window[i%k]));
			window[i%k] = x[i];

			if(window[i%k] > *minSet.rbegin()){
				maxSet.insert(window[i%k]);
			}else{
				maxSet.insert(*minSet.rbegin());
				minSet.erase(minSet.find(*minSet.rbegin()));
				minSet.insert(window[i%k]);
			}
		}

		cout << *minSet.rbegin() << " ";
	}

	cout << endl;

	return 0;
}