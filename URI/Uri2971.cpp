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
#define MAXM 2029
#define MAXL 20

int N,M;
string s;

struct Comp{
	int v[13];
	bool c;
};

vector<Comp> jogador;

bool venci(int p){

	FOR(j,13){
		if(jogador[p].v[j] == 4 && !jogador[p].c)
			return true;
	}

	return false;
}

int passe(int p, bool &curinga){

	if(curinga && jogador[p].c){
		jogador[p].c = false;
		curinga = false;
		return 13;
	}

	if(jogador[p].c){
		curinga = true;
	}

	for(int i=1;i<=4;i++){	
		for(int j=0;j<13;j++){
			if(jogador[p].v[j] == i){
				jogador[p].v[j]--;
				return j;
			}
		}
	}
}

void recebo(int p, int j){
	if(j == 13){
		jogador[p].c = true;
		return;
	}

	jogador[p].v[j]++;
}

void imprimi(){

	FOR(i,N){
		FOR(j,13){
			cout << jogador[i].v[j] << " ";
		}
		cout << jogador[i].c << endl;
	}cout << endl;
}

void solve(){

	bool ganho = false;
	bool curinga = false;

	//Se alguém ganho no início
	FOR(i,N){
		if(venci(i)){
			cout << i+1 << endl;
			return;
		}
	}

	//Simula até alguem ganhar

	int quem, carta;

	int cont = 0;
	while(true){

		quem = M%N;

		carta = passe(quem ,curinga);

		if(carta == 13) curinga = false;

		recebo( (quem+1)%N, carta );

		if(venci(M % N)){
			cout << (M % N) +1 << endl;
			return;
		}
		M++;
	}
	
	cout << (M % N) +1 << endl;
}

int main(){

	cin >> N >> M;

	M--;

	FOR(i,N){

		Comp e;
		
		ms(e.v);

		e.c = false;

		if(i == M){
			e.c = true;
		}

		cin >> s;

		FOR(j,4){

			if(s[j] == 'A') e.v[0]++;
			else if(s[j] == '2') e.v[1]++;
			else if(s[j] == '3') e.v[2]++;
			else if(s[j] == '4') e.v[3]++;
			else if(s[j] == '5') e.v[4]++;
			else if(s[j] == '6') e.v[5]++;
			else if(s[j] == '7') e.v[6]++;
			else if(s[j] == '8') e.v[7]++;
			else if(s[j] == '9') e.v[8]++;
			else if(s[j] == 'D') e.v[9]++;
			else if(s[j] == 'Q') e.v[10]++;
			else if(s[j] == 'J') e.v[11]++;
			else if(s[j] == 'K') e.v[12]++;
		}

		jogador.push_back(e);
	}

	solve();

	return 0;
}