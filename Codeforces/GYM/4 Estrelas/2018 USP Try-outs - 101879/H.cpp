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
#define MAXN 123456

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<int> A,B,comp;

const int t = 128;
int sum, sum2;

struct Query{
	int l, r, id;

    Query() {}
    Query(int _l, int _r, int _id) : l{_l}, r{_r}, id{_id} {}

    bool operator<(const Query &a) const{
	    if (l/t != a.l/t){
	    	return l < a.l; 
	    }

	    return ( (l/t) & 1) ? (r < a.r) : (r > a.r);
	}
};

int v[MAXN], vis[MAXN], ans[MAXN];
Query Q[MAXN];

void add(int pos) {

    //COMP[I] = POSIÇÃO NA COMPREENSÃO
    //VIS[I] = QUANTOS DIAS TEM AQUELA TEMPERATURA NO RANGE QUE EU TO
    //V[I] = QUANTOS GRUPOS TEM MAIS DE I DIAS NAQUELA RANGE

    //SUM = QUANTOS TEMPARUTAS DIFERENTES TENHO NO RANGE
    //SUM2 = PARA O MAIOR I, V[I] >= I
    
    if(vis[ comp[pos] ] == 0) sum++;
    vis[ comp[pos] ]++;
    
    int i = vis[comp[pos]];

    v[ i ]++;

    if(v[ i ] >= i) sum2 = max(sum2, i);
}

void remove(int pos) {
    
    //COMP[I] = POSIÇÃO NA COMPREENSÃO
    //VIS[I] = QUANTOS DIAS TEM AQUELA TEMPERATURA NO RANGE QUE EU TO
    //V[I] = QUANTOS GRUPOS TEM MAIS DE I DIAS NAQUELA RANGE

    //SUM = QUANTOS TEMPARUTAS DIFERENTES TENHO NO RANGE
    //SUM2 = PARA O MAIOR I, V[I] >= I
    
    if(vis[ comp[pos] ] == 1) sum--;

    int i = vis[comp[pos] ];

    if(sum2 == i && v[i] == i) sum2--;

    v[ i ]--;
    vis[ comp[pos] ]--;
}

void MO(){
	sort(Q, Q+M);

	int lMO=0, rMO=-1, l, r;
	
    v[0] = N;

	for(int i=0; i<M; i++) {
		l = Q[i].l;
		r = Q[i].r;
    
        while(rMO < r) add(++rMO);
		while(lMO > l) add(--lMO);
		while(rMO > r) remove(rMO--);
		while(lMO < l) remove(lMO++);
        
		ans[Q[i].id] = min(sum, sum2);
	}
}

void solve(){

    for(int i=0;i<M;i++){
        int a,b;
        
        cin >> a >> b;

        a--, b--;

        Q[i] = (Query(a,b,i));
    }

    MO();

    for(int i=0;i<M;i++){
        cout << ans[i] << endl;
    }
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    A.resize(N);
    B.resize(N);
    comp.resize(N);

    for(int i=0;i<N;i++){
        cin >> A[i];
        B[i] = A[i];
    }

    sort(all(B));

    B.resize(unique(all(B)) - B.begin());

    for(int i=0;i<N;i++){
        comp[i] = lower_bound( all(B), A[i]) - B.begin();
    } 

	solve();

	return 0;
}