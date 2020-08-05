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

int main(){
	FAST_I;
	
	ll n;
	cin >> n;

	vector<ll> v(n);

	REP(i,0,n){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll timer1=0,timer2=0;
	ll i=0,j=n-1;
	while(true){

		// 1º reads all the books he can read while 2º doesn't end his book
		while(timer1+v[i]<timer2+v[j] && i<n && i!=j){
			timer1 += v[i];
			i++;
		}


		if(i==n || i==j){
			timer2 += v[j]; // 2º reader finishes this book
			if(i==n) break; // if 1º reader has read all the books, then both readers have finished their readings
			j = (j+1)%n;
			timer1 = timer2; // adds the time 1º reader had to wait to read the book 2º was reading 
		}

		// 2º reads all the books he can read while 1º doesn't end his book
		while(timer1+v[i] >= timer2+v[j] && (j!=n-1 || timer2==0)){
			timer2 += v[j];
			j = (j+1)%n;
		}

		// 2º read all the books
		if(j==n-1 && timer2>0){
			timer1 += v[i];
			i++;
			break;
		}
	}

	// display how much time the slowest reader has read all the books
	cout << max(timer1,timer2) << endl;
}

/*
	2	4
	3	2
	4	3

	2	6
	3	
	-	2
	6	3

	2	8
	3
	-	
	8	2
		3
	-----
*/