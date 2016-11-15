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

bool isPalin(string S,int i,int j)
{       while(i<j)
                if(S[i++]!=S[j--])return false;
        return true;
}

int PP(string S)
{
        vector<int> parts(S.size()+1,INF);
        parts[0]=-1;
        for(int i=1;i<parts.size();i++)
                for(int j=0;j<i;j++)
                {       if(isPalin(S,j,i-1))
                                parts[i]=min(parts[i],parts[j]+1);
                }
        return parts[S.size()];
}

int main(int argc, char *argv[])
{
        string S;
        cin>>S;
        cout<<PP(S)<<endl;
        return 0;
}
