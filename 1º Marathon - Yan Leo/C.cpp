#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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
#define MAXN 1000010

struct SWEEP{
    int c,f,v;
    
    SWEEP(int _c, int _f, int _v): c{_c}, f{_f}, v{_v} {}
    
    bool operator<(const SWEEP&a) const{
        if(c < a.c) return true;
        if(c == a.c && (f < a.f)) return true;
        return false;
    }
};

struct LINHA{
    int c,f,v;
    
    LINHA(int _c, int _f, int _v): c{_c}, f{_f}, v{_v} {}
    
    bool operator<(const LINHA&a) const{
        if(f < a.f) return true;
        return false;
    }
};

int T,N,M,K;
vector<SWEEP> sweeps;

bool verifica(ll x){
    multiset<LINHA> process;
    
    ll maior = 0;
    ll atual = 0;
    int cont = 0;

    FOR(i,0,N){
        
        atual = 0;

        while(cont < sz(sweeps) && i >= sweeps[cont].c){
            
            LINHA a(sweeps[cont].c, sweeps[cont].f, sweeps[cont].v);

            process.insert(a);
            cont++;
        }
        
        while(true){
            if(process.empty()){
                break;
            }else{
                auto it = process.begin();
                if( (*it).v > ( x - atual)){
                    if( (*it).f <= i) return false;
                    else{
                        ll aux = ( (*it).v - (x - atual) );

                        LINHA a( (*it).c , (*it).f, aux );

                        process.erase(process.begin());
                        process.insert(a);
                        break;
                    }
                }else if((*it).v == ( x - atual)){
                    process.erase(process.begin()); 
                    break;
                }
                else{
                    atual = atual + (*it).v;
                    process.erase(process.begin()); 
                }
            }
        }
    }

    if(!process.empty()) return false;
    return true;
}

ll bb(){
    ll l = 0, r = 1000000000000000001;

    while(true){
        ll m = (l+r)/2;

        if(l>=r){
            return m;
        }else if( verifica(m) ){
            r = m;
        }else{
            l = m+1; 
        }
    }
}

void solve(){

    sort(all(sweeps));

    ll ans = bb();

    cout << ans << endl;
}

int main(){

    cin >> N >> M;

    int a,b,c;

    FOR(i,0,M){
        cin >> a >> b >> c;

        a--; b--; 
        sweeps.emplace_back(a,b,c);
    }

    solve();
}