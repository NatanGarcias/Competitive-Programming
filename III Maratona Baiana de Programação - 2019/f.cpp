#include<bits/stdc++.h>

using namespace std;

int main(){
   char x[100][100];
   char y[100][100];

   int a,b;

   cin >> a >> b;
   for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
        cin >> x[i][j];
    }
    cin.ignore();
   }
    
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin >> y[i][j];
        }
    cin.ignore();
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(x[i][j] != y[i][j]) cout << i+1 <<  " " << j+1 << endl;
        }
   }




}