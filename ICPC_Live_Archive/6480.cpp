#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        int ilhas[20];
        int pessoas[20];
        int sobreviventes = 0;
        for(int j=0;j<20;j++)
            cin >> ilhas[j];
        for(int j=19;j>0;j--){
            pessoas[j] = ilhas[j]%2;
            ilhas[j-1]+= ilhas[j]/2;
        }
        pessoas[0] = ilhas[0];

        for(int j=0;j<19;j++)
            cout << pessoas[j] << " ";
        cout << pessoas[19] << endl;
  }
  return 0;
}