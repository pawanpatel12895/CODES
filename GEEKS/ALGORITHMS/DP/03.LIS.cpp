#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int LIS(vector<int> A)
{       vector<int> L(A.size(),1);
        int m=0;
        for(int i=0;i<A.size();i++)
        {
        for(int j=0;j<i;j++)
        {       if(A[j]<A[i])
                        L[i]=max(L[i],1+L[j]);
        }
        m=max(L[i],m);
        }
        return m;
}

int main(int argc, char *argv[])
{
        int A[]={1,2,3,4,5,6,7,9};
        int n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        reverse(V.begin(),V.end());
        cout<<LIS(V)<<endl;
        return 0;
}
