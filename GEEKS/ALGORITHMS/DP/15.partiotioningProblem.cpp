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

bool partition(vector<int> &vec,vector<vector<int> > &MAT,int sum,int i,int j)
{       if(i<=0||j<0)return false;
        if()
}

bool partition(vector<int> vec)
{       int sum=0;
        for(int i=0;i<vec.size();i++)sum+=vec[i];
        if(sum&1)return false;
        vector<vector<int> > MAT(N+1,vector<int>(sum/2+1,false));
        for(int i=0;i<MAT.size();i++)
                MAT[i][0]=false;
        for(int i=0;i<MAT[0].size();i++)
                MAT[0][i]=false;
        return partition(vec,MAT,sum/2,vec.size()-1,sum/2);
}

int main(int argc, char *argv[])
{


        return 0;
}
