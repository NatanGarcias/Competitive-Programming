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

void solve(){

    vector<int> l(26,0);

    for(auto i : s) l[i - 'a']++;
    
    sort(all(l));

    for(int i=N;i>=1;i--){

        vector<int> cic, vis(N,0);

        //Monta os ciclos para aquele tamanho
        for(int j=0;j<i;j++){
            if(!vis[j]){
                vis[j] = true;
                cic.pb(1);

                int k = (j + M) % i;
                while(!vis[k]){
                    vis[k] = true;
                    cic.back()++;
                    k = (k + M) % i;
                }
            }
        }

        //Vejo se consigo espalhar as letras pelos ciclos
        bool ok = true;
        vector<int> l2(l);

        while(!cic.empty()){
            if(l2.back() < cic.back()){
                ok = false;
                break;
            }
            else{
                l2.back() -= cic.back();
                cic.pop_back();
                sort(all(l2));
            }
        }

        if(ok){
            cout << i << endl;
            return;
        }
    }
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
    
        cin >> s;

		solve();
    }

	return 0;
}