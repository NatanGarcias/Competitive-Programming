#include<bits/stdc++.h>
using namespace std;

int target;

bool formula(int a, int b, int c, int d, int e){
	if(a-(b*b)+(c*c*c)-(d*d*d*d)+(e*e*e*e*e) == target) return true;
	return false;
}


int main(){
	string b;
	while(cin >> target >> b){
		if(!target)
			break;
		vector<int> comb;
		for(int i=0;i<b.size();i++){
			comb.push_back(b[i]-64);
		}
		sort(comb.begin(),comb.end());
		reverse(comb.begin(),comb.end());

		for(int i=0;i<b.size();i++){
			for(int j=0;j<b.size();j++){
				if(j==i)
					continue;
				for(int k=0;k<b.size();k++){
					if(k==j || k==i)
						continue;
					for(int l=0;l<b.size();l++){
						if(l==j || l==i || l==k)
							continue;
						for(int m=0;m<b.size();m++){
							if(m==l || m==j || m==k || m==i)
								continue;
							if(formula(comb[i],comb[j],comb[k],comb[l],comb[m])){
								cout << char(comb[i]+64) << char(comb[j]+64) << char(comb[k]+64) << char(comb[l]+64)  << char(comb[m]+64) << endl;
								goto x;
							}
						}
					}
				}
			}
		}
		cout << "no solution" << endl;
		x:
		int nada;
	}
	return 0;
}