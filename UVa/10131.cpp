#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define ms(x) memset(x,0,sizeof(x))

#define ll long long 
#define pii pair<int,int> 
#define fi first
#define se second
vector<pii> v;
int n;

int LIS(vector<int> &s){

    vector<int> pilha(v.size(),1);

    int maior = -1;

    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[i].se > v[j].se){
                pilha[i] = max(pilha[i],pilha[j] + 1);
                
                if(pilha[maior] < pilha[i]){
                    maior = i;
                }
            } 
        }
    }

    s.push_back(maior);

    int tam,ant;

    tam = pilha[maior]-1;
    ant = maior;
    
    for(int i=maior-1;i>=0;i--){
        if(pilha[i] == tam && pilha[i] < pilha[ant]){
            s.push_back(i);
            ant = i;
            tam--;

            if(!tam) break;
        }
    }
    
    reverse(s.begin(), s.end());

    return pilha[maior];
}

int main(){

    int a,b;

    map<pii,int> m;

    int cont = 0;

    while(cin >> a >> b){
        v.push_back({b,a});
        m[pii(b,a)] = ++cont;
    }   

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    n = v.size();

    vector<int> s;

    int ans = LIS(s);

    cout << ans << endl;

    for(auto i: s){
        cout << m[pii(v[i].fi,v[i].se) ] << " \n"[i==s.size()-1] << endl;
    }

    return 0;
}