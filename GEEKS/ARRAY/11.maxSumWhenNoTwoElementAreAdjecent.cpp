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
        int A[]={1,10,3,4,10,6,7,8};
        int n=8,i,t;
        int ex=0,in=A[0];
        
        
        f1(i,n-1)
        {       t=max(in,ex);
                in=ex+A[i];
                ex=t;
        }
        
        cout<<max(ex,in)<<endl;
        return 0;
}
