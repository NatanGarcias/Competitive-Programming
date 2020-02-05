#include<iostream>
using namespace std;

int main(){
    int a,b,c,d;
    while(cin >> a >> b >> c >> d){
        int v[c];
        int menor =-1;
        bool Posso[c];
        bool Posso2[c];
        int v1[c][d];
        for(int i=0;i<c;i++){
            cin >> v[i];
            Posso[i] = true;
            Posso2[i] = false;
            for(int j=0;j<d;j++)
                cin >> v1[i][j];
        }

        for(int i=0;i<c;i++){
            if(v[i]*a > b)
                Posso[i] = false;
            else{
                for(int j=0;j<d;j++){
                    if(v1[i][j] > a)
                        Posso2[i] = true;
                }
            }
        }

        for(int i=0;i<c;i++){
            if(Posso[i] && Posso2[i]){
                if(menor == -1)
                    menor = v[i]*a;
                else if((v[i]*a)<menor)
                    menor = v[i]*a;
            }
        }

        if(menor ==-1)
           cout << "stay home" << endl;
        else
            cout << menor << endl;
    }
    return 0;
}