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
int v[MAXN];

void solve(){

    for(int i=0;i<N;i++){
        v[i] = v[i] % M;        
    }

    sort(v,v+N);
    reverse(v,v+N);

    priority_queue<pii> ord;
    int cnt = 1;

    for(int i=0;i<N;i++){
        if(!i){
            ord.push(pii(-cnt,v[i]));
        }
        else if(v[i] == v[i-1]){
            cnt++;
            ord.push(pii(-cnt,v[i]));
        }
        else{
            cnt = 1;
            ord.push(pii(-cnt,v[i]));
        }
    }

    ll x = 0;

    while(!ord.empty()){
        ll u = ord.top().se;
        ord.pop();

        if(!u) continue;

        ll aux = (x+u + M-1)/M;
        ll aux2 = aux * M;
    
        x += aux2 - (x + u);
        x++;
    }

    cout << x << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i=0;i<N;i++) cin >> v[i];

		solve();
    }

	return 0;
}