#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M,K;
set<char> s;
multiset<char> ms;

void solve(){

    string ans;

    if(s.size() == 1){
        FOR(i,0, (N+M-1)/M){
            ans.pb( (*s.begin()));
        }
        cout << ans << endl;
    }else if(s.size() == 2 &&  ( ms.count(*s.begin()) == M ) ){
        int cont = 0;
        for(auto i : ms){
            if( !(cont++ % M)){
                ans.pb(i);
            }
        }
        cout << ans << endl;
    }else{
        string ans2;

        int cont = 0;

        for(auto i : ms){
            if(!cont){
              ans.pb(i);
            }
            else if (cont < M){
                ans2 = i;
            }else{
                ans.pb(i);
            }

            cont++;
        }
        ans = max(ans,ans2);
        cout << ans << endl;
    }
}

int main(){

    optimize;

	cin >> T;

    while(T--){
        cin >> N >> M;

        s.clear();
        ms.clear();

        FOR(i,0,N){
            char k;

            cin >> k;

            s.insert(k);
            ms.insert(k);
        }

		solve();
    }

	return 0;
}