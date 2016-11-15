#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={4,5,6,6,8,7};
        int n=sizeof(A)/sizeof(A[0]);

        int i,j=INF,s=0;
        for(i=0;i<n;i++)
                j=min(j,A[i]);
        for(i=0;i<n;i++)
                A[i]-=j;
        int flag=1;
        for(i=0;i<n;i++)
        {       if(A[abs(A[i])]>=0&&A[abs(A[i])]<n)     
                        A[abs(A[i])]=-A[abs(A[i])];
                else 
                        flag=0;
        }
        if (flag)
        cout<<"Consecutive"<<endl;
        else
        cout<<"Not Consecutive"<<endl;
        return 0;
}
