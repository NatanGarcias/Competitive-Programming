#include<bits/stdc++.h>
using namespace std;

int b[14];
vector<vector<int> > semrepetir;
//Escreve a permutacao
void subconjuntos(int n){
    vector<int> aux;
    for(int i=0;i<(1<<n);i++) {     //para cada subconjunto
        aux.clear();
        for(int j=0; j<n; j++) {    //para cada elemento
            if (i & (1 << j))       //elemento j pertence ao subconjunto i
                aux.push_back(b[j]);
        }
        if(aux.size()==6){
            semrepetir.push_back(aux);
        }
    }
}
int main(){
    int a,k;
    k=0;
    while(cin >> a){
        if(!a)
            break;
        if(k)
            cout << endl;
        k++;
        for(int i=0;i<a;i++){
            cin >> b[i];
        }
        semrepetir.clear();
        subconjuntos(a);
        sort(semrepetir.begin(),semrepetir.end());
        for(auto x:semrepetir){
            int j=0;
            for(auto y:x){
                if(!j)
                    cout << y;
                else
                    cout << " " << y;
                ++j;
            }
            cout << endl;
        }
    }
    return 0;
}
