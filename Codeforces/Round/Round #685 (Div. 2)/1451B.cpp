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
string s;
int a,b;

void solve(){

    //Indo
    int cnt = a;
    int pulo = false;

    for(int i = 0 ;i < s.size(); i++){
        if(s[i] == s[cnt]){
            cnt++;

            if(cnt == b+1){
                for(i = b+1; i < s.size();i++){
                    if(s[i] == s[b]) {
                        pulo = true;
                        i = s.size();
                    }
                }
            }
        }
        else{
            if(cnt != a) pulo = true;
        }
    }

    if(cnt != b+1){
        cout << "NO\n";
        return;
    }
    if(cnt == b+1 && pulo){
        cout << "YES\n";
        return;
    } 

    //Voltando
    cnt = b;
    pulo = false;

    for(int i = s.size()-1 ;i >= 0; i--){
        if(s[i] == s[cnt]){
            cnt--;

            if(cnt == a-1){
                for(i = a-1; i>=0;i--){
                    if(s[i] == s[a]) {
                        pulo = true;
                        i = 0;
                    }
                }
            }
        }
        else{
            if(cnt != b) pulo = true;
        }
    }

    if(cnt == a-1 && pulo){
        cout << "YES\n";
        return;
    }

    cout << "NO\n"; 

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
    
        cin >> s;

        for(int i=0;i<M;i++){            
            cin >> a >> b;

            a--, b--;

            solve();
        }
		
    }

	return 0;
}