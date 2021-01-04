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

//#define _DEBUG
// #ifdef _DEBUG
// #endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,H,K;

struct Trem{
    int h, m;

    Trem(){}
    Trem(int _h, int _m) : h(_h), m(_m) {}
};

vector<Trem> trem;
vector<int> nums, ans;
set<int> pos;

void solve(){

    int melhorPos = -1, qtd = INF;

    for(int i=0;i<trem.size();i++){
        nums.pb(trem[i].m);
    
        pos.insert(nums.back());
        pos.insert( (nums.back() + K) % M/2);
    }

    sort(all(nums));
        
    for(auto i : pos){

        int u, v;

        if(i + K <= M/2){
            u = (lower_bound(all(nums), i + K) - 1 - nums.begin()) + 1;
        }
        else{
            u = N;

            if(i+K-M/2 > *nums.begin()){
                u += (lower_bound(all(nums), i + K - M/2) - 1 - nums.begin()) + 1; 
            }
        }

        v = (upper_bound(all(nums), i) - nums.begin() );
     
        int aux = u - v;

        if(aux < qtd){
            qtd = aux;
            melhorPos = i;
        }
    }

    if(melhorPos + K >= M/2){
        cout << qtd << " " << melhorPos + K - M/2 << endl;
    }
    else{
        cout << qtd << " " << melhorPos + K << endl;
    }
    
    for(int i=0;i<trem.size();i++){
        int t = trem[i].m;
        
        if(t + K > M && melhorPos < t || t < melhorPos + K - M/2){
            ans.pb(i+1);
        }
        else if(melhorPos < t && t < melhorPos + K){
            ans.pb(i+1);
        }
    }

    for(int i=0;i<qtd;i++){
        if(!i)  cout << ans[i];
        else    cout << " " << ans[i];
    }
    cout << endl;
}

int main(){

	optimize;
	
    cin >> N >> H >> M >> K;

    for(int i=0;i<N;i++){
        int a,b;

        cin >> a >> b;

        if(b > M/2)             b = b - M/2;
        else if(b == M/2)       b = 0;

        trem.emplace_back(Trem(a,b));
    }
    
    solve();
 
	return 0;
}