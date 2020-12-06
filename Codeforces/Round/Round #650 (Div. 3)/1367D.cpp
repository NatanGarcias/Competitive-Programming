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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;
int v[MAXN];

void solve(){

    vector<int> l(26,0);
    vector<bool> vis(N,0);
    vector<char> ans(N, '0');

    for(auto i : s) l[i-'a']++;

    int cnt = 0, pos = 25;

    while(cnt < N){
        vector<int> p;
        
        for(int i=0;i<N;i++) if(!vis[i] && v[i] == 0) p.pb(i);

        for(int i = pos;i>=0;i--){
            if(l[i] >= p.size() ){
                cnt += p.size();
                l[i] -= p.size();

                for(auto j : p) {
                    vis[j] = true;
                    ans[j] = (char) (i + 'a');

                    for(int k=0;k<N;k++){
                        v[k] = v[k] - abs(j-k);
                    }
                }
                
                pos = --i;
                break;
            }
        }
    }

    for(auto i : ans) cout << i;
    cout << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> s;

        cin >> N;
        
        for(int i=0;i<N;i++) cin >> v[i];
		
		solve();
    }

	return 0;
}