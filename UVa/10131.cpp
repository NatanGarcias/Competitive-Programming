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

    vector<int> pilha;
    int pos[n], pai[n];
    int p;

    for(int i=0; i<v.size(); i++){

        auto it = lower_bound(pilha.begin(), pilha.end(), v[i].se);

        p = it-pilha.begin();

        if(it==pilha.end()) pilha.push_back(v[i].se);
        else *it = v[i].se;

        // a posição original na sequência do número no topo da pilha p agora é i
        pos[p]=i;

        // se o elemento foi inserido na primeira pilha
        if(p==0) pai[i]=-1; // seu pai será -1

        // caso contrário, seu pai será a posição do elemento no topo da pilha anterior a ele
        else pai[i]=pos[p-1];
    }

    p = pos[pilha.size()-1];

    while(p != -1){
        s.push_back(p);
        p=pai[p];
    }

    reverse(s.begin(), s.end());

    return (int)s.size();
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