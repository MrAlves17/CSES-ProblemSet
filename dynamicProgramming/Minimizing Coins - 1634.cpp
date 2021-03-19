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

int find_best_combination(vector<int>& c, int x_atual, vector<int>& answers){
	if(x_atual == 0){
		return 0;
	}else if(answers[x_atual]!=0){
		return answers[x_atual];
	}else{
		int m = INT_MAX;
		bool changed = false;
		for(int i=0; i<c.size(); i++){
			if(x_atual-c[i] >= 0){
				int q = find_best_combination(c, x_atual-c[i], answers);
				if(q == -1){
					continue;
				}else{
					m = min(m, q+1);
					changed = true;
				}
			}
		}
		answers[x_atual] = changed ? m : -1;
		return answers[x_atual];
	}
}

int main(){
	FAST_I;

	int n,x;
	cin >> n >> x;
	vector<int> c(n), answers(x+1);
	for (int i = 0; i < n; ++i){
		cin >> c[i];
	}
	REP(i,0,x){
		answers[i] = 0;
	}

	cout << find_best_combination(c, x, answers) << endl;
	return 0;
}