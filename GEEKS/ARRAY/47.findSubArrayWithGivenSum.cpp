#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;



int main(int argc, char *argv[])
{
        int A[]={1,2,2,4,5,7,3,2,7,2};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,sum=A[0],Rsum=12;
        
        i=0;
        for(j=1;j<n;)
        {       if (sum==Rsum)break;
                else if (sum<Rsum)
                       sum+=A[j++];
                else   sum-=A[i++];
        }
        if(sum==Rsum)
                while(i<j)cout<<A[i++]<<' ';
        cout<<endl;
        return 0;
}
