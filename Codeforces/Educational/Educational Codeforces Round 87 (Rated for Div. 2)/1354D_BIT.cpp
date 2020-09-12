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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int bit[MAXN];

//Consulta em N (log N)^2

int query(int x){
    int sum = 0;
    for(;x>0;x-= x&-x) sum += bit[x];
    return sum;
}

void update(int x, int p){
    for(;x<=N;x+= x&-x) bit[x] += p;
}

void imprimi(){
    FOR(i,1,N+1) cout << bit[i] << " ";
    cout << endl;
}

int buscaBinary(int x){
    int l = 1, r = N;

    if(query(N) == 0) return 0;

    while(true){
        int m = (l+r)/2;

        if(l>=r) return m;
        if(query(m) >= x) r = m;
        else l = m+1;
    }
}

void solve(){

    FOR(i,0,M){
        int a;
        cin >> a;

        if(a>0) update(a,+1);
        else update(buscaBinary(-a),-1);
    }

    cout << buscaBinary(1) << endl;
}

int main(){

    optimize;
    
	cin >> N >> M;

    FOR(i,0,N){
        int a;
        cin >> a;
        update(a,1);
    }	

	solve();
    
	return 0;
}