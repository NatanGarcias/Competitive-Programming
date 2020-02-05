#include<bits/stdc++.h>
using namespace std;

int  fat(int a)
{
	if (a==0)
		return 1;
	else
		return a*fat(a-1);
}

int main ()
{
	int a;
	cin >> a;

	cout << fat(a) << endl;
	
	return 0;
}
