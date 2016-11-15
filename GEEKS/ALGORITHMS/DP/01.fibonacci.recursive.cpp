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

long long fib (int n)
{       if(n<=1)return n;
        return fib(n-1)+fib(n-2);
}
int main(int argc, char *argv[])
{       // f = 45  - took 11 sec
        // f = 46  - took 16 sec       
        // f = 47  - took 27 sec
        // f = 48  - took 41 sec
        int f=5;
        cout<<"Running...\n";
        cout<<fib(f)<<endl;
        return 0;
}
