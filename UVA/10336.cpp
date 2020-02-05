#include<bits/stdc++.h>
using namespace std;

int a,b;

void ff(vector<vector<char>> &v, vector<vector<bool>> &vis,int i,int j){
    if( i<1 || j<1 || i>a || j>b){
        return;
    }
    if(!vis[i][j]){
        vis[i][j] = true;
        
        if(v[i][j] ==v[i][j-1])
            ff(v,vis,i,j-1);
        if(v[i][j] ==v[i][j+1])
            ff(v,vis,i,j+1);
        if(v[i][j] ==v[i-1][j])
            ff(v,vis,i-1,j);
        if(v[i][j] ==v[i+1][j])
            ff(v,vis,i+1,j);
    }    
}

void f(vector<vector<char>> &v){
    
    vector<vector<bool>> vis(a+2,vector<bool>(b+2,0));

    vector<pair<int,char>> p(26); 

    for(int i=0;i<26;i++)
        p[i].first =0;

    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(!vis[i][j]){
                p[ v[i][j]-'a'].first--;
                p[ v[i][j]-'a'].second = v[i][j];

                ff(v,vis,i,j); 
            }
        }
    }

    sort(p.begin(),p.end());


    for(int i=0;i<26;i++){
        if(!p[i].first) break;
        cout << p[i].second << ": " << -p[i].first << endl;
    }
        
}

int main (){
    cin >> a;
    int cont=0;
    while(cin >> a >> b){
        vector<vector<char>> v(a+2,vector<char>(b+2));

        for(int i=1;i<a+1;i++){
            for(int j=1;j<b+1;j++){
                cin >> v[i][j];
            }
        }
        cout << "World #" << ++cont << endl;
        f(v);
    }
}
