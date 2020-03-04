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
#define MAXN 200010

struct SWEEP{
	int y;
	int p,q;
	bool valor;
};

struct RETA{
	int r[4];
};

bool cmp(const SWEEP &a, const SWEEP &b){
	return a.y < b.y;
}

vector<SWEEP> sweep;
vector<RETA> reta;

ll N,P;
ll X1,X2,Y1,Y2;

int seg_C[4*MAXN];
int seg_S[4*MAXN];

ll ans, resp;

void build(){
	ms(seg_C);
	ms(seg_S);
}

void update(int p, int tl, int tr, int a, int b, bool z){

	if(a > tr || b < tl) return;
	
	else if(tl >= a && tr <= b){
		
		seg_C[p] += z ? 1 : -1;

		if(seg_C[p]) seg_S[p] = tr - tl + 1 ;
		else seg_S[p] = seg_S[2*p] + seg_S[2*p+1];
		return;

	}else{
		
		ll e = 2*p;
		ll d = 2*p+1;
		ll tm = (tl+tr)/2;
	
		update(e,tl,tm,a,b,z);
		update(d,tm+1,tr,a,b,z);

		if(seg_C[p]) seg_S[p] = tr - tl + 1;
		else seg_S[p] = seg_S[e] + seg_S[d];
	}
}

int query(){
	//Retorna a area ocupada no território
	//Como sempre vou querer a área do território total não preciso fazer lazy,
	// nem query para nodos abaixos
	return seg_S[1];
}

void geraSweep(ll x){
	
	FOR(i,N){
		ll a,b,c,d;

		a = reta[i].r[0];
		b = reta[i].r[1];
		c = reta[i].r[2];
		d = reta[i].r[3];

		sweep[2*i].y = max(b - x, Y1);
		sweep[2*i].p = max(a - x, X1);
		sweep[2*i].q = min(c + x, X2);
		sweep[2*i].valor = true;

		sweep[2*i+1].y = min(d + x,Y2);
		sweep[2*i+1].p = max(a - x, X1);
		sweep[2*i+1].q = min(c + x, X2);
		sweep[2*i+1].valor = false;

	}
	sort(all(sweep),cmp);
}

bool verifica(int x){

	geraSweep(x);
	build();

	int cont = 0;
	ans = 0;

	for(int i = Y1; i<Y2; i++){
		
		while(cont < sz(sweep) && sweep[cont].y <= i){	

			update(1, X1, X2, sweep[cont].p , sweep[cont].q - 1, sweep[cont].valor);
			
			cont++;
		}	

		ans+= query();
	}

	return ans >= resp;
}

int bb(){
	int l = 0, r = max(X2-X1,Y2-Y1);

	while(true){
		int m = (l+r)/2;

		if(l == r){
			return m;
		}else if(verifica(m)){
			r = m;
		}else{
			l = m+1;
		}
	}
}

int main(){

	cin >> N; 

	sweep.resize(2*N);
	reta.resize(N);

	FOR(i,N){
		cin >> reta[i].r[0] >> reta[i].r[1] >> reta[i].r[2] >> reta[i].r[3];
	}

	cin >> P;

	cin >> X1 >> Y1 >> X2 >> Y2;

	resp = (X2-X1)*(Y2-Y1);
	
	resp = (99LL + P * resp)/100;

	cout <<	bb() << endl;

	return 0;
}