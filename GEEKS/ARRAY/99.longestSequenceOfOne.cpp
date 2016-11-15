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
{       int A[]={1,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,};
        int n=sizeof(A)/sizeof(A[0]);
        int i,j,k,l;
        
        k=j=l=0;
        int maxLen=0,ind=0;
        for(j=0;j<n;j++)
                if(A[j]==0)break;
        for(i=j+1;i<n;i++)
        {       if(A[i]==0)
                {       if(maxLen < i-k)
                        {       maxLen=i-k;
                                ind=j;
                        }
                        k=j;j=i;
                }
        }
        cout<<ind<<endl;

        return 0;
}
