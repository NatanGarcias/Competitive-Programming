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

struct Luta{
    int dif, l, m;

    Luta() {}
    Luta(int _dif, int _l, int _m) : dif(_dif), l(_l), m(_m) {}

    bool operator<(const Luta &a ) const{
        if(dif != a.dif) return dif > a.dif;
        else if(l != a.l) return l > a.l;
        else return m > a.m;
    }
};

Luta L[MAXN];

void imprimi(){
    FOR(i,0,N){
        cout << L[i].dif << " " << L[i].l << " " << L[i].m << endl;
    }
    cout << endl;
}

void solve(){

    sort(L,L+N);

    ll ans = 0, qt = 0;

    FOR(i,0,N){
        if(!i){
            ans = L[i].l;
            qt = L[i].dif;
        }else if(qt < L[i].l){
            ans += L[i].l - qt;
            qt = L[i].l - L[i].m;
        }else{
            qt -= L[i].m;
        }
    }

    cout << ans << endl;

}

int main(){

	optimize;
	
	cin >> N;

    FOR(i,0,N){
        cin >> L[i].l >> L[i].m;

        L[i].dif = L[i].l - L[i].m;
    }

    solve();

	return 0;
}