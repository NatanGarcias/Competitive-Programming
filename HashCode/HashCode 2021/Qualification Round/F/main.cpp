#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
  
typedef long long ll;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

//Lendo arquivo com a solução
ifstream solFile;

vector<int> qtd;
vector<double> ptg;

int D, I, S, V, F;

//Armazena dados do carro
struct Car{
	int id, pos; //id do carro, posição da rua que ele esta passando no array e bonus
	vector<int> ruas; //Ruas que o carro passa
};

//Armazena dados da rua
struct Rua{
	
	int id, l; //id e tamanho da rua
	int b, e; //Interseções de início e fim da rua
	string nome;

	/*Fila de carros esperando no fim da rua (first é o id e 
	second é o tempo que ele chega no fim da rua)*/
	queue<pii> fila; 
};

//Armazena dados da interseção
struct Inter{
	int id; //ID da interseção e luz acesa
	vector<int> ruas; //Ruas da interseção
};

//Armazena a solução
struct Sol{
	
	//Valor total da solucao
	ll valor;

	/*A posiçõa i contem um array de tempos das luzes
	
	Os tempos estão em array de pares, indicando a ordem as luzes
	First indica a posição da luz no array de ruas da interseção e
	second indica o tempo (second = 0 indica que aquela luz é sempre vermelha)*/

	//[1, 3, 2, 5]

	//[(2, 3), (1, 4), (0, 2), (3, 9)]

	vector<int> pos;
	vector<vector<pii>> tempos;
};

//Salva as mudancas de cor
struct Event{
	int t, inter; //Tempo e id do semáforo
	Event(int _t = 0, int _inter = 0) : t(_t), inter(_inter) {}
	bool operator<(const Event &e) const{
		if(t != e.t) return t < e.t;
		return inter < e.inter;
		//return pos < e.pos;
	}
	bool operator>(const Event &e) const{
		if(t != e.t) return t > e.t;
		return inter > e.inter;
		//return pos > e.pos;
	}
};

vector<Car> carros;
vector<Inter> inter;
vector<Rua> ruas;

//mapeia os nomes da ruas para seus ids
map<string, int> nomes;

//fila de eventos
priority_queue<Event, vector<Event>, greater<Event>> eventos;

//Solucao global
Sol solG;

void leitura(){
	cin >> D >> I >> S >> V >> F;

	inter.resize(I);
	ruas.resize(S);
	carros.resize(V);

	//Le as ruas
	for(int i = 0; i < S; i++){
		
		cin >> ruas[i].b >> ruas[i].e >> ruas[i].nome >> ruas[i].l;
		
		ruas[i].id = i;

		//Map dos nomes
		nomes[ruas[i].nome] = ruas[i].id;

		//Adiciona rua na intersecao
		inter[ruas[i].e].ruas.push_back(ruas[i].id);
	}

	//Le os carros
	for(int i = 0; i < V; i++){
		
		int N;
		string rua;
		cin >> N;

		carros[i].id = i;
		carros[i].pos = 0;

		for(int j = 0; j < N; j++){
			cin >> rua;
			carros[i].ruas.push_back(nomes[rua]);
		}
	}
}

void print(Sol &sol){
	
	int N = 0;
	
	//Contar quantas inter nao sao tudo vermelho
	for(int i = 0; i < I; i++){
		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				N++;
				break;
			}
		}
	}

	cout << N << "\n";

	for(int i = 0; i < I; i++){

		int M = 0;

		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				M++;
			}
		}

		if(M == 0) continue;

		cout << i << "\n";
		cout << M << "\n";

		for(int j = 0; j < sol.tempos[i].size(); j++){
			if(sol.tempos[i][j].second > 0){
				
				int pos = sol.tempos[i][j].first;
				int t = sol.tempos[i][j].second;

				int rua = inter[i].ruas[pos];

				cout << ruas[rua].nome << " " << t << "\n";
			}
		}
	}
}

void pre(){

	qtd.resize(S,0);
	ptg.resize(S,0);

	ll cnt = 0;

	vector<pii> tamanhos;
	for(int i=0;i<V;i++) tamanhos.pb(pii(carros[i].ruas.size(), i));

	sort(all(tamanhos));

	vector<bool> vis(V);
	for(int i=0;i<(9*V/10);i++){
		vis[ tamanhos[i].se ] = true;
	}

	for(int i=0;i<V;i++){
		if(!vis[i]) continue;

		for(int j=0;j<carros[i].ruas.size();j++){
			qtd[carros[i].ruas[j]]++;
			cnt++;
		}
	}

	for(int i=0;i<S;i++){
		ptg[i] = qtd[i]/(cnt * 1.0);
	}
}

void initial(){
	
	int repCiclo = 150;
	int segCiclo = D/repCiclo;

	solG.tempos.resize(I);
	solG.pos.resize(I);

	for(int i=0;i<I;i++){
		solG.tempos[i].resize(inter[i].ruas.size());
	}

	for(int i=0;i<I;i++){

		double acum = 0.0;

		for(int j=0;j<solG.tempos[i].size();j++){
			acum += ptg[inter[i].ruas[j]];
		}
		
		acum = 100/acum;

		for(int j=0;j<solG.tempos[i].size();j++){
			if(qtd[inter[i].ruas[j]]){
				solG.tempos[i][j] = make_pair(j, min(10 , max( 1, (int) (ceil( ( ( ptg[inter[i].ruas[j]] * acum ) / segCiclo ) ) ) ) ) );
			}
			else{
				solG.tempos[i][j] = make_pair(j, 0);
			}
		}
	}
}

int main(int argc, char *argv[]){

	leitura();

	pre();

	initial();
	
	print(solG);
	
    return 0;
}