#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

int n,g,r;

void dfs(const vector<vector<int>> &adj, vector<bool> &vis , int k){

    queue<int> fila;

    fila.push(k);
    vis[k] = true;
    
    while(!fila.empty()){
        int u = fila.front();
        
        fila.pop();

        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];

            if(!vis[v]){
                fila.push(v);
                vis[v] = true;
            }
        }
    }
}

bool dfs(const vector<vector<int>> &adj, vector<bool> &visR,vector<bool> &visG){

    queue<int> fila;

    fila.push(r);
    visR[r] = true;

    while(!fila.empty()){
        
        int u = fila.front();
        
        fila.pop();
        
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            
            if(!visG[v] && v == r)
                return true;
            
            if(!visR[v] && !visG[v]){
                fila.push(v);
                visR[v] = true;
            }
        }
    }
    return false;
}

void encontroPasseio(vector<vector<int>>&adjG,vector<vector<int>>&adjR){

    vector<bool> visG(n,false);
    vector<bool> visR(n,false);

    //Uso uma dfs nos dois grafos para saber em quais vertices o gato e o rato podem chegar
    dfs(adjG,visG,g);
    dfs(adjR,visR,r);

    bool certo = false;
    
    //Se o gato e o rato podem visitar o mesmo vertice a primeira resposta é sim
    for(int i=0;i<n;i++){
        if(visG[i] && visR[i]){
            cout << "Y ";
            certo = true;
            break;
        }
    }
    if(!certo)
        cout << "N ";

    //Agora veremos se o rato consegue passear
    //Faço uma dfs para o rato sem poder passar nos vertices que o gato pode passar
    
    vector<bool> visR2(n,false);

    certo = dfs(adjR,visR2,visG);

    if(certo)
        cout << "Y" << endl;
    else
        cout << "N" << endl;    
}

int main(){

    int casos =0;
    int cont=0;
    
    cin >> casos;
    
    while(casos--){
        
        cin >> n >> g >> r;

        g--;r--;
        
        //List de adj para o gato e para o rato
        vector<vector<int>>adjG(n);
        vector<vector<int>>adjR(n);

        int a,b;

        while(cin >> a >> b){
            if(a==-1 && b==-1)
                break;
            adjG[a-1].push_back({b-1});
        }

        string s;

        cin.ignore();
        while(getline(cin,s)){
            if(s.empty()) break;

            stringstream ss(s);
            int c, d;

            ss >> c;
            ss >> d;
            adjR[c-1].push_back({d-1});                
        }

        encontroPasseio(adjG,adjR);

        if(casos)
            cout << endl;
    }
}