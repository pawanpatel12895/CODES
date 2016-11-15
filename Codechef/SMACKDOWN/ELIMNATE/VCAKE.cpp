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

void swap(int &a,int &b)
{       int  c=a;
        a=b;
        b=c;
}


int main(int argc, char *argv[])
{
        int T;
        cin>>T;
        while(T--)
        {       long long R,C,M,K,J;
                cin>>R>>C>>M>>K>>J;
                if(M+K+J>R*C){cout<<"No\n";continue;}
                
                if(K<M)swap(K,M);
                if(K<J)swap(K,J);
                if(J<M)swap(J,M);
                
                if(R<C)swap(R,C)
                
                
                long long s= floor(sqrt(R));
                
                if(K/s > )
                rect1_R = K/s; 
                rect1_C = C-s;
                rect2_R = R- K/s;
                rect2_C = C;
                
                if()
                
        }
        return 0;
}
