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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 100010
#define MAXL 18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int comp[MAXN], A[MAXN], st[MAXN][MAXL];
vector<int> primos;
vector<int> fat[MAXN];

void crivo(int l){

    for(ll i=2;i<l;i++){
        if(!comp[i]){
            for(ll j=i+i;j<l;j+=i) comp[j] = true, fat[j].pb(i);
            fat[i].pb(i);
            primos.pb(i);
        }
    }
}

void preCalc(){

    vector<vector<int>> pos(MAXN);

    //Para cada número, adiciono a sua posição em cada fator primo dele
    for(int i=0;i<N;i++){
        for(int j : fat[A[i]]){
            pos[ j ].pb(i);
        }
    }

    //Calculando valor inicial da pos[i]
    //Para cada num na posição A[i]
    int aux = N - 1;
    for(int i=N-1;i>=0;i--){

        //Vejo até que posição posso nele sem ter colisão com ninguém
        //Ou seja, pega o mínimo dentre os fatores primos do número atual que tenho
        for(int j : fat[A[i]]){
            auto it = upper_bound(all(pos[j]), i);
            if(it != pos[j].end())aux = min( (*it)-1, aux);
        }

        st[i][0] = aux + 1;
    }

    //Contruindo sparseTable
    //K = quantidade de saltos que vou fazer
    for(int k=1;k<MAXL;k++){
        for(int i=0;i<N;i++){
            if(st[i][k-1] == N) st[i][k] = N;
            else                st[i][k] = st[ st[i][k-1] ][k-1];
        }
    }
}

int query(int l, int r){

    int ans = 0;

    for(int k = MAXL - 1 ; k >= 0 ; k--){
        if(l < r && st[l][k] <= r){
            ans += (1 << k);
            l = st[l][k];
        }
    }

    return ans + 1;
}

void solve(){

    crivo(MAXN);
    preCalc();

    for(int i=0,l,r;i<M;i++){
        cin >> l >> r;

        l--, r--;

        cout << query(l,r) << endl;
    }	
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++) cin >> A[i];

	solve();
    
	return 0;
}