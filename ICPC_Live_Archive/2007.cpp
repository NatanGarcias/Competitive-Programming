#include<bits/stdc++.h>
using namespace std;

void f(const string &s){
    stack<string> pilha;
    for(int i=2;i<s.size();i++){
        if(s[i-2]=='<' && (s[i-1] >= 'A' && s[i-1]<='Z') && s[i] == '>'){
            string k;
            k+= s[i-2];
            k+=s[i-1];
            k+=s[i];
            pilha.push(k);
            //cout << k << endl;
        }
        else if(i+1<s.size() && s[i-2]=='<' && s[i-1]=='/' && (s[i] >= 'A' && s[i]<='Z') && s[i+1] == '>'){
            string k;
            if(!pilha.empty()){
                k = pilha.top();
                if(s[i] == k[1]){
                    pilha.pop();
                    i++;
                }else{
                    cout << "Expected </" << k[1] << "> found </" << s[i] << '>' << endl;
                    return;
                }
            }
            else{
                cout << "Expected # found </" << s[i] << '>' << endl;
                return;
            }
        }
    }
    if(!pilha.empty()){
        string k;
        k = pilha.top();
        cout << "Expected </" << k[1] << "> found #" << endl;
        return; 
    }
    cout << "Correctly tagged paragraph" << endl;
}

int main(){
    string s;
    string s1;
    while(getline(cin,s)){
        if(s[0]=='#')
            break;
        if(s[s.size()-1]!='#'){
            s1+=s;
            continue;
        }
        else{
            s1+=s;
            f(s1);
            s1.clear();
        }
    }
}