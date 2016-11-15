#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void markMultiples(vector<bool> &Arr,int i,int n)
{   for(int j=2*i;j<=n;j+=i)
        Arr[j]=false;
}
void sieve(int n)
{   vector<bool> Arr=vector<bool>(n+1,true);
    Arr[0]=Arr[1]=false;
    for(int i=2;i<=n;i++)
    {   if(Arr[i] == true)
        {   markMultiples(Arr,i,n);
      //      cout<<i<<' ';
        }

    }


}
int main()
{
    int n=100000000;
    //cin>>n;
    sieve(n);
}
