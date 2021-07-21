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

	int n;
	cin >> n;

	string s;

	for(int i=0; i<n; i++){
		s += '0';
	}

	int qtd = 0;
	int last = 0;
	int qtd_max = pow(2,n);
	set<string> list;
	while(qtd < qtd_max){
		cout << s << endl;
		list.insert(s);
		string aux = s;
		int bit_to_change = -1;
		for(int i=0; i<n && list.count(aux); i++){
			aux = s;
			aux[i] = (aux[i] == '0') ? '1' : '0';
		}
		s = aux;
		qtd++;
	}
	return 0;
}


/*
	0000
	1000
	1001
	1011
	1111


*/