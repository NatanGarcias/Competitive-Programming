#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        stack<char> a;
        string c;

        getline(cin,c);
        for(int j=0;j<c.size();j++){
            if(a.empty())
                a.push(c[j]);
            else if(c[j]=='(')
                a.push(c[j]);
            else if(c[j]=='[')
                a.push(c[j]);
            else if(c[j]==')' && a.top() == '(')
                a.pop();
            else if(c[j]==')' && a.top() != '(')
                a.push(c[j]);
            else if(c[j]==']' && a.top() == '[')
                a.pop();
            else if(c[j]==']' && a.top() != '[')
                a.push(c[j]);
        }
        if(a.empty()){
            cout << "Yes" <<  endl;
        }
        else{
            cout << "No" << endl; 
        }  
    }
    return 0;
}