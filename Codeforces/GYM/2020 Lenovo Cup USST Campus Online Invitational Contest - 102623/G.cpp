#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; } 
typedef long long int ll;
typedef pair<ll,ll> pii;

#define fi first 
#define se second 
#define MAXN 10000100
#define mod 998244353

ll N,P,X,Y,Z,B;
ll v[MAXN];
ll aux;

struct MonStack{
	stack<pii> p;
	ll valP;
	
	MonStack(){
		valP = 0;
	}

	void sumMinP(ll x, ll i){
		
		int j = i;
		bool ok = true;

        x %= mod;

		while(!p.empty() && p.top().fi > x){

			pii t = p.top();
			p.pop();

			ok = false;

			int pos2 = 0;
			if(!p.empty()){
				pii a = p.top();
				pos2 = a.se +1; 
			} 	

			valP = ( (valP + mod) - (j - pos2) * v[t.se])%mod;

			j = pos2;
		}

		if(!ok) valP = ( valP + (i - j) * x + mod)%mod;

		valP = (valP + x + mod)%mod;

		aux = (aux + valP) % mod;

		p.push(pii(v[i],i));
	}

};

void solve(){

	MonStack ms;

	ll ans = 0;
	ll respAnt = B;
	ll valAnt = B;

	v[0] = B;

	for(int i=0;i<N;i++){

		ms.sumMinP(valAnt,i);

		respAnt = aux%P;

		valAnt = (((X * respAnt) %P ) + ((Y * valAnt) %P ) + Z) %P;

		v[i+1] = valAnt;
    
    	ans ^= aux;
	}

	cout << ans << endl;
}

int main(){

	cin >> N >> P >> X >> Y >> Z >> B;

	solve();

	return 0;
}