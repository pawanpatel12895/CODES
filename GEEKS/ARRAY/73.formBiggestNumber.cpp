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
int revNum(int a)
{       int b=0;
        while(a!=0)
        {       b=a%10+b*10;
                a/=10;
        }
        return b;
}
int myCompare(int a,int b)
{       
        int p=a,q=b,x;
        while(p!=0)p/=10,q*=10;
        x=a+q;
        p=a,q=b;
        while(q!=0)q/=10,p*=10;
        return (x > p+b)? 0: 1;
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i];
        cout<<endl;
}

int main(int argc, char *argv[])
{
        int A[]={1, 34, 3, 98, 9, 76, 45, 4};
        int  n=sizeof(A)/sizeof(A[0]);
        int i,j;
        sort(A,A+n,myCompare);
        printArray(A,n);

        return 0;
}
