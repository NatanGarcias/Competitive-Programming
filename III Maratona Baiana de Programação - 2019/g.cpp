#include<bits/stdc++.h>

using namespace std;

int main(){ 
    set<int> numeros;
    int aux;
    for(int i=0;i<6;i++){
        cin >> aux;
        numeros.insert(aux);
    }
    int quina,quadra,sena;
    quina = quadra = sena = 0;
    int quantos,tamanho;
    cin >> quantos;
    vector<vector<int>> jogod(quantos);
    for(int i=0;i<quantos;i++){
        cin >> tamanho;
        int l;
        for(int j=0;j<tamanho;j++){
            cin >> l;
            jogod[i].push_back(l);
        }
    }
    int cont=0;
    for(int i=0;i<quantos;i++){
        cont=0;
        for(int j=0;j<jogod[i].size();j++){
            if(numeros.find(jogod[i][j])!=numeros.end()){
                cont++;
            }
        }
        if(cont==4)
            quadra++;
        if(cont==5)
            quina++;
        if(cont==6)
            sena++;
    }
    cout << sena << " " << quina << " " << quadra << endl;
}