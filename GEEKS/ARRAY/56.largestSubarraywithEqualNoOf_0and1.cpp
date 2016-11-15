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

void printArray(int  A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
void LargestSubarray(int A[],int n)
{       int i,j;
        f0(i,n)if(A[i]==0)A[i]=-1;

        int sumL[n+1];
        int m,M;
        sumL[0]=m=M=A[0];
 
        f1(i,n-1)
        {       sumL[i]=A[i]+sumL[i-1];
                M=max(M,sumL[i]);
                m=min(m,sumL[i]);
        }
        f0(i,n){sumL[i]-=m;};
        cout<<m<<endl;
        
        
        int hash[M-m+1];
        f0(i,n){hash[i]=INF;}
        cout<<sizeof(hash)/sizeof(hash[0])<<endl;
        sumL[0]=A[0]-m;
 
        int MA=0;int a,b;
        printArray(sumL,n);
        f0(i,n)
        {       if(hash[sumL[i]]==INF)
                        hash[sumL[i]]=i;
                else 
                        if( sumL[hash[sumL[i]]] == sumL[i] &&  MA < abs((hash[sumL[i]] - i))+ 1 )
                        {       a=hash[sumL[i]];
                                b=i;
                                MA=abs((hash[sumL[i]] - i))+ 1;
                        }
                 cout<<':'<<sumL[hash[sumL[i]]]<<' '<< sumL[i]<<endl; 
        }
        printArray(hash,M-m+1);
        cout<<a<<' '<<b<<endl;
}

int main(int argc, char *argv[])
{
        int A[]={0,0,1,1,0};
        int n=sizeof(A)/sizeof(A[0]);
LargestSubarray(A,n);



        return 0;
}
