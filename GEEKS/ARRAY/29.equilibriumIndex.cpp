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
        int A[]={-7,1,5,2,-4,3,0};
        int n= sizeof(A)/sizeof(A[0]);
        int i,sum=0;
        for(i=0;i<n;i++)
                sum+=A[i];
        int sum2=0;
        for(i=0;i<n;i++)
        {       sum-=A[i];
                if (sum==sum2)
                        cout<<i<<' ';
                sum2+=A[i];
        }
        cout<<endl;
        return 0;
}
