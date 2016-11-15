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

int smallestSubarray(int A[],int n,int sum)
{       int i,j,k,S,len=INF;
        A[n]=0;
        for(i=j=S=0;i<=n;)
        {       if(S<=sum)
                        S+=A[i++];
                else 
                {       len=min(len,i-j);
                        S-=A[j++];
                }
        }
        return len;
}


int main(int argc, char *argv[])
{       int A[]={3,5,2,4,5,3,3,7,4,3,2,3};
        int n=sizeof(A)/sizeof(A[0]);
        int sum=6;
        
        cout<< smallestSubarray(A,n,sum)<<endl;
        
        
        return 0;
}
