#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        if(i)
            cout << "\n";

        int l,c,n,l1,c1;
        cin >> l >> c >> n;
        l1 = l+2;
        c1 = c+2;
        char matriz[l1][c1];
        char aux[l1][c1];
        string z;
        if(l==0 || c==0){
            cin.ignore();
            cin.ignore();
            goto x;
        }
        memset(matriz,'A',sizeof(matriz));
        for(int j=1;j<l+1;j++){
            cin >> z;
            for(int k=1;k<c+1;k++){
                matriz[j][k] = z[k-1];
            }
        }
        
        for(int j=0;j<n;j++){
            for(int j1=1;j1<l+1;j1++){
                for(int j2=1;j2<c+1;j2++){
                    if(matriz[j1][j2]=='R'){
                        if(matriz[j1+1][j2]=='P')
                            aux[j1][j2] = 'P';
                        else if(matriz[j1-1][j2]=='P')
                            aux[j1][j2] = 'P';
                        else if(matriz[j1][j2+1]=='P')
                            aux[j1][j2] = 'P';
                        else if(matriz[j1][j2-1]=='P')
                            aux[j1][j2] = 'P';
                        else
                            aux[j1][j2] = 'R';
                    }
                    else if(matriz[j1][j2]=='P'){
                        if(matriz[j1+1][j2]=='S')
                            aux[j1][j2] = 'S';
                        else if(matriz[j1-1][j2]=='S')
                            aux[j1][j2] = 'S';
                        else if(matriz[j1][j2+1]=='S')
                            aux[j1][j2] = 'S';
                        else if(matriz[j1][j2-1]=='S')
                            aux[j1][j2] = 'S';
                        else
                            aux[j1][j2] = 'P';
                    }
                    else if(matriz[j1][j2]=='S'){
                        if(matriz[j1+1][j2]=='R')
                            aux[j1][j2] = 'R';
                        else if(matriz[j1-1][j2]=='R')
                            aux[j1][j2] = 'R';
                        else if(matriz[j1][j2+1]=='R')
                            aux[j1][j2] = 'R';                        
                        else if(matriz[j1][j2-1]=='R')
                            aux[j1][j2] = 'R';
                        else
                            aux[j1][j2] = 'S';                        
                    }
                }
            }
            for(int m=1;m<l+1;m++){
                for(int n=1;n<c+1;n++){
                    matriz[m][n] = aux[m][n];
                }
            }
        }
        for(int m=1;m<l+1;m++){
            for(int n=1;n<c+1;n++){
                cout << matriz[m][n];
            }
            cout << endl;
        }
        x:
        int nada;
    }
    return 0;
}