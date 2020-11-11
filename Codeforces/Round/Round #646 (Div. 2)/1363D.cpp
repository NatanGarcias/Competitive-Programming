#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<set<int>> adj;

int query(vector<int> &a){
    cout << "? " << (int)a.size() << " ";
    cout.flush();
    
    for(int i=0;i<(int)a.size()-1;i++) cout << a[i] << " ";
    cout << a[a.size()-1] << endl;

    int ans;

    cin >> ans;

    return ans;
}

void resp(vector<int> &a){
    cout << "! ";
    cout.flush();
    
    for(int i=0;i<(int)a.size()-1;i++) cout << a[i] << " ";
    cout << a[a.size()-1] << endl;

    string ans;
    cin >> ans;
}

int bb(int x){

    int l = 0, r = N-1;

    while(l != r){
        int m = (l+r)/2;

        vector<int> aux;
        for(int i=l;i<=m;i++) aux.push_back(i+1);

        if(query(aux) == x){
            r = m;
        }
        else{
            l = m+1;
        }
    }

    return l;
}

void solve(){

    vector<int> aux(N,0);
    for(int i=0;i<N;i++) aux[i] = i+1;

    int maior = query(aux);

    int p = bb(maior);

    int v = -1;

    for(int i=0;i<M;i++) {
        if(adj[i].find(p+1) != adj[i].end()) v = i;
    }

    aux.clear();   
    for(int i=0;i<N;i++) if(adj[v].find(i+1) == adj[v].end()) aux.push_back(i+1);
    int ult = query(aux);

    aux.clear();    
    for(int i=0;i<M;i++) aux.pb(maior);
    aux[v] = ult;

    resp(aux);
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;

        adj.resize(M);

        for(int i=0;i<M;i++){
            int a;
            cin >> a;

            for(int j=0;j<a;j++) {
                int b;
                cin >> b;

                adj[i].insert(b);
            } 
        }

		solve();
        
        for(int i=0;i<M;i++) adj.clear();
    }

	return 0;
}