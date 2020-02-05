#include<bits/stdc++.h>
using namespace std;

struct Racional{
    int cima,baixo;
};

int mdc(int a, int b){
    return (b == 0 ? a : mdc(b, a%b)); 
}

pair<int,int> dfs( vector<vector<tuple<int,int,int>>> &adj, int deOnde, int paraOnde ){

    vector<bool> vis(adj.size(),0);

    stack<tuple<int,int,int>> pilha;

    pilha.push({deOnde,1,1}); 

    vis[deOnde] = true;
    
    while(!pilha.empty()){
        
        int onde = get<0>(pilha.top());

        int cima = get<1>(pilha.top());;
        int baixo = get<2>(pilha.top());;

        pilha.pop();

        if(onde == paraOnde){
            pair<int,int> a;
            a.first = cima;
            a.second = baixo;
            return a;
        }

        for(int i=0;i<adj[onde].size();i++){
            int temp = get<0>(adj[onde][i]);

            if(!vis[ temp ]){
                vis[ temp ] = true;
                
                int aux = get<1>(adj[onde][i]);
                int aux2 = get<2>(adj[onde][i]);

                int aux3 = cima*aux;
                int aux4 = baixo*aux2;

                int min;

                min = mdc(aux,aux2);

                int aux5 = aux3/min;
                int aux6 = aux4/min;

                pilha.push({temp,aux5,aux6});
            }
        }
    }


    pair<int,int> a;
    a.first = 0;
    a.second = 0;
    return a;

}
int main(){
    
    string s;
    
    unordered_map<string,int> mapa;
    unordered_map<int,string> mapa2;

    vector<vector<tuple<int,int,int>>> adj;
    
    int cont=0;
    
    while(getline(cin,s)){
        if(s[0] =='!'){
            stringstream ss;
            int a,b;
            string s2,s3;
            char k;

            ss << s;

            ss >> k >> a >> s2 >> k >> b >> s3;

            if(mapa.find(s2) == mapa.end()){
                adj.push_back(vector<tuple<int,int,int>>());
                mapa[s2] = cont++;
                mapa2[cont] = s2;
            }

            if(mapa.find(s3) == mapa.end()){
                adj.push_back(vector<tuple<int,int,int>>());
                mapa[s3] = cont++;
                mapa2[cont] = s3;
            }

            int min;

            min = mdc(a,b);

            a/= min; b/= min;

            adj[ mapa[s2] ].push_back({mapa[s3],a,b});
            adj[ mapa[s3] ].push_back({mapa[s2],b,a});

        }else if(s[0] =='?') {

            stringstream ss;
            string s2,s3;
            char k;

            ss << s;
            ss >> k >> s2 >> k >> s3;

            int u  = mapa[s2];
            int v = mapa[s3];

            pair<int,int> z = dfs(adj,u,v);

            if(z.first==0 && z.second==0){
                cout << "? " << s2 << " = " << "? " << s3 << endl;
            }else{
                int min2 = mdc(z.first,z.second);
                cout << z.first/min2 << " " << s2 << " = " << z.second/min2 << " " << s3 << endl;
            }
        
        }else{
            break;
        }
    }
}