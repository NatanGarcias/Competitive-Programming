#include<iostream>
using namespace std;

int main(){
    int vezes;
    cin >> vezes;
    for(int k=0;k<vezes;k++){
        int a,b,c,dado;
        cin >> a >> b >> c;
        int v[a];
        int v1[b],v2[b];
        for(int i=0;i<a;i++)
            v[i] =1;
        for(int i=0;i<b;i++)
            cin >> v1[i] >> v2[i];

        if(a==0){
            for(int i=0;i<c;i++)
                cin >> dado;
            continue;
        }
        for(int i=0;i<c;i++){
            cin >> dado;
            v[i%a]+= dado;
            for(int j=0;j<b;j++){
                if(v[i%a] == v1[j]){
                    v[i%a] = v2[j];
                        break;
                }
            }
            for(int m=0;m<a;m++)
                if(v[m] >=100){
                    i++;
                    for(;i<c;i++)
                        cin >> dado;
                    goto x;
                }
        }
        x:
        for(int i=0;i<a;i++){
            cout << "Position of player " << i+1 << " is ";
            if(v[i]>=100)
                cout << "100." << endl;
            else
                cout << v[i] << '.' << endl;
        }
    }
    return 0;
}