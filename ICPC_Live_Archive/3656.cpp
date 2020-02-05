#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    while(cin >> a){
        if(a==0)
            break;
        int b[a];
        int c[a];
        for(int i=0;i<a;i++)
            cin >> b[i];
        for(int i=0;i<a;i++)
            cin >> c[i];
        int par,impar;
        par = impar = 0;

        for(int i=0;i<a;i++){
            if(b[i]%2 ==0)
                par++;
            if(c[i]%2==1)
                impar++;
        }
        cout << abs(par-impar) << endl;
    }
    return 0; 
}