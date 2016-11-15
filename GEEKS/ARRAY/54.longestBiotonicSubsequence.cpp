/** MicrosoftInterview **/

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


void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int lengthOfLongestBiotonicSubArry(int A[],int n)
{       int L[n],S[n];
        int i;
         int m=0;
        S[n-1]=0;
        L[0]=0;
        f1(i,n-1)
        if(A[i-1]>A[i])L[i]=0;else L[i]=L[i-1]+1;
        for(i=n-2;i>0;i--)
                if(A[i]>A[i+1])S[i]=S[i+1]+1;else S[i]=0;
        f0(i,n)m=max(m,L[i]+S[i]+1);
        return m;
}


int main(int argc, char *argv[])
{
        int A[]={1,2,3,44,3,2,23,3,1,2,2,6};
        int n=sizeof(A)/sizeof(A[0]);
        cout<<lengthOfLongestBiotonicSubArry(A,n)<<endl;
        
        return 0;
}
