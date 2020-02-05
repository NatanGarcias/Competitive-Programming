#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,cont;
    cin >> a;
    cont =0;
    for(int i=0;i<a;i++){
      char b[91];
      int c;
      cin >> c;
      cin >> b;
      cout << i+1 << " ";
      for(int j=0;j<strlen(b);j++){
        if(j!=c-1)
          cout << b[j];
      }
      cout << endl;
    }
  return 0;
}