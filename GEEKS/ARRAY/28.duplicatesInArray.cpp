#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,1,3,4};
        int n=sizeof(A)/sizeof(A[0]);
        int i;

        for(i=0;i<n-1;i++)
        {       int j=abs(A[i]);
                if (A[j]>0)
                       A[j]=-A[j];       
                else
                        cout<<j<<' ';
        }
        cout<<endl;
        
        return 0;
}
