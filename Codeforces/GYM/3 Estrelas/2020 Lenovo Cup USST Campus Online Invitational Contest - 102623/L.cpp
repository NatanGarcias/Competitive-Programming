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

#define mod 998244353LL
#define MAXN 12

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int v[MAXN];

void solve(){

    vector<int> fim;
    vector<string> ans;

    for(int i=0;i<99;i+=4){
        if(i == 48 || i == 4 || i == 8) continue;
        fim.pb(i);
    }

    vector<pii> diminui;

    FOR(i,0,sz(fim)){
        if(fim[i] == 0){
            if(v[0] < 2 ) continue;

            v[0] -= 2;
            diminui.pb(pii(0,2));
        }
        else if(fim[i] == 44){
            if(v[4] < 2 ) continue;

            v[4] -= 2;
            diminui.pb(pii(4,2));
        }
        else if(fim[i] == 88){
            if(v[8] < 2 ) continue;

            v[8] -= 2;
            diminui.pb(pii(8,2));
        }
        else{
            if(v[ fim[i]/10 ] < 1) continue;
            if(v[ fim[i]%10 ] < 1) continue;

            v[fim[i]/10] -= 1;
            diminui.pb(pii(fim[i]/10,1));            
            
            v[fim[i]%10] -= 1;
            diminui.pb(pii(fim[i]%10,1));            
        }

        string aux;

        for(int j=9;j>=0;j--){
            FOR(k,0,v[j]){
                aux.pb( (char)(j + '0'));
            }
        }

        for(auto l : diminui){
            for(int m=0;m<l.se;m++){
               aux.pb( (char)(l.fi + '0'));
                v[ l.fi ]++;
            }
        }

        int ptr = 0;
        
        while(ptr < aux.size() && aux[ptr] == '0') ptr++;
        
        string aux2(aux.begin()+ptr,aux.end());
        aux = aux2;

        if(aux.empty()) aux.pb('0');

        ans.pb(aux);
        diminui.clear();
    }

    if(ans.empty()){
        if(v[8] == 1) cout << 8 << endl;
        else if(v[4] == 1) cout << 4 << endl;
        else if(v[0] == 1) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }
    
    sort(all(ans));
    reverse(all(ans));
    
    cout << ans[0] << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){

        FOR(i,0,10)
            cin >> v[i];
		
		solve();
    }

	return 0;
}