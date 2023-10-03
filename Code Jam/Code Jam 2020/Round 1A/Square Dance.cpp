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
#define MAXN 200010

int T,N,M;
ll sum;

void vizEsq(int i, int j, const vector<set<int>> &sH, vector<pii> &vizinhos){

	if(sH[i].empty()) return;

	auto it = sH[i].upper_bound(j);

	if(it == sH[i].begin()) return;
	
	it--;
	vizinhos.pb(pii(i,*it));
}

void vizDir(int i, int j, const vector<set<int>> &sH, vector<pii> &vizinhos){

	if(sH[i].empty()) return;

	auto it = sH[i].lower_bound(j);

	if(it == sH[i].end()) return;
	
	vizinhos.pb(pii(i,*it));
}

void vizCima(int i, int j, const vector<set<int>> &sV, vector<pii> &vizinhos){

	if(sV[j].empty()) return;

	auto it = sV[j].upper_bound(i);

	if(it == sV[j].begin()) return;
	
	it--;

	vizinhos.pb(pii(*it, j));
}

void vizBaixo(int i, int j, const vector<set<int>> &sV, vector<pii> &vizinhos){

	if(sV[j].empty()) return;

	auto it = sV[j].lower_bound(i);

	if(it == sV[j].end()) return;

	vizinhos.pb(pii(*it, j));
}

void imprimi2(const vector<set<int>> &sH, const vector<set<int>> &sV){

	cout << "Horizontal: \n";
	FOR(i,0,N){
		for(auto j : sH[i]){
			cout << j << " ";
		}cout << endl;
	}

	cout << "Vertical: \n";
	FOR(i,0,M){
		for(auto j : sV[i]){
			cout << j << endl;
		}cout << endl;
	}
}

bool elimina(const vector<vector<int>> &m, vector<set<int>> &sH, vector<set<int>> &sV, set<pii> &posOlhar){

    vector<pii> posOlhar2;
    set<pii> posOlhar3;

	if(posOlhar.empty()){
		FOR(i,0,N){
			FOR(j,0,M){
					
				int cont = 0;

				vector<pii> vizinhos;
				vizinhos.reserve(4);

				if(j > 0) vizEsq(i,j-1, sH, vizinhos);                
				if(j < M-1) vizDir(i,j+1, sH, vizinhos);                
				if(i > 0) vizCima(i-1,j, sV, vizinhos);
				if(i < N-1) vizBaixo(i+1,j, sV, vizinhos);

				for(auto i: vizinhos) cont+= m[ i.fi ][ i.se ];

				if(cont > m[i][j] * sz(vizinhos)){
					
					posOlhar2.pb(pii(i,j));

					sum -= m[i][j];

					for(auto i : vizinhos)	posOlhar3.insert(i);
				}
			}
		}
	}else{
		for(auto k : posOlhar){
			int i = k.fi;
			int j = k.se;

			if(sH[i].find(j) != sH[i].end()){
				
				int cont = 0;

				vector<pii> vizinhos;
				vizinhos.reserve(4);

				if(j > 0) vizEsq(i,j-1, sH, vizinhos);                
				if(j < M-1) vizDir(i,j+1, sH, vizinhos);                
				if(i > 0) vizCima(i-1,j, sV, vizinhos);
				if(i < N-1) vizBaixo(i+1,j, sV, vizinhos);

				for(auto i: vizinhos) cont+= m[ i.fi ][ i.se ];

				if(cont > m[i][j] * sz(vizinhos)){
					
					posOlhar2.pb(pii(i,j));

					sum -= m[i][j];

					for(auto i : vizinhos) posOlhar3.insert(i);
				}
			}
		}
	}
    
	if(posOlhar3.empty()) return false;

    for(auto k : posOlhar2){

    	int i = k.fi;
    	int j = k.se;

	    sH[i].erase(j);
    	sV[j].erase(i);
    }

    posOlhar = posOlhar3;
	return true;    
}

void constroi(const vector<vector<int>> &m,vector<set<int>> &sH, vector<set<int>> &sV){

	FOR(i,0,N){
		FOR(j,0,M){
			sH[i].insert(j);
		}
	}

	FOR(i,0,M){
		FOR(j,0,N){
			sV[i].insert(j);
		}
	}
}

void solve(const vector<vector<int>> &m, int caso){

    ll ans = 0;

    bool batalha = true;

    vector<set<int>> sH(m.size());
	vector<set<int>> sV(m[0].size());

	set<pii> posOlhar;

    constroi(m,sH,sV);

    while(batalha){
        
        ans += sum;

        batalha = elimina(m,sH,sV,posOlhar);
    }

    cout << "Case #" << caso << ": " <<  ans << endl;
}

int main(){

    optimize;
	cin >> T;

    FOR(i,1,T+1){
		cin >> N >> M;

        vector<vector<int>> m (N,vector<int>(M,0));

		sum = 0;
        FOR(i,0,N){
            FOR(j,0,M){
                cin >> m[i][j];
				sum+= m[i][j];
            }
        }
		solve(m,i);
    }
	return 0;
}