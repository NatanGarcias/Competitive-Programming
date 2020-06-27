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
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

const int t = 750;
int v[MAXN];
int bloco[t];

void pre(){

    for(int i=0;i<N;i++){
        v[i] = 1;
        bloco[i/t] += 1;
    }
}

int query(int l, int r){
    int sum = 0;

    int tl = l/t, tr = r/t;

    if(tl == tr){
        for(int i=l;i<=r;i++){
            sum += v[i];
        }
    }else{
        for(int i=l,end = (tl+1)*t -1; i<= end; i++){
            sum += v[i];
        }
        for(int i =tl+1;i<tr;i++){
            sum += bloco[i];
        }
        for(int i = tr*t;i<=r;i++){
            sum += v[i];
        }
    }
    return sum;
}

void update(int p, int valor){
    v[p]+= valor;
    bloco[p/t] += valor;
}

void solve(){

    FOR(i,0,N){
        int a;
        cin >> a;

        cout << query(0,a-1) << " \n"[i==N-1];
        cout << query(0,a-1) << "\n";

        update(a-1,-1);
    }
}

int main(){

    optimize;
    cin >> N;

    pre();
    solve();

	return 0;
}