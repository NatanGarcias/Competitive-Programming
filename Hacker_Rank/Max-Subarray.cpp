#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
int main(){
	int a,b;
	cin >>a;
	f(i,a){
		cin >> b;
		int max=0;
		int max2=0;
		int max3=-10000000;
		int min = 10;
		int c;
		f(j,b){
			cin >> c;
			if(c<0){
				if(c*(-1)<min)
					min = fabs(c);
			}
			if(c >0){
				max+=c;
				max2+=c;
			}
			else if(c+max2>=0){
				if(max2>max3)
					max3 = max2;
				max2+=c;	
			}
			else{
				if(max2>max3)
					max3 = max2;
				max2=0;
			}
		}
		int l = max2>max3?max2:max3;
		if(l<=0 && max<=0)
			cout << (-1)*min << " " << (-1)*min << endl;
		else{	
			cout << l << " " << max << endl;
		}
	}
}	