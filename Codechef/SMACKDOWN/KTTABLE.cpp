#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{      long N,T,i,x,j;
        cin>>T;
        while(T--)
        {       cin>>N;
                long A[N],B[N];
                f0(i,N)cin>>A[i];       
                f0(i,N)cin>>B[i];       
                for(i=N-1;i>0;i--)
                        A[i]-=A[i-1];
               // sort(A,A+N);
               // sort(B,B+N);
                
                for(j=i=0;i<N;i++)
                if(B[i]<=A[i])j++;
                
                cout<<j<<endl;
        }        


        return 0;
}
