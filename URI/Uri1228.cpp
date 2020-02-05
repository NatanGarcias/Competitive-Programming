#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,soma,cont;
    while(cin >> a){
        soma =0;
        int b[a],c[a];
        for(int k=0;k<a;k++)
            cin >> b[k];
        for(int k=0;k<a;k++)
            cin >> c[k];   

        for(int j=0;j<a;j++){
             cont =0;
            for(int k=j;k<a;k++){
                if(c[j] != b[k]){
                    cont++;
                }
                else{
                    for(int l=0;l<cont;l++){
                        swap(b[k-l],b[k-1-l]);
                        soma++;
                    }
                    break;
                }
            }
        }
        cout << soma << endl;
    }
    return 0;
}