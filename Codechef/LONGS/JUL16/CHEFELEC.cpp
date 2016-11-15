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
long min(long a,long b)
{       return (a<b)?a:b;
}

int main(int argc, char *argv[])
{       
        ios_base::sync_with_stdio(false);
        int T;
        cin>>T;
        while(T--)
        {       string S;
                long x,N;
                cin>>N>>S;
                vector<long> V(N),left(N),right(N);
                for(int i=0;i<N;i++)
                        cin>>V[i];
                
                if(S[0] == '0') left[0] = INF;
                else            left[0] = 0;
                for(int i=1;i<N;i++)
                        if(S[i]=='1')left[i] = 0;
                        else if(left[i-1] == INF)left[i] = INF;
                        else         left[i] = V[i] - V[i-1];
        
                if(S[N-1]=='0') right[N-1]=INF;
                else            right[N-1]=0;
                for(int i=N-2;i>=0;i--)
                        if(S[i]=='1')right[i] = 0;
                        else if(right[i+1]==INF)right[i]=INF;
                        else right[i]=V[i+1]-V[i];
                
                long Sum=0;
                for(int i=0;i<N;i++)
                        Sum+=min(left[i],right[i]);
                cout<<Sum<<endl;
        }
        return 0;
}
