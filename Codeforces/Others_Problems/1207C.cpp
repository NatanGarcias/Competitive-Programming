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
#define MAXN 3500

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,X,Y,a,b;
string s;

void solve(){
    
    bool ok = false;
    ll ptr;

    FOR(i,0,N){
        if(ok){
            if(s[i] == '1'){

                if(2LL*a + b >= (i-ptr-1)*b){
                	FOR(j,ptr+1,i){
                        s[j] = '1'; 
                    }    
                }
                ptr = i;
            }
        }else if(s[i] == '1'){
            ok = true;
            ptr = i;
        }
    }
    
    ll ans = 0;
    ll cont = 0, cont2 = 0;

    FOR(i,0,N){
        if(s[i] == '1'){
            cont++;
        }

        if(i<N-1 && s[i] == '0' && s[i+1] == '1'){
            cont2++;
        }
        if(i<N-1 &&  s[i] == '1' && s[i+1] == '0'){ 
            cont++;
            cont2++;
        }
    }

    ans = (cont+N+1)*b + (cont2+N)*a;

    cout << ans << endl;
}

int main(){

    cin >> T;

    while(T--){
        cin >> N >> a >> b;
        cin >> s;

        solve();
    }

	return 0;
}
