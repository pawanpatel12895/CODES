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

int f(int x){return x*x-20*x-100;}

int BinSearch(int a,int b)
{
        if(b-a==1)return b;
        if( f(a+(b-a)/2) <= 0 )
                return BinSearch(a+(b-a)/2,b);
        else    return BinSearch(a,a+(b-a)/2);
}

int findFirstPositive()
{       if(f(0)>0)return 0;
        int i=1;
        while(f(i)<=0)
                i*=2;
        
        return BinSearch(i/2,i);
}




int main(int argc, char *argv[])
{       
        cout<<findFirstPositive()<<endl;

        return 0;
}
