#include<bits/stdc++.h>
using namespace std;

int u[27]={1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4, 1};

int main(){
  int t, c = 1;
  cin >> t;
  string s;
  getline(cin, s);
  while(t--){
    getline(cin, s);
    long long int sum = 0;
    for(int i = 0; i < s.size(); i++){
      int j = (int)(s[i] - 'a');
      if(s[i] == ' ')
        sum++;
      else
        sum += u[j];
    }
    cout << "Case #" << c++ << ": ";
    cout << sum << endl;
  }
}
