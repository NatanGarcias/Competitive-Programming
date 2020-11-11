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
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll v[MAXN], pre[MAXN], menor[MAXN];

void solve(){
    for(int i=0;i<(N+1)/2;i++){
        if(!i)  pre[i] = v[i];
        else    pre[i] = pre[i-1] + v[i];
    }

    for(int i=(N+1)/2;i<N;i++)
        pre[i] = pre[i-1] + M - v[i - (N+1)/2];

    ll aux = INFLL;

    for(int i =(N+1)/2 -1;i<N;i++){
        if(i == (N+1)/2 -1) menor[i] = pre[i];
        else menor[i] = min(menor[i-1], pre[i]);
    }


    for(int i = N-1, cnt = 0;i>=(N+1)/2 -1;i--, cnt++){
        aux = menor[i];

        if(aux + M*cnt > 0){
            cout << (N+1)/2 + cnt << endl;
            return;
        }
        
    }

    cout << -1 << endl;
}

int main(){

	optimize;
	
	cin >> N;

    for(int i=0;i<(N+1)/2;i++) cin >> v[i];

    cin >> M;
	
    solve();
    
	return 0;
}