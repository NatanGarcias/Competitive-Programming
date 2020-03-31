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

#define MAXN 110
#define MAXM 1010

int T,N,M;

pii v[MAXM];
int m[MAXN][MAXN];

int cal(int x, int y){

	set<int> s;

	//Vertical
	FOR(i,1,x){
		s.insert(m[i][y]);
	}

	//Horizontal
	FOR(i,0,y){
		s.insert(m[x][i]);
	}

	//Diagonal
	FOR(i,1,min(x,y)+1){
		s.insert(m[x-i][y-i]);
	}

	FOR(i,0,MAXM){
		if(s.find(i) == s.end()){
			return i;
		}
	}

}

void pre(){

	FOR(i,0,102){
		FOR(j,0,102){
			if(!i || !j || i==j){
				m[i][j] = INF;				
			}else{
				m[i][j] = cal(i,j);
			}
		}
	}
}

void imprimi(){
	FOR(i,0,40){
		FOR(j,0,40){
			cout << setw(3) << m[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void solve(){
	int ans = 0;

	FOR(i,0,T){
		if(m[v[i].fi][v[i].se] == INF){
			ans = 1;
			break;
		}
		ans = ans ^ m[v[i].fi][v[i].se];
	}

	if(ans > 0)	cout << "Y\n";
	else 	cout << "N\n"; 
}

int main(){

	pre();

	cin >> T;

	FOR(i,0,T)	cin >> v[i].fi >> v[i].se;
	solve();

	return 0;
}