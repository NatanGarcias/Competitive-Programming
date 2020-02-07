#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
ull count( int S[], int m, int n )
{
    long long int i, j,x,y;

    ull table[n + 1][m];
    for (i = 0; i < m; i++)
        table[0][i] = 1;
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x+y;
        }
    }
    return table[n][m - 1];
}

int main()
{
    int arr[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int h1,h;
    char s;
    string k1;
    double oldn;
    while(cin >> k1){
        stringstream k;
        k << k1;
        k >> h1 >> s >> h;
        oldn = h1+(h/100.0);
        int num=h1*100+h;
        if(num==0) break;
        printf("%*s",6,k1.c_str());
        printf("%*llu\n",17,count(arr, m, num));
    }
    return 0;
}