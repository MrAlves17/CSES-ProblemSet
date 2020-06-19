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

	map<char,int> m;

	for(ll i=0; i<s.size(); i++){
		map<char,int>::iterator it;
		it = m.find(s[i]);
		if(it!=m.end()){
			it->second++;
		} else {
			m.insert(make_pair(s[i],1));
		}
	}

	string p="";
	char mid='.';
	bool solution = true, middle=false;
	for(map<char,int>::iterator it=m.begin(); it!=m.end(); it++){
		if(it->second%2==0){
			for(ll i=0; i<it->second/2; i++){
				p.push_back(it->first);
			}
			it->second = it->second/2;
		} else if(s.size()%2==0){
			solution = false;
		} else if(!middle){
			mid = it->first;
			it->second--;
			middle = true;
			for(ll i=0; i<it->second/2; i++){
				p.push_back(it->first);
			}
		} else {
			solution = false;
		}
	}
	if(!solution) cout << "NO SOLUTION" << endl;
	else{
		if(mid!='.'){
			p.push_back(mid);
			cout << p;
			for(ll i=p.size()-2; i>=0; i--){
				cout << p[i];
			}
		} else {
			cout << p;
			for(ll i=p.size()-1; i>=0; i--){
				cout << p[i];
			}
			cout << endl;
		}
		
	}
}

/*
	AAACBBBCAAA
*/