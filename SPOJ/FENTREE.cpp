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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1000100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

ll bit[MAXN];

void update(int x, ll b){

	for(;x<MAXN;x+= x&-x) bit[x] += b;
}

ll query(int x){
	ll sum = 0;

	for(;x>0;x-= x&-x) sum += bit[x];

	return sum;
}

ll queryI(int a, int b){

	if(a == 1) 	return query(b);
	else 		return query(b) - query(a-1);
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++) {
		int a;
		cin >> a;

		update(i+1,a);
	}

	cin >> M;

	for(int i=0;i<M;i++){
		char k;
		int a, b;

		cin >> k >> a >> b;

		if(k == 'q'){
			cout << queryI(a,b) << endl;
		}
		else{
			update(a,b);
		}
	}

	return 0;
}