#include<bits/stdc++.h>
using namespace std;

int main(){
    int nome,team,cont,soma,aux,aux1;
    bool certo;
    cont =0;
    cin >> nome >> team;
    x:
    vector<string> a;
    string b;
    for(int i=0;i<nome;i++){
        cin >>  b;
        a.push_back(b);
    }
    certo = true;
    sort(a.begin(), a.end());
    for(int i=1;i<nome;i++){
    		string elementoInserir=a[i];
    		int j= i-1;
    		while(j>=0 && a[j].size()>elementoInserir.size()){
    			a[j+1]=a[j];
    			j--;
    		}
    		a[j+1]=elementoInserir;
    }
    for(int j=0;j<nome;j++){
        soma=0;
        for(int l=0;l<team;l++){
          soma+= a[j+l].size();
        }
        aux = soma/team-a[j].size();
        aux1= soma/team-a[j+team-1].size();
        if(abs(aux)>2 || abs(aux1) >2){
          certo =false;
        }
        j+=team-1;
    }
    if(!certo)
        cout << "Case " << 1+cont++ << ": no" << endl;
    else
        cout << "Case " << 1+cont++ << ": yes" << endl;

    cin >> nome >> team;
    if(nome!=0 && team !=0){
      cout << endl;
      goto x;
    }
}