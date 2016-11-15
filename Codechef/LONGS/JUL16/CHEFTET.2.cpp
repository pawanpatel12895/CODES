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

void stacy()
{
        long long N,i,p,sum=0,num;
        cin>>N;
        vector<long long > A(N),B(N);
        f0(i,N)
        {       cin>>B[i];
                sum+=B[i];
        }
        f0(i,N)
        {       cin>>A[i];
                sum+=A[i];
        }
        if(sum%N)
        {       cout<<-1<<endl;
                return;
        }
        num = sum/N;
        long flag=1;
        if(num==A[0]);
        else if(num==A[0]+B[0]);
        else if(num==A[0]+B[1]);
        else if(num==A[0]+B[1]+B[0]);
        else flag=0;
        
        for(i=1;i<N-1;i++)
        {            if(num==A[i]);
                else if(num==A[i]+B[i-1]);
                else if(num==A[i]+B[i  ]);
                else if(num==A[i]+B[i+1]);
                else if(num==A[i]+B[i-1]+B[i  ]);
                else if(num==A[i]+B[i-1]+B[i+1]);
                else if(num==A[i]+B[i  ]+B[i+1]);
                else if(num==A[i]+B[i-1]+B[i  ]+B[i+1]);
                else flag=0;
        }
        if(num==A[N-1]);
        else if(num==A[N-1]+B[N-1]);
        else if(num==A[N-1]+B[N-2]);
        else if(num==A[N-1]+B[N-1]+B[N-2]);
        else flag=0;
        
        if(flag)
        cout<<num<<endl;
        else cout<<-1<<endl;
}


int main(int argc, char *argv[])
{
        int T;
        cin>>T;
        while(T--)
                stacy();

        return 0;
}
