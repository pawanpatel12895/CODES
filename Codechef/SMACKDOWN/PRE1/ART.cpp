#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 1000001
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int T,N;
        cin>>T;
        int A[size];
        while(T--)
        {       cin>>N;
                int f=0;
                cin>>A[0]>>A[1];
                for(int i=2;i<N;i++)
                {       cin>>A[i];
                        if(A[i]==A[i-1]&&A[i-2]==A[i-1])
                                f=1;
                }
                if(f)
                        cout<<"Yes\n";
                else    cout<<"No\n";
        }

        return 0;
}
