#include<iostream>
using namespace std;
int BinCoff(int n,int k)
{   if(k==n||k==0)return 1;
    if(k>n&&k<0)return -1;
    int B =1;
    k=min(k,n-k);
    for(int i=1;i<=k;i++)
        B *= (n-i+1)/i;
    return B;
}

int main()
{   cout<<BinCoff(6,4);
    return 0;
}
