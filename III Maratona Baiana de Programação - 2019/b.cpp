#include<bits/stdc++.h>

using namespace std;

bool cmp(const tuple<int,int,string>&a, const tuple<int,int,string>&b){
    if(get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b));
    return get<1>(a) > get<1>(b));
}
int main(){
    int numero , capacidade;
    int pontos,gasto;
    string cidade;
    vector<tuple<int,int,string>> g;
    map<string,bool> nomesDasCidades;
    for(int i=0;i<numero;i++){
        cin << gasto << pontos << cidade;
        g.push_back({gastos,pontos,cidades});
    }
    sort(g.begin(),g.end(),cmp);
    nomesDasCidades[cidade] = true;
    long long total =0;
    long long max = 0;
    for(int j=0;j<10000;j++){
        max =0;
        for(int i=0;i<g.size();i++){
            if(nomesDasCidades[get<2>(g[i]]) == false && get<0>(g[i]<j)){
                if(capacidade2 -get<0>(g[i])  >=  0){
                    max+= get<1>(g[i]);
                    capacidade2 -= get<0>(g[i]);
                }
            }
        }
        if(max>total)
            total = max;
    } 
}
