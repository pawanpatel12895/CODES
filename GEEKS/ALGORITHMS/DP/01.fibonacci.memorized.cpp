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

long long fib(int n)
{       static long long f[1000]={0};
        if(f[n] == 0)
        {       if(n<=1)
                        f[n]=n;
                else 
                        f[n]=fib(n-1)+fib(n-2);
        }
        return f[n];
}

int main(int argc, char *argv[])
{
        int f=48;
        cout<<"Running...\n";
        cout<<fib(f)<<endl;
        return 0;
}
