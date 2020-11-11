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
#define MAXM 1000100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int v[MAXN], ans[MAXM], c[MAXN], pre[MAXN], menor;
pii q[MAXN];

void preCalc(){

    for(int i=1;i<=N;i++){
        pre[i] = pre[i-1] + v[i-1];
    }
}
void solve(){

    preCalc();

    sort(q,q+M);

    for(int i=0;i<M;i++){
        int k = q[i].fi;

        if(k < menor) {
            c[q[i].se] = -1;
            continue;
        }

        if( ans[q[i].fi] ) {
            c[q[i].se] = ans[q[i].fi];
            continue;
        }

        int cnt = 0, p = 0;

        while(true){
            p = upper_bound(pre,pre+N+1,k) - pre - 1;
            
            cnt++;

            k = pre[p] + q[i].fi;
        
            if(p == N) break;
        }
        
        ans[q[i].fi] = cnt;
        c[q[i].se] = cnt;
    }
    
    for(int i=0;i<M;i++){
        if(c[i] == -1) cout << "Impossible\n";
        else cout << c[i] << endl;
    }
}

int main(){

	optimize;
	
	cin >> N;

    for(int i=0;i<N;i++) {
        cin >> v[i];
        if(v[i] > menor) menor = v[i];
    }

    cin >> M;

    for(int i=0;i<M;i++){
        cin >> q[i].fi;
        q[i].se = i;
    }

	solve();

	return 0;
}