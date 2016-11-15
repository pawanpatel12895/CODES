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

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}

int main(int argc, char *argv[])
{
        int A[]={1,2,3,3,4,1,1,1,1,1};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j;
        int jumps[n];
        jumps[0]=0;
        for(i=1;i<n;i++)
        {       jumps[i]=INF;
                for(j=0;j<i;j++)
                {       if (i<=j+A[j]&&jumps [j]!=INF )
                        {       jumps[i]=min(jumps[i],jumps[j]+1);
                 //               break;
                        }        
                }
        }
        printArray(jumps,n);
        cout<<jumps[n-1]<<endl;
        return 0;
}
