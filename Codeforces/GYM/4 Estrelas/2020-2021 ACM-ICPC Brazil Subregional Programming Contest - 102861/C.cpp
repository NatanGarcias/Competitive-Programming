#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define mod2 998244353LL

#define MAXN 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */


ll T,N,M,K;
vector<string> A, B;
map<pll, ll> pre, suf;
map<pll, vector<pll> > par, par2;
ll pot[MAXN], pot2[MAXN];

const ll p = 101;
const ll p2 = 153;

void preCalc(){

    pot[0] = p;
    pot2[0] = p2;

    for(int i=1;i<MAXN;i++) pot[i] = (pot[i-1] * p) % mod;
    for(int i=1;i<MAXN;i++) pot2[i] = (pot2[i-1] * p2) % mod2;
}

ll getChar(char k){
    return k - 'a' + 1;
}
    
struct Hash{
	vector<ll> h, h2;

	Hash(const string &s){
		h.resize(s.size());
        h2.resize(s.size());

		for(int i=0;i<s.size();i++){
			if(!i){
				h[i] = ( ( (ll) ( getChar(s[i]) * pot[i]) ) %mod );  
                h2[i] = ( ( (ll) ( getChar(s[i]) * pot2[i]) ) %mod2 );  
			}else{
				h[i] = (h[i-1] + ( ((ll) (getChar(s[i]) * pot[i]) ) %mod ) ) %mod;  
                h2[i] = (h2[i-1] + ( ((ll) (getChar(s[i]) * pot2[i]) ) %mod2 ) ) %mod2;  
			}
		}
	}

    pll getHash(int l, int r){
		pll r1(h[r], h2[r]);

		if(l){ 
			int w = MAXN - l - 1;
			
            r1.fi = (r1.fi - h[l-1] + mod) % mod;  
			r1.fi = (r1.fi * pot[w]) %mod; 		 	 

            r1.se = (r1.se - h2[l-1] + mod2) % mod2;  
			r1.se = (r1.se * pot2[w]) %mod2; 		 	 
		}
        else{ 
            r1.fi = (r1.fi * pot[MAXN-1]) %mod;
            r1.se = (r1.se * pot2[MAXN-1]) %mod2;
		}

		return r1;
	}
};

vector<Hash> C,D;

void solve(){

    vector<bool> vis(N,1), vis2(M,1);

    preCalc();

    for(int i=0;i<N;i++) C.pb(Hash(A[i]));
    for(int i=0;i<M;i++) D.pb(Hash(B[i]));

    for(int i=0;i<N;i++) pre[ C[i].getHash(0, A[i].size() -1 )] = i;
    for(int i=0;i<M;i++) suf[ D[i].getHash(0, B[i].size() -1 )] = i;

    for(int i=0;i<N;i++){
        for(int j=0;j<A[i].size() -1;j++){

            pll aux = C[i].getHash(0,j);

            auto it = pre.find(aux);
            
            if(it != pre.end()){
                par[ C[i].getHash(j+1, A[i].size() -1) ].pb(pll(i, (*it).se));
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=1;j<B[i].size();j++){

            pll aux = D[i].getHash(j, B[i].size() -1);
            
            auto it = suf.find(aux);
            
            if(it != suf.end()){
                par2[ D[i].getHash(0, j-1) ].pb(pll(i, (*it).se));
            }
        }
    }

    for(auto j : par){
        auto it = par2.find(j.fi);
        
        if(it != par2.end()){

            for(auto i : j.se){
                vis[i.fi] = false;
                vis[i.se] = false;
            }

            for(auto i : (*it).se){    
                vis2[ i.fi ] = false;
                vis2[ i.se ] = false;
            }
        }
    }

    pll ans(0,0);

    for(int i=0;i<N;i++) if(vis[i]) ans.fi++;
    for(int i=0;i<M;i++) if(vis2[i]) ans.se++;

    cout << ans.fi << " " << ans.se << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    A.resize(N);
    B.resize(M);

    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++) cin >> B[i];

    solve();
    
	return 0;
}