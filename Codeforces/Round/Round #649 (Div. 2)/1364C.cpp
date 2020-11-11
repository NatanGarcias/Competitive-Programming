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
int v[MAXN];
int r[MAXN];
int ans[MAXN];

set<int> s;
priority_queue<pii> pq;

void solve(){

    FOR(i,0,N+1){
        if(r[i] == 0) s.insert(i); 
    }

    int c = 1;
    int maior = 99999;

    FOR(i,0,N){
        if(s.empty()){
            ans[i] = INF-c;
            c++;
        }else{
            ans[i] = *(s.begin());
            s.erase(s.begin());
        }

        if(!pq.empty() && -pq.top().fi  == i){
            s.insert(pq.top().se);
            pq.pop();
        }
    }

    FOR(i,0,N) cout << ans[i] << " \n"[i==N-1];

}

int main(){

    optimize;

    cin >> N;

    int last = -1;

    FOR(i,0,N){
        cin >> v[i];

        r[v[i]]++;

        if(i && last != v[i]){
            pq.push(pii( -(i-1) ,last));
        }

        last = v[i];        
    }
    
    solve();

	return 0;
}