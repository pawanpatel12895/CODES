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
int f(int x)//infinite Array f(x) at index x
{return x*x - 20*x -100;}

int binSearch(int i,int j,int key)
{       int m=(i+j)/2;
        if(j-i==1)if(f(i)==key)return i;
                else return -1;
        if(f(m)==key)return m;
        if( key<f(m))return binSearch(i,m,key);
        return binSearch(m,j,key);
        
}
int main(int argc, char *argv[])
{       int x,i;
        int key=-4;
        for(i=1;f(i)<=key;i*=2);
        i=binSearch(i/2,i,key);
        cout<<i<<endl;;
        return 0;
}
