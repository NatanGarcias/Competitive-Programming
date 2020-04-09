#include<bits/stdc++.h>
using namespace std;

//K é o número de pizzas
//N é a capacidade
//Vi armazena a quantidade de pedaços da pizza i

#define MAXN 100010
#define FOR(x,n) for(int x=0;x<n;x++)
#define pii pair<int,int>
#define fi first
#define se second
typedef unsigned long long ull;

int N,K;
int v[MAXN];
int valS = 0;
map<int,int> m;
multiset<int> solG;

void leitura(){
    FOR(i,K){
        cin >> v[i];
    }
}

void mapa(){

    FOR(i,K){
        m[v[i]] = i;
    }
}

bool tempo(clock_t t, long double tempMax){
	
	t = clock() - t;
	
	long double ti = (((long double)t)/CLOCKS_PER_SEC);
	
	if(ti >= tempMax){
		return false;
	}
	
	return true;
}

double quantoT(clock_t t){
	
	t = clock() - t;
	
	long double ti = (((long double)t)/CLOCKS_PER_SEC);
	
	return ti;
}

void imprimir(){
    
    // cout << "Esperado: " << N << endl;
    // cout << "Solucao: " << valS << endl;
    // cout << "Diferenca: " << N-valS << endl;
    
    cout << solG.size() << endl;
    
    auto it = solG.begin();

    int ant = -1;
    int pos = 1;
    ull tot = 0;

    FOR(i,solG.size()){
    	if( (*it) == ant ){
    		cout << m[ (*it) ] - pos <<  " \n"[i==solG.size()-1];
			pos++;
    	}else{
    		ant = (*it);
	    	pos = 1;

	        cout << m[(*it)] << " \n"[i==solG.size()-1];

	    }
        it++;
    }
}

void knapsack(){

    int dp[K+1][N+1];
    mapa();
    
    FOR(i,K+1){
        FOR(j,N+1){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(v[i-1] <= j){
                dp[i][j] = max(v[i-1] + dp[i-1][j- v[i-1]],
                                dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int w = N;
    int res = dp[K][N];

    valS = res;
    
    for(int i=K; i>0 && res > 0; i--){
        if(res == dp[i-1][w])
            continue;
        else{
            solG.insert(v[i-1]);
        
            res-= v[i-1];
            w-= v[i-1]; 
        }
    }

    imprimir();
}

bool add(multiset<int> &nS, multiset<int> &sol, int &n, int &val){

	auto it = nS.lower_bound(n);

    int aux = (*it);
    if(it == nS.end()){
    	return false;
    }else if(n <= aux){
        sol.insert((-aux));
        val -= aux;

        n =  n - aux ;
        nS.erase( nS.find(*it) );
        return true; 
    }

    return false;
}

bool add_with_Tabu(multiset<int> &nS, multiset<int> &sol,vector<long long> &tabu, int &n, int &val, int iter){

	auto it = nS.lower_bound(n);

    int aux = (*it);

    if(it == nS.end()){
    	return false;
    }	
	
	while(it != nS.end()){

		aux = (*it);

        if(iter >= tabu[ m[-aux]]){
			sol.insert( -aux );
	        val -= aux;

	        n =  n - aux ;
	        nS.erase(nS.find(*it));
	        return true;
		}
        it++;
	}

	return false;
}

void contrutivoGreedy(multiset<int> &nS, multiset<int> &sol){
    
    int n = -N;
    int cont = 0;

    int val = 0;

    while(add(nS,sol,n,val));

    valS = val;
}

void BT(multiset<int> &nS){

	srand(time(NULL));

	int n =  - N + valS;
	int best = valS;

	int iterM = 0;
	ull iter = 0;

	multiset<int> sol;
	sol = solG;

	vector<long long> tabu(K,0);
	
	clock_t t = clock();
	
	while(tempo(t,1200.0)){

		iterM++;
		iter++;

		if(valS == N){
			break;
		}

		int itens = rand()%15 + 3;

		while(itens--){
			if(sol.empty()) break;

			int pos = rand()%sol.size();
			
			auto it = sol.begin();
			
			for(int i=0;i<pos;i++){
				if(it != sol.end()){
					it++;
				}
			}

			tabu[ (*it) ] +=3;

			nS.insert( -v[(*it)] );

			best -= v[*it];

			sol.erase(sol.find(*it));
		}

		n = -N + best;
	
		while(add_with_Tabu(nS,sol,tabu,n,best,iter));
			
		if(best > valS){
			iterM = 0;
			solG = sol;
			valS = best;
		}
	}
}

void heuristics(){

    mapa();

    multiset<int> nS;
	multiset<int> sol;

    FOR(i,K){
        nS.insert(-v[i]);   
    }

    contrutivoGreedy(nS,sol);
	    
    solG = sol;

    if(valS == N){
		imprimir();    	
    }else{
    	BT(nS);

    	imprimir();
    }
}

int main(){

    cin >> N >> K;

    ull C = (ull)N*(ull)K;

    leitura();

    if(C < pow(10,7)){
        //cout << "Exact\n";
        knapsack();
    }else{
        //cout << "Don't exact\n";
        heuristics();
    }
    return 0;
}