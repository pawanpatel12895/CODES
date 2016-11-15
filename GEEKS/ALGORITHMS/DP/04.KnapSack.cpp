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

int KnapSack(vector<int> &items,int i,int W)
{       if(W==0||i==-1)return 0;
        if(W < items[i])return KnapSack(items,i-1,W);
        return max(items[i] + KnapSack(items,i-1,W-items[i]),KnapSack(items,i-1,W));
}

int main(int argc, char *argv[])
{       vector<int> V;
        int A[]={1,5,3};
        int n=sizeof(A)/sizeof(A[0]);
        while(n--)V.push_back(A[n]);
        sort(V.begin(),V.end());
        cout<<KnapSack(V,V.size()-1,10)<<endl;
        return 0;
}
