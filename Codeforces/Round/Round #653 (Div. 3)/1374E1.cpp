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
vector<int> v[3];

void solve(){

    sort(all(v[0]));
    sort(all(v[1]));
    sort(all(v[2]));

    ll ans = 0;
    vector<int> aux;
    int ptr = 0;

    for(int i=0;i<min(M, (ll) v[0].size());i++){
        ans += v[0][i];
        aux.pb(v[0][i]);
    }

    if(aux.size() < M){
        ll aux2 = M - aux.size();

        if(aux2 > v[1].size() || aux2 > v[2].size()){
            cout << -1 << endl;
            return;
        }

        for(;ptr<aux2;ptr++){
            ans+= v[1][ptr] + v[2][ptr];
        }
    }

    while(ptr < v[1].size() && ptr < v[2].size() && !aux.empty() && v[1][ptr] + v[2][ptr] < aux.back()){
        ans -= aux.back();
        ans += v[1][ptr] + v[2][ptr];
        ptr++;
        aux.pop_back();
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++){
        int a,b,t;

        cin >> t >> a >> b;
        
        if(a && b){
            v[0].pb(t);
        }
        else if(a){
            v[1].pb(t);
        }
        else if(b){
            v[2].pb(t);
        }
    }
	
    solve();

	return 0;
}