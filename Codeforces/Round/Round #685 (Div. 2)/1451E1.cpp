#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
vector<int> ans;
map<vector<int>, vector<int> > mapa;

void preCalc(){
	vector<int> aux, aux2;

	aux = {0,0,0}; 
	aux2 = {0,0,0,0,0};
	mapa[aux2] = aux;

	aux = {0,0,1}; 
	aux2 = {0,0,1,1,1};
	mapa[aux2] = aux;

	aux = {0,1,0}; 
	aux2 = {1,1,0,0,1};
	mapa[aux2] = aux;

	aux = {0,1,1}; 
	aux2 = {1,1,1,1,1};
	mapa[aux2] = aux;

	aux = {1,0,0}; 
	aux2 = {1,1,1,1,0};
	mapa[aux2] = aux;

	aux = {1,0,1}; 
	aux2 = {1,1,1,0,1};
	mapa[aux2] = aux;

	aux = {1,1,0}; 
	aux2 = {1,0,1,1,1};
	mapa[aux2] = aux;

	aux = {1,1,1}; 
	aux2 = {1,0,1,0,1};
	mapa[aux2] = aux;
}

int query(int id, int a, int b){
	if(!id){
		cout << "OR " << a << " " << b << endl;
	}
	else if(id == 1){
		cout << "XOR " << a << " " << b << endl;
	}
	else{
		cout << "AND " << a << " " << b << endl;
	}

	int c;
	cin >> c;

	return c;
}

void resp(){
	cout << '!';

	for(auto i : ans) cout << " " << i;
	cout << endl; 
}

void solve(){

	//Descobrindo os 3 primeiros
	preCalc();

	int a = query(0,1,2);
	int b = query(1,1,2);
	int c = query(0,1,3);
	int d = query(1,1,3);
	int e = query(0,2,3);

	int v[3] = {0};

	for(int i = 20;i>=0;i--){
		vector<int> aux;

		if(a & (1 << i)) aux.pb(1);
		else aux.pb(0);

		if(b & (1 << i)) aux.pb(1);
		else aux.pb(0);

		if(c & (1 << i)) aux.pb(1);
		else aux.pb(0);

		if(d & (1 << i)) aux.pb(1);
		else aux.pb(0);

		if(e & (1 << i)) aux.pb(1);
		else aux.pb(0);

		vector<int> aux2 = mapa[aux];

		for(int j=0;j<3;j++) if(aux2[j]) v[j] = v[j] | (1 << i);
	}

	for(int j=0;j<3;j++) ans.pb(v[j]);

	//Descobrindo o resto
	for(int i=3;i<N;i++){
		int aux = query(1,i,i+1);

		ans.pb(ans.back() ^ aux);
	}

	resp();
}

int main(){
	
	cin >> N;
	
	solve();
    
	return 0;
}