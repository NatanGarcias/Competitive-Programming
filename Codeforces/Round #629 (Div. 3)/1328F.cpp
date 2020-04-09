#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<ll,ll>
#define fi first 
#define se second 

#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x33ffffff
#define INFLL 0x33ffffffffffffff

#define mod %1000000007

#define MAXN 200010

ll N,K,a;

struct Dif{
    ll q, c, d;

    Dif() : q{0}, c{0}, d{0} {}
    Dif(ll _q, ll _c, ll _d) : q{_q}, c{_c}, d{_d} {}
};

set<ll> s;
map<ll,ll> m;
multiset<ll> ms;

void solve(){

    int n = sz(s);

    vector<Dif> vai(n);
    vector<Dif> vem(n);
    ll cont, resp, valorAnt, pos; 

	//Resposta indo
	priority_queue<pii> pq;

	for(auto i : s){
		pq.push({-i, ms.count(i) } );
	}
    
    cont = pq.top().se;
    valorAnt = 0;
    resp = 0;
    pos = 0;
    
    Dif aux(cont,resp, valorAnt);

    vai[pos] = aux;
    pos++;

    FOR(i,0,n-1){
        auto u = pq.top();
        pq.pop();

        pii v;

        if(pq.empty()){
            v = (pii(u.fi , 0));
        }else{
            v = pq.top();
        }
        valorAnt = (-1)*v.fi - (-1)*u.fi;

        if(cont >= K){
            vai[pos] = vai[pos-1];
        }else if(cont + v.se >= K){
            resp = resp + valorAnt*(K - v.se);
            cont = K;

            Dif aux2(cont, resp, valorAnt);
            vai[pos] = aux2;
        }else{
            resp = resp + (valorAnt*cont);
            cont = cont + v.se;

            Dif aux2(cont, resp, valorAnt);
            vai[pos] = aux2;
        }
        pos++;
    }

    //Resposta voltando 
    while(pq.size()) pq.pop();
    
    for(auto i : s){
		pq.push({i, ms.count(i) } );
	}
    
    cont = pq.top().se;
    valorAnt = 0;
    resp = 0;
    pos = n-1;
    
    Dif aux3(cont, resp, valorAnt);

    vem[pos] = aux3;
    pos--;

    FOR(i,0,n-1){

        auto u = pq.top();
        pq.pop();
        auto v = pq.top();
        
        valorAnt = u.fi - v.fi;

        if(cont >= K){
            vem[pos] = vem[pos+1];
        }else if(cont + v.se >= K){
            resp = resp + valorAnt*(K - v.se);
            cont = K;

            Dif aux2(cont, resp, valorAnt);
            vem[pos] = aux2;
        }else{
            resp = resp + valorAnt*cont;
            cont = cont + v.se;

            Dif aux2(cont, resp, valorAnt);
            vem[pos] = aux2;
        }
        pos--;
    }

	//Indo e voltando
    vector<ll> sol(n,INFLL);
    
    sol[0] = vai[n-1].c;
    sol[n-1] = vem[0].c;
   
    FOR(i,1,n-1){
        ll faltamA = K - vai[i].q;
        ll gasteiA = vai[i].c + vem[i+1].c;
        gasteiA += faltamA * vem[i].d;
        
        if(vem[i].d > 1)
            gasteiA += (vem[i+1].q - faltamA )* (vem[i].d-1);
 
        ll faltamB = K - vem[i].q;
        ll gasteiB = vem[i].c + vai[i-1].c;
        gasteiB += faltamB * vai[i].d;
        
        if(vai[i].d > 1)
            gasteiB += (vai[i-1].q - faltamB) * (vai[i].d-1);

        sol[i] = min( gasteiA, gasteiB ); 
    }
    
    sort(all(sol));

    cout << sol[0] << endl;

}

int main(){

    optimize;

    cin >> N >> K;

    FOR(i,0,N){
        cin >> a;
        s.insert(a);
        ms.insert(a);
    }

    auto it = s.begin();
    
    //Faço um map dos números e vejo se a resposta já está certa
    FOR(i,0,sz(s)){
        if(ms.count(*it) >= K ){
            cout << 0 << endl;
            return 0;
        }
        m[ (*it) ] = i;
        it++;
    }

    solve();
}