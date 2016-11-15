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

long long fib[1000];
void init()
{       fib[0]=0,fib[1]=1;
        for(int i=2;i<1000;i++)
                fib[i]=fib[i-1]+fib[i-2];
}


int main(int argc, char *argv[])
{
        int f=48;
        init();
        cout<<"Running...\n";
        cout<<fib[f]<<endl;
        return 0;
}
