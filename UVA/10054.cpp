#include<bits/stdc++.h>
using namespace std;

int main (){
    
    //ios::sync_with_stdio(0);
    // cin.tie(0);
    
    int a,b,c,d;

    scanf("%d",&a);
    int cont=0;
    while(scanf("%d",&a)==1){
        
        if(cont) printf("\n");
        
        vector<list<int>> m(51);
        
        int grau[52]= {0};
        int pos,posAtual;
        
        for(int i=0;i<a;i++){
            
            scanf("%d %d",&c,&d); 

            grau[c]++;
            grau[d]++;
            m[c].push_back(d);
            m[d].push_back(c);
            pos = d;
        }
        bool con = true;
        for(int i=0;i<51;i++){
            if(grau[i]%2){
                printf("Case #%d\nsome beads may be lost\n",++cont );

                con = false;
                break;
            }
        }

        if(con){
            stack<int> pilha;
            stack<int> caminho;

            pilha.push(pos);
            
            posAtual = m[pos].front();

            m[pos].pop_front();

            for(list<int>::iterator it = m[posAtual].begin(); it!=m[posAtual].end(); ++it){
                if(*it== pilha.top()){
                    m[posAtual].erase(it);
                    break;
                }
            }

            int aux=1;
            while(pilha.size()){
                if(m[posAtual].empty()){
                    caminho.push(posAtual);

                    posAtual = pilha.top();

                    pilha.pop();

                }else{
                    aux++;
                    pos = posAtual;
                    pilha.push(pos);
                    
                    posAtual = m[pos].front();

                    m[pos].pop_front();

                    for(list<int>::iterator it = m[posAtual].begin(); it!=m[posAtual].end(); ++it){
                        if(*it== pilha.top()){
                            m[posAtual].erase(it);
                            break;
                        }
                    }
                }
            }

            while(pilha.size()){
                int z = pilha.top();
                caminho.push(z);
                pilha.pop();
            }

            int x,y,t,u;
            printf("Case #%d\n",++cont );
            t = caminho.top();
            while(caminho.size()>1){
                x = caminho.top();
                caminho.pop();
                y = caminho.top();
                printf("%d %d\n",x,y );
            }
            printf("%d %d\n",y,t);
        }
    }    
}
