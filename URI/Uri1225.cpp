#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,h=0;
    while(cin >> a){
        int b[a],soma;
        soma =0;
        h=0;
        for(int i=0;i<a;i++){
            cin >> b[i];
        }

        for(int i=0;i<a;i++)
            soma += b[i];
        
        if(soma%a!=0){
            cout << -1 << endl;
        }
        else{
            soma = soma/a;
            for(int i=0;i<a;i++)
                h += abs(soma-b[i]);
            cout << (h/2)+1 << endl;
        }
        
    }  
    return 0;
}