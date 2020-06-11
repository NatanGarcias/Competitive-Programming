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

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct PT{
	ll x,y;
	PT(ll _x = 0, ll _y = 0) : x{_x}, y{_y}{}
	PT(const PT &p){ x = p.x, y = p.y;};

	PT operator+(const PT &p){ return PT(x+p.x,y+p.y); };
	PT operator-(const PT &p){ return PT(x-p.x,y-p.y); };
	PT operator*(int a){ return PT(x*a,y*a); };
	PT operator/(int a){ return PT(x/a,y/a); };

	bool operator<(const PT &p) const { return x < p.x; }
    bool operator==(const PT &p) const { return x == p.x && y == p.y; }
};

ll vet(PT p,PT q){ return p.x*q.x + p.y*q.y; }
ll det(PT p,PT q){ return p.x*q.y - p.y*q.x; }

struct Evento{
	PT e;
	int id,t;

	Evento(PT _e = PT(), int _id = -1, int _t = -1) : e{_e}, id{_id}, t{_t} {}
	bool operator<(Evento &E){
		if(e.x != E.e.x) return e.x < E.e.x;
		else if(t != E.t) return t < E.t;
		return e.y < E.e.y; 
	}
};

vector<int> q;
vector<pair<PT,PT>> retas;
vector<Evento> eventos;

struct CMP{
	bool operator()(int a, int b){
		PT p = retas[a].fi;
        PT q = retas[a].se;
        PT r = retas[b].fi;
        PT s = retas[b].se;

		//Ordenando os eventos ativos, ordena pelo ponto mais baixo primeiro
        if(p.x < r.x) return det(PT(p - r),PT(q - r)) > 0;
        return det(PT(r - p),PT(s - p)) < 0;
	}
};

set<int, CMP> ativos; //Guarda as retas que estão sendo processadas pelo sweep no momento
vector<int> up; //Guarda o id da reta que está acima da atual
vector<int> lowest; //Primeira reta acima de mim
vector<PT> dp; //Salva o Ponto mais acima para aquele id

PT climb(int x, int id){
	//Se a reta acima de mim é paralela ao eixo x
	if(retas[id].fi.y == retas[id].se.y) return PT(x,retas[id].fi.y);
	else if(dp[id] == PT()){ //subo nas retas inclinadas até chegar numa reta limite
		int next = (retas[id].fi.y > retas[id].se.y ? retas[id].fi.x : retas[id].se.x);
		dp[id] = climb(next, up[id]);
	}
	//Retorno a reta mais acima
	return dp[id];
}

void process(){
	ativos.insert(eventos[0].id);

	FOR(i,1,sz(eventos)){
		int id = eventos[i].id;
		int t = eventos[i].t;

		if(!t){
			ativos.insert(id);
			if(retas[id].fi.y > retas[id].se.y){
				auto it = ativos.find(id);
				up[id] = *(++it);
			}
		}else if(t == 2){
			ativos.insert(id);
			if(retas[id].fi.y < retas[id].se.y){
				auto it = ativos.find(id);
				up[id] = *(++it);
			}
			ativos.erase(id);
		}else{
			lowest[id] = *(ativos.begin());	
		}
	}
}

void queries(){
	FOR(i,0,M){
		if(lowest[i] == N+1){
			cout << q[i] << "\n";
		}else{
			PT p = climb(q[i], lowest[i]);
			if(p.y == INF){
				cout << p.x << "\n";
			}else{
				cout << p.x << " " << p.y << "\n";
			}
		}
	}
}

void solve(){
	process();
	queries();
}

int main(){
	optimize;
	
    while(cin >> N >> M){

		eventos.resize(2*N+M+2);
		retas.resize(N+1);
		dp.assign(N+1,PT());
		up.resize(N);
		lowest.resize(M);
		q.resize(M);

		FOR(i,0,N){
			cin >> retas[i].fi.x >> retas[i].fi.y;
			cin >> retas[i].se.x >> retas[i].se.y;

			if(retas[i].se < retas[i].fi) swap(retas[i].fi, retas[i].se);

			eventos[2*i] = Evento(retas[i].fi,i,0);
			eventos[2*i +1] = Evento(retas[i].se,i,2);
		}	
		
		retas[N] = make_pair(PT(-1,INF),PT(INF,INF));
		eventos[2*N] = Evento(PT(-1,INF),N,0);
		eventos[2*N+1] = Evento(PT(INF,INF),N,2);

		FOR(i,0,M){
			cin >> q[i];
			eventos[2*N+i+2] = Evento(PT(q[i],0),i,1);
		}	

		sort(all(eventos));
		solve();
    }

	return 0;
}