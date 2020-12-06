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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int a[MAXN], b[MAXN];
int c[MAXN], d[MAXN];

void solve(){

    int cnt = 0;

    for(int i=0;i<N/2;i++){
        c[cnt] = a[i];
        d[cnt++] = b[i];
    }

    for(int i=(N+1)/2;i<N;i++){
        c[cnt] = a[i];
        d[cnt++] = b[i];
    }

    sort(c,c+cnt);
    sort(d,d+cnt);
    
    if( (N & 1) && a[N/2] != b[N/2]){
        cout << "No\n";
        return;
    }
    
    for(int i=0;i<cnt;i++){
        if(c[i] != d[i]){
            cout << "No\n";
            return;
        }
    }

    vector<pii> aux , aux2;

    for(int i=0;i<N/2;i++){
        aux.pb(pii( min(a[i], a[N-1-i]) , max(a[i], a[N-1-i]) ));
        aux2.pb(pii( min(b[i], b[N-1-i]) , max(b[i], b[N-1-i]) ));
    }

    sort(all(aux));
    sort(all(aux2));

    for(int i=0;i<aux.size();i++){
        if(aux[i] != aux2[i]){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main(){

	optimize;
    
    cin >> T;

    while(T--){    
        cin >> N;

        for(int i=0;i<N;i++) cin >> a[i];
        
        for(int i=0;i<N;i++) cin >> b[i];
            
        solve();
    }
    
	return 0;
}