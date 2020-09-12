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
#define MAXN 100010
#define MAXM 5010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

vector<int> v2;
int v[MAXN], freq[MAXN], comp[MAXN], t=0;

struct Query{
	int l,r,k,id;

	Query() {}
    Query(int _l, int _r, int _k, int _id) : l{_l}, r{_r}, k(_k), id{_id} {}

    bool operator<(const Query &a) const{
	    if (l/t != a.l/t){
	    	if(l != a.l) return l < a.l; 
	        if(r != a.r) return r < a.r;
	        return id < a.id;
	    }

	    // Otimização dos ponteiros
	    return ( (l/t) & 1) ? (r < a.r) : (r > a.r);
	}
};

int ans[MAXM], freqS[MAXM]; 
Query Q[MAXM];

void add(int p){
	int elem = comp[p];
	freq[elem]++;
	freqS[elem/t]++;
}

void remove(int p){
	int elem = comp[p];
	freq[elem]--;
	freqS[elem/t]--;
}

int kth(int k){

	for(int i=0;i<t;i++){
		if(k - freqS[i] > 0) k -= freqS[i];
		else {
			int b = i*t;

			for(int j=0;j<t;j++){
				if(k - freq[b+j] > 0) k -= freq[b+j];
				else return b+j;
			}
		}
	}
}	

void MO(){
	sort(Q,Q+M);

	int lMO = 0, rMO = -1, l, r, k, id;

	for(int i=0;i<M;i++){
		l = Q[i].l;
		r = Q[i].r;
		k = Q[i].k;
		id = Q[i].id;
	
		while(rMO < r) add(++rMO);
		while(lMO > l) add(--lMO);
		while(rMO > r) remove(rMO--);
		while(lMO < l) remove(lMO++);
	
		ans[ id ] = v2[kth(k)];
	}

	for(int i=0;i<M;i++) cout << ans[i] << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

	v2.resize(N);

	for(int i=0;i<N;i++) {
		int a;
		cin >> a;

		v[i] = a;
		v2[i] = a;
	}

	sort(all(v2));
	v2.resize(unique(all(v2)) - v2.begin());
	
	int n = v2.size();		
	while(t*t <= n) t++;
	
	for(int i=0;i<N;i++) comp[i] = lower_bound(all(v2),v[i]) - v2.begin();

	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;

		Query aux(a-1,b-1,c,i); 

		Q[i] = aux;
	}
	
	MO();

	return 0;
}