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

pair<int,int> minimumLengthSubArray(vector<int> &V)
{       int i,j,s,e,m,M;
        if(V.size()<2)return make_pair(0,0);
        s=0,e=V.size()-1;
        while(s+1<V.size()&&V[s]<V[s+1])s++;        
        if(s+1==V.size())return make_pair(V.size(),V.size());
        while(e>0&& V[e] > V[e-1])e--;
        m=M=V[s+1];
        for(i=s+1;i<e;i++)
                m=min(m,V[i]),M=max(M,V[i]);
        while(s>=0&&V[s]>m)s--;
        while(e<V.size()&&V[e]<M)e++;
        return make_pair(s+1,e);
}

int main(int argc, char *argv[])
{       int A[]={1,2,6,123,124};
        int i=0,n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(i!=n)V.push_back(A[i++]);
        pair<int,int> P=minimumLengthSubArray(V);
        cout<<P.first<<' '<<P.second<<endl;
        return 0;
}
