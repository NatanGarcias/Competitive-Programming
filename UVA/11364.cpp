#include<bits/stdc++.h>
using namespace std;

int main(){

  int a;
  cin >> a;
  for(int l=0;l<a;l++){
    int b,c;
    cin >> b;
    vector<int> v;
    for(int i=0;i<b;i++){
      cin >> c;
      v.push_back(c);
    }
    sort(v.begin(),v.end());

    cout << (v[b-1] -v[0])*2 << endl;
  }
}
