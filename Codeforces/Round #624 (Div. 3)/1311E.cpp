#include<bits/stdc++.h>
using namespace std;

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
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 5010
#define MAXM 5015

ll N,D,T;

int v[MAXM];
int v2[MAXM];
int v3[MAXM];

void pre(){
	
	FOR1(i,MAXN){
		v[i+1] = (i*(i+1))/2;
		v3[i+1] = i;
	}

	int cont, cont2 = 1, x = 0;
	int valor = 0;
	
	while(cont2 < MAXN){
		
		cont = 0;
		
		valor++; 

		int j = 1 << ++x;

		while(cont2++ < MAXN && cont++ < j){
			v2[cont2] = v2[cont2-1] + valor;
		}
		cont2--;
	}
}

void solve(){
	
	if(	 D > v[N] || D < v2[N]){
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;

	multiset<int> ms;

	FOR1(i,N){
		ms.insert(v3[i]);
	}

	int cont = v[N];

	while(cont > D){
		auto it = ms.end();

		it--;
		int aux = *it;

		ms.erase(it);

		int h = 1;

		while(ms.count(h) >= (1 << h)){
			h++;
		}
		
		while(cont > D  && aux > h){
			cont--;
			aux--;
		}

		ms.insert(aux);
	}
	
	int aux;

	vector<int> sol;
	vector<int> altura(N,0);

	cont = 0;
	
	for(auto i:ms){
		cont++;
		if(!i) continue;
		if(!altura[i]){
			altura[i] = cont;
		}
	}

	for(auto i : ms){
		if(!i) continue;

		else{
			if(i == 1){
				sol.push_back(1);
				aux = 1;
			}else{
				if(i != aux) cont = 0; 
				
				aux = i;
				
				int temp = altura[i-1];

				for(int j=0;j<cont/2;j++){
					temp++;
				}
				
				sol.push_back(temp);

				cont++;
			}
		}
	}

	FOR(i,sol.size()-1){
		cout << sol[i] << " ";
	}cout << sol[sz(sol)-1] << endl;
}

int main(){

	cin >> T;

	pre();

	while(T--){
		cin >> N >> D;

		solve();
	}

	return 0;
}