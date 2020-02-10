#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define pii pair<int,int>

bool v[MAXN];

int N,M,K;

int vizinho(int x, int upDown, int casa){
    if((x/casa)%(10) == 9 && upDown == 1){
        return x - 9*casa;
    }else if((x/casa)%(10) == 0 && upDown == -1){
        return x + 9*casa;
    }else{
        return x + upDown*casa;
    }
}

int bfs(int com ,int fim){

    v[com] = true;
    queue<pii> fila;

    fila.push({com, 0});

    if(com == fim)
        return 0;

    int r[2] = {-1,1};
    int c[4] = {1,10,100,1000};

    while(!fila.empty()){
        int u = fila.front().first;
        int t = fila.front().second;

        fila.pop(); 
                
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                int upDown = r[i];
                int casa = c[j];

                int aux = vizinho(u,upDown,casa);
                if(aux == fim)
                    return t+1;

                if(!v[aux]){
                    v[aux] = true;
                    fila.push({aux,t+1});
                }
            }
        }
    }

    return -1;
}

int trata(int a,int b,int c,int d){
    return a*1000 + b*100 + c*10 + d;
}

int main(){

    cin >> K;

    while(K--){
        
        memset(v,0,sizeof(v));

        int a,b,c,d;

        int com,fim,aux;

        cin >> a >> b >> c >> d;

        com = trata(a,b,c,d);

        cin >> a >> b >> c >> d;

        fim = trata(a,b,c,d);

        cin >> M;

        for(int i=0;i<M;i++){
            cin >> a >> b >> c >> d;
            v[trata(a,b,c,d)] = true;
        }

        cout << bfs(com,fim) << endl;
    }
    return 0;
}