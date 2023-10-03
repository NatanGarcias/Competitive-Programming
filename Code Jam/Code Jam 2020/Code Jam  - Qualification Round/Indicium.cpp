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
#define MAXN 55

vector<int> adjU[MAXN];
int pairU[MAXN], pairV[MAXN];
bool vis[MAXN];
int m, n;

bool dfs(int u) {
    vis[u] = true;
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (!vis[pairV[v]] && dfs(pairV[v])) {
            pairV[v] = u; pairU[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    for (int u = 1; u <= m; u++) {
        memset(&vis, false, sizeof vis);
        if (pairU[u]==0 && dfs(u)) result++;
    }
    return result;
}

ll T,N,M;
int v[MAXN][MAXN];

void imprimiD(vector<int> &d){
	FOR(i,0,N){
		cout << d[i] << " ";
	}cout << endl;
}

void imprimi(){	
	FOR(i,0,N){
		FOR(j,0,N){
			cout << v[i][j] << " \n"[j==N-1];
		}
	}
}

void diagonal(vector<int> &d){
	
	int aux = M-N;
	int cont = 1;
	int iter = 0;
	
	if(N == 3){ 
		aux = 0;
		d[0] = d[1] = d[2] = M/N;
	}

	while(aux > 0){
		if(cont == 1){
			d[0]++; d[1]++;
			aux -= 2;
			cont += 2;
		}else if(cont > N*N -N-2){
			aux--;
			d[N-1] = d[N-2] = N;
			cont += 2;
		}else if(cont > N*N - 2*N ){
			aux--;
			d[N-1]++;
			cont += 1;
		}else{
			aux--;
			d[iter]++;
			cont += 1;
			if(d[iter] == N) iter++;
			
		}
	}
}

void preenche(int num){
	vector<bool> d(N,true);

	FOR(i,0,N) if(v[i][i] == num) d[i] = 0;

	FOR(i,1,N+1) adjU[i].clear();
	
	FOR(i,0,N){
		FOR(j,0,N){
			if(d[i] && d[j] && !v[i][j]){
				adjU[i+1].pb(j+1);
			}
		}
	}

	m = n = N;

	int aux = kuhn();
	
	FOR(i,0,N){
		if(pairU[i+1]) v[ i ][ pairU[i+1]-1 ] = num;
	}

}

void preenche(vector<int> & d){

	FOR(i,0,N)	v[i][i] = d[i];

	vector<int> nums(N+1,N);

	FOR(i,0,N) nums[ d[i] ]--;

	priority_queue<pii> pq;

	FOR(i,1,N+1) if(nums[i]) pq.push(pii(-nums[i],i));

	while(!pq.empty()){
		int num = pq.top().se;
		pq.pop();

		preenche(num);
	}
}

void solve(int caso){

	if( M < N || M > N*N || M == N+1 || M == N*N -1 || (N==3 && (M == 5 || M == 7))){
		cout << "Case #" << caso << ": " << "IMPOSSIBLE\n";
		return;
	}
	
	cout << "Case #" << caso << ": " << "POSSIBLE\n";

	vector<int> d(N,1);

	ms(v,0);
	diagonal(d);
	preenche(d);
	imprimi();
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N >> M;

		solve(i);
    }

	return 0;
}