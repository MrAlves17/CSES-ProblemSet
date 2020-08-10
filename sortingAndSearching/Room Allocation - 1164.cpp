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
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define SQ(a) a*a

using namespace std;

int main(){
	FAST_I;

	ll n;
	cin >> n;
	ll a,b;
	vector<pair<ll,pair<ll,ll>>> v;
	REP(i,0,n-1){
		cin >> a >> b;
		v.PB(MP(a,MP(-1,i)));// if customer is entering
		v.PB(MP(b,MP(1,i)));// if customer is leaving
	}

	sort(v.begin(), v.end()); // if times are equal, then -1 comes first

	ll mx=0;
	ll now=0;
	vector<ll> rooms(200005);
	queue<ll> q;
	REP(i,0,v.size()-1){
		if(v[i].S.F == 1){
			// customer is leaving, new room added
			q.push(rooms[v[i].S.S]);
		}else if(q.size() == 0){
			// customer is entering, but there isn't any room
			rooms[v[i].S.S] = ++mx;
		}else{
			// customer is entering, occupy existing room
			rooms[v[i].S.S] = q.front();
			q.pop();
		}
	}

	cout << mx << endl;
	REP(i,0,n-1){
		cout << rooms[i] << " ";
	}
	cout << endl;
}