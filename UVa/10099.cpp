#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

//Numero de vertices e arestas do caso de teste
int n,m;
int casos;

void caminhoneiro(vector<vector<int>>&adj){
    
    //Floyd
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = max( adj[i][j], min(adj[i][k],adj[k][j]));
            }
        }
    }

    int s,d,t;

    cin >> s >> d >> t;

    s--;d--;t--;
    
    cout << "Scenario #" << ++casos << endl;
    cout << "Minimum Number of Trips = " << (int)ceil(t/(adj[s][d]*1.0)) << "\n\n";
}

int main(){

    int casos =0;
    while(cin >> n  >> m){
        if(n==0 && m==0)
            break;

        vector<vector<int>>adj(n,vector<int>(n,0));

        int s,d,t;

        for(int i=0;i<m;i++){
            cin >> s >> d >> t;

            s--;d--;t--;

            adj[s][d] = t;
            adj[d][s] = t;
        }
        
        caminhoneiro(adj);
    }
}