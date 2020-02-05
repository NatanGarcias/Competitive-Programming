#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool a= true;
    while(cin >> n){
      if(a) a= false;
      else cout << endl;
      vector<vector<int>> adj;
      vector<int> g;
      adj.resize(n);
      g.resize(n);
      fill(g.begin(), g.end(), 0);
      for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
          int aux;
          cin >> aux;
          adj[i].push_back(aux);
        }
      }

      g[0] = 1;

      long long int sum = 0;

      for(int i = 0; i < n; i++){
        for(int j:adj[i]){
          g[j] += g[i];
        }

        if(adj[i].size() == 0)
          sum += g[i];
      }

      cout << sum << endl;
    }
}
