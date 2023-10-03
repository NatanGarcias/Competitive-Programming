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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
	vector<int> parent, size, rank, maior, menor;

	UF(int n){
		parent.assign(n+1,0);
        maior.assign(n+1,0);
        menor.assign(n+1,0);
		size.assign(n+1,1);
        rank.assign(n+1,0);
		iota(all(parent), 0);
        iota(all(menor), 0);
        iota(all(maior), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
        u = find(u);
        v = find(v);

        if(u != v){
            if(rank[u] < rank[v]) swap(u,v);
            parent[v] = u;
            
            menor[u] = min(menor[u], menor[v]);
            menor[v] = menor[u];

            maior[u] = max(maior[u], maior[v]);
            maior[v] = maior[u];

            size[u] += size[v];
            size[v] = size[u];

            if(rank[u] == rank[v]) rank[u]++;
        }
    }

    void print(int u){
        u = find(u);
        cout << menor[u] << " " << maior[u] << " " << size[u] << endl;
    }
};

void solve(){

	UF uf(N);

	for(int i=0;i<M;i++){
		string s;
		int a,b;

		cin >> s;

		if(s[0] == 'u'){
            cin >> a >> b;

            uf.unir(a,b);
        } 
		else {
			cin >> a;

            uf.print(a);
		}
	}
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();

	return 0;
}