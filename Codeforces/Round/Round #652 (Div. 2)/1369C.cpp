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

ll A[MAXN], B[MAXN];

void solve(){

    sort(A,A+N);
    reverse(A,A+N);
    sort(B,B+M);

    vector<vector<int>> adj(M);

    int j = 0, k = -1, i = 0;

    for(i=0;i<N;i++){
        if(B[j] == 1){
            adj[j].pb(A[i]);
            j++;
        }
        else if(B[j] == 2){
            adj[j].pb(A[i]);
            i++;
            adj[j].pb(A[i]);
            j++;
        }
        else{
            if(k == -1) k = j;

            for(;j<M;j++,i++) {
                adj[j].pb(A[i]);
            }
            break;
        }
    }

    k = max(0, k);
    
    for(j = k;j<M;j++){
        for(int l = adj[j].size();l < B[j];l++, i++){
            adj[j].pb(A[i]);
        }
    }

    for(i=0;i<M;i++) sort(all(adj[i]));

    ll ans = 0;

    for(i=0;i<M;i++){
        ans += adj[i][0] + adj[i].back();
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i=0;i<N;i++) cin >> A[i];
        for(int i=0;i<M;i++) cin >> B[i];

		solve();
    }

	return 0;
}