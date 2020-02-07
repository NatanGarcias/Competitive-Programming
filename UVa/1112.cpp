#include<bits/stdc++.h>
#define INF 1 << 29
using namespace std;

int adj[100][100];

void floyd(int n){
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){
    int t0;
    cin >> t0;
    while(t0--){
      int n, f, t;
      cin >> n >> f >> t;
      int m;
      cin >> m;


      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = INF;
        }
      }

      for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[--a][--b] = c;
      }

      floyd(n);
      int sum = 0;
      f--;
      for(int i = 0; i < n; i++)
        if(adj[i][f] <= t || f == i){
          sum++;
        }
      cout << sum << endl;
      if(t0) cout << endl;
    }
}
