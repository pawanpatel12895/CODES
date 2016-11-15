#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(n) for(int ii=1;ii<=n;ii++)
#define f0(n) for(int ii=0;ii< n;ii++)
#define fij(i,j) for(int kk=i;kk<j;kk++)

using namespace std;
/*
/// Recursive
int maxSumSubsequence(vector<int> &V,int i)
{       int m = V[i];
        f0(i)
        {
                if(V[ii] <= V[i])
                        m = max(m,maxSumSubsequence(V,ii));
        }
        return m;
}
*/

int maxSumSubsequence(vector<int> &V,int i)
{       vector<int> A(V.size());
        for(int i=0;i<V.size();i++)
        {       A[i] = V[i];
                for(int j=0;j<i;j++)
                        if(V[j]<V[i])
                                A[i]= max(A[i],V[i]+A[j]);
        }
        return A[V.size()-1];
}

int main(int argc, char *argv[])
{       int A[]={1,3,4,6,7,32,2,14,2,42};
        int n= sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(n--)V.push_back(A[n]);
        reverse(V.begin(),V.end());

        cout<<maxSumSubsequence(V,V.size()-1);

        return 0;
}
