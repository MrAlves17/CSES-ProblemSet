#include <bits/stdc++.h>
typedef ll long long;
typedef ld long double;
typedef ull unsigned long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int,int> pi;
#define endl "\n"
#define FAST_I ios_base::sync_with_stdio(false); cin.tie(0)
#define F first
#define S second
#define PB push_back
#define MP make_pair


using namespace std;

int main(){
	FAST_I;

	string s;
	cin >> s;

	sort(s.begin(),s.end());

	ll fat[s.size()+1];
	fat[0] = 1;
	for(int i=1; i<s.size()+1; i++){
		fat[i] = fat[i-1]*i;
	}
	ll n = fat[s.size()];
	int count = 1;
	for(int i=0; i<s.size()-1; i++){
		if(s[i] != s[i+1]){
			n /= fat[count];
			count = 1;
		} else count++;
	}
	if(count==s.size()) n/=fat[count];

	cout << n << endl;

	//https://www.quora.com/How-would-you-explain-an-algorithm-that-generates-permutations-using-lexicographic-ordering
	for(int k=0; k<n; k++){
		cout << s << endl;
		int largestI=0;
		for(int i=0; i<s.size()-1; i++){
			if(s[i]<s[i+1]){
				largestI=i;
			}
		}

		int largestJ=0;
		for(int j=0; j<s.size(); j++){
			if(s[j] > s[largestI]){
				largestJ = j;
			}
		}

		swap(s[largestI],s[largestJ]);

		reverse(s.begin()+largestI+1, s.end());
	}
}

/*
	permutation with repetition
*/