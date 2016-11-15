#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define MM(a,b) (a>b)?a:b;
using namespace std;

void printArray(llong A[],llong n)
{
        llong i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{       llong N,T,i,M,j;
        llong maxSum,maxSoFar;
        cin>>T;
        while(T--)
        {       M=-INF;
                cin>>N;
                llong A[N],B[N],C[N];
                f0(i,N)
                {       cin>>A[i];
                        M=max(M,A[i]);
                }
 
                if(M<0)maxSum=M;
                else
                {       maxSoFar=0;
                        maxSum=0;
                        f0(i,N)
                        {       B[i]=maxSoFar=max(maxSoFar+A[i],(llong)0);
                                maxSum=max(maxSoFar,maxSum); 
                        }
                        maxSoFar=0;
                        for(i=N-1;i>=0;i--)
                        {       C[i]=maxSoFar=max(maxSoFar+A[i],(llong)0);
                                maxSum=max(maxSoFar,maxSum); 
                        }
                       // printArray(B,N);
                       // printArray(C,N);
                        f0(i,N-2)if(A[i+1]<0)
                        maxSum=max(maxSum,B[i]+C[i+2]);        
                }
                cout<<maxSum<<endl;
        }


        return 0;
}
