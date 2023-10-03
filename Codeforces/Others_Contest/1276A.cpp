#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
set<int> apaga;
string s;

void solve(int i){
	if(s[i] != 'o') return;

	if(i >= 2 && i <= sz(s)-2){
		if(s[i-1] == 'w' && s[i-2] == 't' && s[i+1] == 'n' && s[i+2] == 'e') {
			apaga.insert(i);		}
	}
}

void solve2(int i){
	if(s[i] == 't'){
		if(i <= sz(s)-2){
			if(s[i+1] == 'w' && s[i+2] == 'o') {
				if(apaga.find(i+2) == apaga.end()) apaga.insert(i+1);
			}
		}
	}

	if(s[i] == 'o'){
		if(i <= sz(s)-2){
			if(s[i+1] == 'n' && s[i+2] == 'e') {
				if(apaga.find(i) == apaga.end()) apaga.insert(i+1);
			}
		}
	}

}

void solve(){	

	apaga.clear();
	FOR(i,0,sz(s)) solve(i);
	FOR(i,0,sz(s)) solve2(i);
	
	cout << apaga.size() << endl;
	
	for(auto i : apaga){
		if(i == *apaga.begin()) cout << i+1;
		else cout << " " << i+1;
	}
	cout << endl;

}

int main(){

	cin >> N;

	FOR(i,0,N){
		cin >> s;
    	solve();
	}
    
	return 0;
}