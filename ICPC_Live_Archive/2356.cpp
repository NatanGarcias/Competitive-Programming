#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    cin.ignore();
    for(int i=0;i<a;i++){
        if(i)
            cout << endl;
        cin.ignore();
        stack<string> ant;
        stack<string> dep;
        string corrente = "http://www.acm.org/";
        string s;
        while(true){
            getline(cin,s);
            if(s[0] == 'Q')
                break;
            else if(s[0]=='B'){
                if(!ant.empty()){
                    dep.push(corrente);
                    corrente = ant.top();
                    ant.pop();
                    cout << corrente << endl;
                }
                else
                    cout << "Ignored" << endl;
            }
            else if(s[0]=='F'){
                if(!dep.empty()){
                    ant.push(corrente);
                    corrente = dep.top();
                    dep.pop();
                    cout << corrente << endl;
                }
                else
                    cout << "Ignored" << endl;
            }
            else if(s[0]== 'V'){
                string aux = "";
                for(int i=6;i<s.size();i++){
                    aux+=s[i];
                }
                ant.push(corrente);
                corrente = aux;
                while(!dep.empty())
                    dep.pop();
                cout << corrente << endl;
            }
        }
    }
    return 0;
}