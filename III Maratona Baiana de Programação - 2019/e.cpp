#include<bits/stdc++.h>

using namespace std;

int n;
int k;
bool booom[100001] = {0};
vector<pair<int, int>> p;

int dist(int i, int j){
    return abs(p[i].first - p[j].first) * abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) * abs(p[i].second - p[j].second);
}

void bfs2(queue<int>&fila){
    while(!fila.empty()){
        for(int i=0;i<n;i++){
            if(i!=fila.front() && !booom[i]){
                if(dist(fila.front(),i)<k){
                    booom[i] = true;
                    fila.push(i);
                }
            }
        }
        fila.pop();
    }
}
void bfs(){
    queue<int> fila;
    for(int i=0;i<n;i++){
        if(!booom[i]){
            fila.push(i);
            bfs2(fila);
        }
    }
}

int main(){
    cin >> n >> k;
    k *= k;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    for(int i = 0; i < n; i++){
        if(!booom[i]){
            for(int j = 0; j < n; j++){
                //cout << dist(i, j) << " " << i << " " << j << endl;
                if(i != j && dist(i, j) < k){
                    booom[i] = booom[j] = true;
                    break;
                }
            }
        }    
    }
   // bfs();
    for(int i = 0; i < n; i++)
        cout << (booom[i]?"YES\n":"NO\n");
}