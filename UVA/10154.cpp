#include<bits/stdc++.h>
using namespace std;

bool cmp(const tuple<int,int,int>&a,const tuple<int,int,int>&b){
	if(get<0>(a) > get<0>(b))
		return true;
	else if (get<0>(a) < get<0>(b))
		return false;
	else if (get<1>(a) > get<1>(b))
		return true;
	else
		return false;
}

int main(){
	int a,b;
	
	vector<tuple<int,int,int>> m;
	
	while(cin >> a >> b){
		m.push_back({b-a,a,b});
	}
	
	int cont=0;
	int total=0;
	
	sort(m.begin(),m.end(),cmp);
	
	int menor=get<0>(m[0]);
	for(int j=1;j<800;j++){
		cont =0;
		menor=get<0>(m[0]);
		for(int i=0;i<m.size();i++){
			if(menor>=get<1>(m[i]) && get<1>(m[i])<j){
				cont++;
				menor = menor-get<1>(m[i])>get<1>(m[i])?menor-get<1>(m[i]):get<1>(m[i]);
			}
		}
		if(cont > total)
			total = cont;
	}
	cout << total << endl;
}