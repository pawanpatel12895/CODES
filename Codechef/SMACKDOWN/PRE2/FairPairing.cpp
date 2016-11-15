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


int main(int argc, char *argv[])
{
        int T;
        cin>>T;
        while(T--)
        {       int N;
                int i;
                cin>>N;
                vector<pair<int,int> > A(N),B(N),C(N);
                for(i=0;i<N;i++)
                {       cin>>A[i].first;
                        A[i].second=i;       
                }
                for(i=0;i<N;i++)
                {       cin>>B[i].first;
                        B[i].second=i;       
                }
                sort   (A.begin(),A.end());
                sort   (B.begin(),B.end());
                reverse(B.begin(),B.end());
                int Ans=0;
                for(i=0;i<N;i++)
                {       C[i].first=A[i].second;
                        C[i].second=B[i].second;
                        if(A[i].first==B[i].first)
                                ++Ans;
                }
                sort(C.begin(),C.end());
                cout<<Ans<<endl;
                for(i=0;i<N;i++)
                cout<<C[i].second<<' ';
                cout<<endl;
        }
        return 0;
}
