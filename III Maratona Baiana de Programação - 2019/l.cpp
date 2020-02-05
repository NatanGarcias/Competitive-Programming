#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[7][7];
    for(int i = 0; i < 7; i++) 
        for(int j = 0; j < 7; j++)
            cin >> a[i][j];
    int c[7] = {0};
    for(int i = 0; i < 7; i++) 
        for(int j = 0; j < 7; j++){
            if(a[i][j])
                c[i]++;           
        }

    for(int i = 0; i < 7; i++)
        cout << c[i] << endl;
}