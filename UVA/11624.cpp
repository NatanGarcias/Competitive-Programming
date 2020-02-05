#include<bits/stdc++.h>
using namespace std;

int a,b;

void bfs(vector<vector<char>> m, queue<pair<pair<int,int>,int>> &fila,vector<vector<int>> &tempos ){

    int x,y,temp;

    x = fila.front().first.first;
    y = fila.front().first.second;
    temp = fila.front().second;

    m[x][y] = 'J';

    tempos[x][y] = temp;

    while(!fila.empty()){
        
        x = fila.front().first.first;
        y = fila.front().first.second;
        temp = fila.front().second;
        temp++;

        fila.pop();
        

        if(x < 0 || y<0 || x>=a || y>=b){
            continue;
        }

        if(x-1 >=0 && m[x-1][y] == '.'){
            tempos[x-1][y] = temp;
            
            m[x-1][y] = 'J';
            fila.push({ make_pair(x-1,y), temp } );
        }
        if(x+1 < a &&  m[x+1][y] == '.'){
            tempos[x+1][y] = temp;
            
            m[x+1][y] = 'J';
            fila.push({ make_pair(x+1,y), temp } );
        }
        if(y-1 >=0 && m[x][y-1] == '.'){
            tempos[x][y-1] = temp;
            m[x][y-1] = 'J';
            fila.push({ make_pair(x,y-1), temp } );
        }
        if(y+1 <b && m[x][y+1] == '.'){
         	tempos[x][y+1] = temp;
            m[x][y+1] = 'J';
            fila.push({ make_pair(x,y+1), temp } );
        }
    }
}

void bfs(vector<vector<char>> &m){
    int xJ, yJ;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(m[i][j] == 'J'){
                xJ = i; yJ = j;
            }
        }
    }

    vector<vector<int>> tempos(a,vector<int>(b,10000000));
    vector<vector<int>> tempos2(a,vector<int>(b,10000000));
    
    queue<pair<pair<int,int>,int>> fila;
    
    fila.push({ make_pair(xJ,yJ), 1} );

    bfs(m,fila,tempos);
    
    vector<pair<int,int>> fogos;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(m[i][j] == 'F'){
                fogos.push_back({i,j});
            }
        }
    }

    for(int i=0;i<fogos.size();i++){
        fila.push({ make_pair(fogos[i].first,fogos[i].second), 1 } );
    }

    bfs(m,fila,tempos2);
    
    int menor = 10000000;

    for(int i=0;i<a;i++){
    	if(tempos[i][0]<tempos2[i][0])
    		menor = min(menor,tempos[i][0]);
    }
    for(int j=0;j<b;j++){
    	if(tempos[0][j]<tempos2[0][j])
    		menor = min(menor,tempos[0][j]);
    }
    for(int i=0;i<a;i++){
    	if(tempos[i][b-1]<tempos2[i][b-1])
    		menor = min(menor,tempos[i][b-1]);
    }
    for(int i=0;i<b;i++){
    	if(tempos[a-1][i]<tempos2[a-1][i])
    		menor = min(menor,tempos[a-1][i]);
    }
    if(menor!=10000000){
    	cout << menor << endl;
    }else{
    	cout << "IMPOSSIBLE" << endl;
    }
    
}
int main(){
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a >> b;
        vector<vector<char>> m(a,vector<char>(b,' '));

        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin >> m[i][j];
            }
        }
        
        bfs(m);
    }
}