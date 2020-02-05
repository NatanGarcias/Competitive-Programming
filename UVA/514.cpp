#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,auxiliar;
    cin >> a;
    while(true){
        x:
        cin >> auxiliar;
        if(auxiliar ==0){
            cout << endl;
            break;
        }
        stack<int> pilha;
        queue<int> entrada;
        entrada.push(auxiliar);
        for(int i=1;i<a;i++){
            cin >> auxiliar;
            entrada.push(auxiliar);
        }
        for(int i=1;i<=a;i++){
            if(pilha.empty()){
                pilha.push(i);
            }
            else
                pilha.push(i);
            if(!pilha.empty()){
                while(pilha.top() == entrada.front()){
                    entrada.pop();
                    pilha.pop();
                    if(pilha.empty())
                        break;
                }
            }
        }
        if(pilha.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;        
    }
    cin >> a;
    if(a!=0)
        goto x;

    return 0;
}