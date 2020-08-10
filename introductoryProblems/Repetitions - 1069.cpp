#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int main(){
	FAST_I;

	string s;
	cin >> s;

	ll max=0,size=1;
	for(ll i=1; i<s.size(); i++){
		if(s[i-1]==s[i]){
			size++;
		} else {
			if(size>max){
				max = size;
			}
			size=1;
		}
	}

	if(size>max) max=size;

	cout << max << endl;
}