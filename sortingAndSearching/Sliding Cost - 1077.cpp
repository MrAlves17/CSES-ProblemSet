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
	References:
		https://www.youtube.com/watch?v=a96aJIs_C00&t=820s
		https://www.geeksforgeeks.org/median-of-sliding-window-in-an-array/
*/

int main(){
	FAST_I;

	ll n,k;
	cin >> n >> k;

	vector<ll> v(n);
	REP(i,0,n){
		cin >> v[i];
		if(k==1) cout << "0 ";
	}

	if(k==1){
		cout << endl;
		return 0;
	}

	multiset<ll> minSet,maxSet;

	ll window[k];
	REP(i,0,k){
		window[i] = v[i];
	}

	REP(i,0,k/2){
		maxSet.insert(window[i]);
	}

	REP(i,k/2,k){
		if(window[i] <= *maxSet.begin()){
			minSet.insert(window[i]);
		}else{
			minSet.insert(*maxSet.begin());
			maxSet.erase(maxSet.begin());
			maxSet.insert(window[i]);
		}
	}

	ll costs;
	costs=0;
	REP(i,0,k){
		costs += abs(*minSet.rbegin()-window[i]);
	}
	cout << costs;

	ll lastCosts = costs;
	ll last = window[0], lastMed = *minSet.rbegin();
	REP(i,k,n){

		if(window[i%k] < *maxSet.begin()){
			minSet.erase(minSet.find(window[i%k]));

			window[i%k] = v[i];

			if(window[i%k] < *maxSet.begin()){
				minSet.insert(window[i%k]);
			}else{
				minSet.insert(*maxSet.begin());
				maxSet.erase(maxSet.begin());
				maxSet.insert(window[i%k]);
			}
		}else{
			maxSet.erase(maxSet.find(window[i%k]));

			window[i%k] = v[i];

			if(window[i%k] > *minSet.rbegin()){
				maxSet.insert(window[i%k]);
			}else{
				maxSet.insert(*minSet.rbegin());
				multiset<ll>::iterator it=minSet.end(); it--;
				minSet.erase(it);
				minSet.insert(window[i%k]);
			}
		}

		costs = lastCosts - abs(lastMed-last) + abs(*minSet.rbegin()-window[i%k]);
		if(k%2==0){
			costs -= (*minSet.rbegin()-lastMed);
		}

		lastMed = *minSet.rbegin();
		cout << " " << costs;
		lastCosts = costs;
		last = window[(i+1)%k];
	}

	cout << endl;
 
	return 0;
}

/*
	for k%2!=0:
		[a b (c) d e] f | sorted
		w1 = (c-a) + (c-b) + (d-c) + (e-c);
		w1 = (d+e) - (a+b);
		
		case 1: f > med
			a [b c (d) e f]
			w2 = (e+f) - (b+c);
			w2 = w1 + x;
				x = w2 - w1;
				x = (e+f) - (b+c) - ((d+e) - (a+b));
				x = f - c - d + a;
				x = (f-d) - (c-a);
			w2 = w1 - (c-a) + (f-d);
			c = lastMed; d = med; a=erased; f=inserted;

		case 2: f == med
			a [b c (f) d e]
			w2 = (d+e) - (b+c);
			w2 = w1 + x;
				x = w2 - w1;
				x = (d+e) - (b+c) - ((d+e) - (a+b));
				x = (a-c);
			w2 = w1 - (c-a) + (f-f);
			c = lastMed; f = med; a=erased; f=inserted;

		case 3: f < med
			a [f b (c) d e]
			w2 = (d+e) - (f+b);
			w2 = w1 + x;
				x = w2 - w1;
				x = (d+e) - (f+b) - ((d+e) - (a+b));
				x = (a-f);
			w2 = w1 - (c-a) + (c-f);
			c = lastMed; c = med; a=erased; f=inserted;

	w(i) = w(i-1) - (lastMed-last) + (med-inserted);

	for k%2==0:
		[a (b) c d] e  | sorted
		w1 = (b-a) + (c-b) + (d-b);
		w1 = (c+d) - (a+b);
		
		case 1: e > med
			a [b (c) d e]
			w2 = (d+e) - (b+c);
			w2 = w1 + x;
				x = w2 - w1;
				x = (d+e) - (b+c) - ((c+d) - (a+b));
				x = e-2c+a;
				x = (a-c) + (e-c) + (b-b) = -(b-a) + (e-c) - (c-b);
			w2 = w1 - (b-a) + (e-c) - (c-b);
			b = lastMed; c = med; a=erased; e=inserted;

		case 2: e == med
			a [b (e) c d]
			w2 = (c+d) - (b+e);
			w2 = w1 + x;
				x = w2 - w1;
				x = (c+d) - (b+e) - ((c+d) - (a+b));
				x = a-e + (b-b) = -(b-a) + (e-e) - (e-b);
			w2 = w1 - (b-a) + (e-e) - (e-b);
			b = lastMed; e = med; a=erased; e=inserted;

		case 3: e < med
			a [e (b) c d]
			w2 = (c+d) - (e+b);
			(equal case 2)	

	
	w(i) = w(i-1) - (lastMed-last) + (med-inserted) - (med-lastMed);

	w(i) = w(i-1) - (lastMed-last) + (med-inserted);
	if(k%2==0){
		w(i) -= (med-lastMed)
	}
*/