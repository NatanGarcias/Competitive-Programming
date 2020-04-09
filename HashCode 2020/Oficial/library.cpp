#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define endl "\n"
#define INF 2000000020
#define MAXN 2000020
#define FOR(x,n) for(int x=0;x<n;x++)

typedef long long ll;

//Bibliotecas
struct BBT{
    //Número de livros, Dias de inscrição, Número de livros enviados por dia
    int N,T,M,index;
    //Guarda o valor do livro no first e o id do livro no second
    vector<pii> v; 
};

// M N T
bool cmp(const BBT &a, const BBT &b){

	if(a.M > b.M){
		return true;
	}else if (a.M < b.M){
		return false;
	}else{

		if(a.N > b.N){
			return true;
		}else if (a.N < b.N){
			return false;
		}else{
			
			if(a.T < b.T){
				return true;
			}else if (a.T > b.T){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

// N M T
bool cmp2(const BBT &a, const BBT &b){

	if(a.N > b.N){
		return true;
	}else if (a.N < b.N){
		return false;
	}else{

		if(a.M > b.M){
			return true;
		}else if (a.M < b.M){
			return false;
		}else{
			
			if(a.T < b.T){
				return true;
			}else if (a.T > b.T){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

//N T M
bool cmp3(const BBT &a, const BBT &b){

	if(a.N > b.N){
		return true;
	}else if (a.N < b.N){
		return false;
	}else{

		if(a.T < b.T){
			return true;
		}else if (a.T > b.T){
			return false;
		}else{
			
			if(a.M > b.M){
				return true;
			}else if (a.M < b.M){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

//M T N
bool cmp4(const BBT &a, const BBT &b){

	if(a.M > b.M){
		return true;
	}else if (a.M < b.M){
		return false;
	}else{

		if(a.T < b.T){
			return true;
		}else if (a.T > b.T){
			return false;
		}else{
			
			if(a.N > b.N){
				return true;
			}else if (a.N < b.N){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

//T N M
bool cmp5(const BBT &a, const BBT &b){

	if(a.T < b.T){
		return true;
	}else if (a.T > b.T){
		return false;
	}else{

		if(a.N > b.N){
			return true;
		}else if (a.N < b.N){
			return false;
		}else{
			
			if(a.M > b.M){
				return true;
			}else if (a.M < b.M){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

//T M N
bool cmp6(const BBT &a, const BBT &b){

	if(a.T < b.T){
		return true;
	}else if (a.T > b.T){
		return false;
	}else{

		if(a.M > b.M){
			return true;
		}else if (a.M < b.M){
			return false;
		}else{
			
			if(a.N > b.N){
				return true;
			}else if (a.N < b.N){
				return false;
			}else{
				if(a.index < b.index){
					return true;
				}else{
					return false;
				}
			}
		}	
	}
}

//Armazena a solução
struct S{
    //Quantas bibliotecas estou usando
    int qttd;
    //Quantos livros consigo processaer
    vector<int> q;
    //ID das bibliotecas que vao ser usadas na ordem
    vector<int> s;
    //No id da biblioteca guarda os livros dela q vao ser processados
    vector<vector<int>> m;
};

int B,L,D;
vector<int> livros;
vector<BBT> bbt;
vector<BBT> bbt2;

int iterVND = 100;
int iterLivros = 500;
int espera = 30;
int iterPre = 30000;
int iterILS = 3;

bool tempo(clock_t t, long double tempMax){
	
	t = clock() - t;
	
	long double ti = (((long double)t)/CLOCKS_PER_SEC);
	
	if(ti >= tempMax){
		return false;
	}
	
	return true;
}

void imprimir(S &sol){
    int dia = 0;

    cout << sol.qttd << endl;

    for(int i=0;i<sol.s.size();i++){
        int b = sol.s[i];
        if(dia + bbt2[ b ].T >= D) break;
        else{
            dia += bbt2[ b ].T;  

            //Quantos livros vou conseguir processar 
            unsigned long long process = (D-dia) * bbt2[b].M;

            process = min(process, (unsigned long long)sol.m[b].size() );

            cout << b << " " << process << endl;

            FOR(j,process){
                cout << sol.m[b][j] << " \n"[j==process-1];
            }
        }
    }
}

ll fObj(S &sol){
    
    int dia = 0;
    ll ans = 0;
    int quantidade = 0;

    //Não contar um id duas vezes
    vector<bool> vis(B,false);

    FOR(i,sol.s.size()){
        //Biblioteca q estou avaliando
        int b = sol.s[i];

        if(dia + bbt2[b].T >= D) break;

        else{        
            dia += bbt2[b].T;

            quantidade = i+1;
            
            //Quantos livros vou conseguir processar 
            unsigned long long process = (D-dia) * bbt2[b].M;

            process = min(process, (unsigned long long)sol.m[b].size() );
            
            sol.q[i] = process;

            //Adicionando o valor daquele livro
            FOR(j,process){
                if( vis[ sol.m[b][j] ]) continue;
                else{ 
                    ans += livros[ sol.m[b][j] ] ;
                    vis[ sol.m[b][j] ] = true; 
                }
            }
        }
    }

    sol.qttd = quantidade;

    return ans;
}

void preenche(S &sol){

	FOR(i,L){
        sol.s[i] = bbt[i].index;
    }

    FOR(i,L){
        int b = sol.s[i];

        sol.m[b].resize( bbt[i].v.size() );

        FOR(j,bbt[i].v.size()){
            sol.m[b][j] = bbt[i].v[j].se;
        }
    }
}

void melhor(S &sol, S &solG, ll &ansG){

	ll ans = fObj(sol);

    if(ans > ansG){
    	solG = sol;
    	ansG = ans;
    }
}

void construtivo(S &sol){

	S solG;
	ll ansG = 0;

    sort(bbt.begin(),bbt.end(),cmp);

    preenche(sol);

    melhor(sol,solG,ansG);
 
    sort(bbt.begin(),bbt.end(),cmp2);

    preenche(sol);

    melhor(sol,solG,ansG);

    sort(bbt.begin(),bbt.end(),cmp3);

    preenche(sol);
    
    melhor(sol,solG,ansG);
    
    sort(bbt.begin(),bbt.end(),cmp4);

    preenche(sol);
    
    melhor(sol,solG,ansG);
    
    sort(bbt.begin(),bbt.end(),cmp5);

    preenche(sol);

    melhor(sol,solG,ansG);

    sort(bbt.begin(),bbt.end(),cmp6);

    preenche(sol);
    
    melhor(sol,solG,ansG);

    sol = solG; 
}
	
void optBBT(S &sol, ll &ansH){

	int a = rand()%bbt.size();
	int b = rand()%bbt.size();

	int cont = 0;
	while( cont++ < 20 && b == a || (b >sol.qttd) && a > sol.qttd){
		b = rand()%bbt.size();
	}

	swap(sol.s[a],sol.s[b]);
}

void optLivros(S &sol , ll &ansH, int k){

	int b = sol.s[k];

	for(int i=0;i<iterLivros;i++){

		int cont = 0;

		int a = rand()%sol.m[b].size();
		int c = rand()%sol.m[b].size();

		while( cont++ < espera && (c == a || (c >sol.q[k]) && a > sol.q[k])){
			c = rand()%sol.m[b].size();
		}

		if(a!=c && (c <= sol.q[k] || a <= sol.q[k])){

			swap(sol.m[b][a],sol.m[b][c]);

			ll ans = fObj(sol);

			if(ans > ansH){
				ansH = ans;
			}else{			
				swap(sol.m[b][a],sol.m[b][c]);
			}	
		}
		
	}
}

void optLivros(S &sol, ll &ansH){

	ll ans = fObj(sol);

	int l = sol.qttd;

	for(int i=0;i<l;i++){
		optLivros(sol,ansH,i);
	}	
}

void preOpt(S &solG, ll &ansH){

	ll ans = 0;

	int iter = 0;
	
	while(iter++ < iterPre){
		S sol = solG;
		optBBT(sol,ans);

		ans = fObj(sol);

		if(ans > ansH){
			cerr << "Ans: " << ans << " " << iter << endl;
			iter = 0;
			solG = sol;
			ansH = ans;
		}	
	}

	S sol = solG;
	
	optLivros(sol,ans);
    
    if(ans > ansH){
    	solG = sol;
    	ansH = ans;
    }
}

void VND(S &solG,ll &ansG){
    
    int iter = 0;

    preOpt(solG,ansG);

    cerr << "Pre Opt:" << ansG << endl;

    while(iter++ < iterVND){

    	cerr << "\nIter VND: " << iter << endl;
    	S sol = solG;
    	ll ans = ansG;

        optBBT(sol,ans);

        optLivros(sol,ans);

        if(ans > ansG){
        	iter = 0;
        	solG = sol;
        	ansG = ans;
        }
        cerr << "Melhor Solucao Atual:" << ansG << endl;
	}
}

void ILS(S &solG,ll &ansG){

    VND(solG,ansG);
	
	cerr << "######### Primeiro VND: " << ansG << endl;
	while(iterILS--){

		S &solK = solG;

		random_shuffle(solK.s.begin(),solK.s.end());

		ll ansK = fObj(solK);

    	VND(solK,ansK);

    	cerr << "######### Iter ILS: " << ansK << endl;

    	if(ansK > ansG){
    		ansG = ansK;
    		solG = solK;
    	}
	}
}

void heuristic(){

    srand(time(NULL));

	clock_t t = clock();
	
    S solG;
    ll ansG = 0;

    solG.q.assign(L,0);
    solG.s.assign(L,0);
    solG.m.resize(L);

    construtivo(solG);

    ansG = fObj(solG);

    cerr <<"Construtivo: " <<  ansG << endl;

    optLivros(solG,ansG);    

    cerr <<"Primeiro Solucao: " <<  ansG << endl;

    ILS(solG,ansG);
    
    cerr <<"\n!!!!!!!!!!!!! 	Valor Final: " <<  ansG << endl;

    imprimir(solG);
}

int main(int argc, char const *argv[]){   
    
    cin >> B >> L >> D; 

    livros.resize(B);

    FOR(i,B){
        cin >> livros[i];
    }

    bbt.resize(L);

    FOR(i,L){

        cin >> bbt[i].N >> bbt[i].T >> bbt[i].M;
        bbt[i].index = i;

        bbt[i].v.resize( bbt[i].N );

        FOR(j,bbt[i].N ){
            cin >> bbt[i].v[j].se;

            bbt[i].v[j].fi = livros[ bbt[i].v[j].se ];
        }

        //Ordena os livros dentro de cada biblioteca
        sort(bbt[i].v.begin(), bbt[i].v.end());
        reverse(bbt[i].v.begin(), bbt[i].v.end());
    }

    bbt2 = bbt;

    heuristic();

    return 0;
}