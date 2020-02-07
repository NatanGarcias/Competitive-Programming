#include<bits/stdc++.h>

using namespace std;

int f( const string &s){

	stack<char> pilha;
	int k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='['  || s[i]=='{' || s[i]=='<'){
			pilha.push(s[i]);
		}
		else if (s[i] =='(' && i!= s.size()-1 && s[i+1] == '*'){
			pilha.push('a');
			i++;
		}
		else if(s[i] =='('){
			pilha.push('(');
		}
		else if (s[i]==']'){
			if(!pilha.empty()){
				if('[' == pilha.top())
					pilha.pop();
				else
					return k;
			}else{
				return k;
			}
		}
		else if (s[i]=='}'){
			if(!pilha.empty()){
				if('{' == pilha.top())
					pilha.pop();
				else
					return k;
			}else{
				return k;
			}
		}
		else if (s[i]=='>'){
			if(!pilha.empty()){
				if('<' == pilha.top())
					pilha.pop();
				else
					return k;
			}else{
				return k;
			}
		}
		else if(s[i] =='*' && i!= s.size()-1 && s[i+1] == ')'){
			i++;
			if(!pilha.empty()){
				if(pilha.top()=='a')
					pilha.pop();
				else
					return k;
			}else{
				return k;
			}
		}
		else if(s[i] == ')'){
			if(!pilha.empty()){
				if('(' == pilha.top())
					pilha.pop();
				else
					return k;
			}

		}
		k++;
	}
	if(pilha.empty())
		return 0;
	else
		return k;
}
int main(){
	string s;

	while(getline(cin,s)){
		int a = f(s);
		if(a)
			cout << "NO " << a << endl;
		else
			cout << "YES" << endl; 	
	}
}