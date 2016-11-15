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

int maxSubArraySum(int A[],int n)
{
        if (n==1)return max(A[0],0);
        int i,s1=0,s2=0,m=0;
        for(i=n/2+1;i<n;i++)
        {       s1+=A[i];
                m=max(s1,m);
        }
        s1=m;m=0;
        for(i=n/2;i>=0;i--)
        {       s2+=A[i];
                m=max(s2,m);
        }
        s2=m;
        m=max(maxSubArraySum(A,n/2),maxSubArraySum(A+n/2,n-n/2));
        return max(m,s1+s2);
}


int main(int argc, char *argv[])
{       int A[]={1,2,2,-10,5,6,2,-50,14,-5,20};
        int n=sizeof(A)/sizeof(A[0]);
        
        cout<< maxSubArraySum(A,n)<<endl;

        return 0;
}
