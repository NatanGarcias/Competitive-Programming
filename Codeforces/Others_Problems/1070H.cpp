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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;
map<string, vector<string>> mapa;

void add(){
    int n = sz(s);

    string aux;
    set<string> conj;

    FOR(i,0,n){
        FOR(j,i,n){
            aux += s[j];
            if(conj.find(aux) == conj.end()){ 
                mapa[ aux ].pb(s);
                conj.insert(aux);
            }
        }
        aux.clear();
    }
}

void query(){

    if(mapa[s].empty()){
        cout << "0 -\n";
    }else{
        cout << mapa[s].size() << " " << mapa[s].back() << endl;
    }
}

int main(){

	cin >> N;
    
    FOR(i,0,N){
        cin >> s;
        add();
    }

    cin >> M;

    FOR(i,0,M){
        cin >> s;
        query();
    }

	return 0;
}