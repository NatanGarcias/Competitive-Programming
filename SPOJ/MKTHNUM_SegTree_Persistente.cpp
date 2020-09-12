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

struct Node{
	int x;
	Node *l, *r;

	Node(int _x = 0) : x(_x), l(NULL), r(NULL) {}
};

Node seg[MAXN];
int v[MAXN], v2[MAXN], mapa2[MAXN];
map<int,int> mapa;

void build(Node *curr, int tl, int tr){

	if(tl != tr){
		int tm = (tl+tr)/2;

		curr->l = new Node();
		curr->r = new Node();
		
		build(curr->l,tl,tm);
		build(curr->r,tm+1,tr);
	}
}

void update(Node *prev, Node *curr, int tl , int tr, int a, int b, int x){

	if(a > tr || b < tl) return;
	else if(a <= tl && tr <= b){
		curr->x += x;
		return;
	}
	else{
		int tm = (tl+tr)/2;
		
		//Constrói só para o lado do valor que to indo
		if(a <= tm){		
			curr->r = prev->r;

			if(curr->l == NULL) curr->l = new Node();

			update(prev->l , curr->l, tl, tm, a, b, x);
		}else{
			curr->l = prev->l;

			if(curr->r == NULL) curr->r = new Node();

			update(prev->r , curr->r, tm+1, tr, a, b, x);
		}
		
		curr->x = curr->l->x + curr->r->x;
	}
}

int query(Node *prev, Node *curr, int tl , int tr, int k){

	if (tl == tr) return tl;
	else{
		int tm = (tl+tr)/2;

		//Soma curr e diminui prev
		int vleft = curr->l->x - prev->l->x;

		if(k <= vleft)	return query(prev->l, curr->l, tl, tm, k);
		else	return query(prev->r, curr->r, tm+1, tr, k-vleft);
	}
}

void solve(){

	for(int i=0;i<M;i++){
		int a,b,c;

		cin >> a >> b >> c;

		int aux = query(&seg[a-1], &seg[b], 1, N, c);

		cout << mapa2[aux] << endl;
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
		
	build(&seg[0],1,N);

	for(int i=0;i<N;i++) cin >> v[i];

	for(int i=0;i<N;i++) v2[i] = v[i];

	sort(v2, v2+N);
	unique(v2, v2+N);

	int cnt = 1;
	for(auto i : v2) {
		mapa[i] = cnt;
		mapa2[cnt++] = i;
	}

	for(int i=0;i<N;i++) update(&seg[i],&seg[i+1], 1, N, mapa[v[i]], mapa[v[i]], 1);

	solve();

	return 0;
}