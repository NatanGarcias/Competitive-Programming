#include<bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int> > &matriz, vector<int> &visited, int qual, int &indice){
    for(int i=0;i<matriz[qual].size();i++){
        if(matriz[qual][i]){
            if(visited[i]!=indice){
                visited[i] =indice;
                bfs(matriz,visited,i,indice);
            }
        }
    }
}
int main(){
    int a;
    while(cin >> a){
        if(a==0)
            break;
        vector<vector<int> > matriz(a+1,vector<int>(a+1,0));
        int b;
        while(cin >> b){
            if(b==0)
                break;
            int c;
            while(cin >> c){
                if(c==0)
                    break;
                matriz[b][c] = true;
            }
        }

        int tamanho;
        
        cin >> tamanho;
        
        int qual;
        
        vector<int> visited(a+1,0);
        
        for(int i=1;i<=tamanho;i++){
        
            cin >> qual;
        
            bfs(matriz,visited,qual,i);
        
            int cont=0;
        
            for(int j=1;j<visited.size();j++)
                if(visited[j] ==i)
                    cont++;
        
            cont = a-cont;
        
            cout << cont;
        
            for(int j=1;j<visited.size();j++)
                if(visited[j] !=i)
                    cout << " " << j;
            cout << "\n";
        }
    }
}
