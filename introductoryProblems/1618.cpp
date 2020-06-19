#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int main(){
	FAST_I;

	ll n;
	cin >> n;

	ll count = 0;
	for(ll i=5; n/i>=1; i*=5){
		count += n/i;
	}

	cout << count << endl;
}

// we add 0 when we multiply by 10
// but 2*5 == 10, then all 2*5 must be count
// we allways have more 2's than 5's
// so we could only count number of 5's
// 25 has two 5's -> 5*5==25
// 125 has three 5's -> 5*5*5==125
// 5^n has n 5's...
// floor of n/(5^i) >= 1 when 5^i < n
// so the condition to stop is n/(5^i) >= 1
