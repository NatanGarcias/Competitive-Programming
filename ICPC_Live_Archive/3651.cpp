#include<iostream>
using namespace std;

int main(){
    int a,b,c,d;
    while(cin >> a >> b >> c){
        if(a==0 && b==0 && c==0)
            break;
        
        int z[c+1] = {0};

        for(int i=0;i<(a*b);i++){
            cin >> d;
            z[d]+=1;
        }
        int menor = 10E7;
        int cont=0;
        for(int i=1;i<=c;i++){
            if(menor == z[i])
                cont++;
            if(menor > z[i]){
                cont = 0;
                menor = z[i];
            }
        }
        for(int i=1;i<=c;i++){
            if(menor == z[i]){
                if(cont !=0){
                    cout << i << " ";
                    cont--;
                }
                else
                    cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}