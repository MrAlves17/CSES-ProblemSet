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
	Solution O(n)
	References:
		https://discuss.codechef.com/t/help-with-maximum-subarray-sum-ii-from-cses/73404/2
*/

struct minqueue{
	stack<pair<ll,ll>> front, back;
	void push(ll x){
		if(front.empty()){
			front.push({x,x});
			return;
		}
		front.push({x, min(x,front.top().second)});
	}
	void pop(){
		assert(front.size() + back.size());
		if(!back.empty()){
			back.pop();
			return;
		}
		back.push({front.top().first, front.top().first});
		front.pop();
		while(!front.empty()){
			back.push({front.top().first, min(front.top().first, back.top().second)});
			front.pop();
		}
		back.pop();
	}
	ll getmin(){
		assert(front.size() + back.size());
		if(front.empty()){
			return back.top().second;
		}
		if(back.empty()){
			return front.top().second;
		}
		return min(front.top().second, back.top().second);
	}
};

int main(){
	FAST_I;

	int n,a,b;
	cin >> n >> a >> b;

	// using prefix sum, the subarray sum in range (j-1)<->i is ps[i]-ps[j], j<i;
	// the idea is to find in the last b-a+1 elems the minimum prefix sum, so the 
	// subarray sum is maximized
	vector<ll> ps(n+1);
	ll x;
	ps[0] = 0;
	REP(i,0,n){
		cin >> x;
		ps[i+1] = ps[i] + x;
	}

	// two stacks that works like that:
	/*
		1) fill st1 with (b-a+1) ps elements. The second value in pair must be the min of all seen 
		from beginning to end.
		2) when st1 is full, move st1 elems to st2. st2 will be st1 in reverse order, but the top 
		elem is the min of all seen from end to beginning;
		3) pop the top element of st2 (the oldest elem)
		4) fill st1 again as 1), popping the elements in st2
		5) return to 2) if there are more elements
		obs: for each step, the min elem will be the min of the two stacks second values.
	*/
	minqueue q;


	ll ans=-LLONG_MAX;
	REP(i,a,n+1){
		if(i>b){
			q.pop();
		}
		q.push(ps[i-a]);
		ans = max(ans,ps[i]-q.getmin());
	}

	cout << ans << endl;

	return 0;
}