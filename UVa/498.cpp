#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        stringstream ss;
        ss<<s;
        vector<int> coeficientes;
        int d;
        while(ss>>d){
        coeficientes.push_back(d);
        }
        getline(cin,s);
        stringstream ss1;
        ss1<<s;
        vector<int> poli;
        while(ss1>>d){
            poli.push_back(d);
        }
        for(int i=0;i<poli.size();i++){
            int aux=0;
            for(int j=0;j<coeficientes.size();j++){
                aux+= coeficientes[coeficientes.size()-j-1] * pow(poli[i],j);
            }
            if(i!=poli.size()-1)
               cout << aux << " ";
            else
                cout << aux << endl;
        }
    }
    return 0;
}