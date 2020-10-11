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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll v[MAXN];

void solve(){

    ms(v, 0);

	if(M == 1LL){
		cout << N << endl;
		return;
	}

    if(N < M){
        for(int i=0;i<N;i++) v[i] = 1;
        N = 0;
    }

	if(N >= M){
		for(int i=0;i<M;i++) v[i] = 1LL;
		N -= M;
	}

	ll k = (M-1LL)*2LL;
    k = N/k;
    
    for(int i=0;i<M;i++) {
        if(i == 0 || i==M-1LL) {
            v[i] += k; 
            N -= k;
        }
        else {
            v[i] += k*2;
            N -= k*2;
        }
    }
    
    bool indo;
    int ptr;
    
    indo = false;
    ptr = M-2;
    	
	while(N){
        if(indo){
            while(ptr < M && N){
				v[ptr++]++;
				N--;
			}
			if(ptr == M) {
				indo = false;
				ptr = M-2;
			}
		}
		else{
            while(ptr >= 0 && N){
				v[ptr--]++;
				N--;
			}
			if(ptr == -1) {
				indo = true;
				ptr = 1;
			}
		}
	}

	for(int i=0;i<M;i++) cout << v[i] << " \n"[i==M-1];
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
		
		solve();
    }

	return 0;
}