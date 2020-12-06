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
#define MAXN 55

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<bool> h, v;

void solve(){

    int cnt = 0, cnt2 = 0;

    for(auto i : h) if(!i) cnt++;
    for(auto i : v) if(!i) cnt2++;

    int ans = min(cnt,cnt2);

    if(ans & 1)  cout << "Ashish\n";
    else         cout << "Vivek\n"; 
}

int main(){

	optimize;
	
	cin >> T;

    int aux = 0;

    while(T--){
		cin >> N >> M;

        h.clear();
        v.clear();

        h.assign(N,0);
        v.assign(M,0);

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                int a;
                cin >> a;

                if(a) {
                    h[i] = true;
                    v[j] = true;
                }
            }
        }

		solve();
    }

	return 0;
}