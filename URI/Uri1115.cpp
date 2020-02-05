#include<bits/stdc++.h>
using namespace std;

int main ()
{
	for(;;)
	{
		int b,c;
		cin >> b >> c;
		if(b==0 || c==0)
			break;
		if (c>0 && b>0)
			cout <<"primeiro" << endl;
		if (c>0 && b<0)
			cout <<"segundo" << endl;
		if (c<0 && b>0)
			cout <<"quarto" << endl;
		if (c<0 && b<0)
			cout <<"terceiro" << endl;
	}
	return 0;
}