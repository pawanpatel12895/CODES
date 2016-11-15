#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define size 100
using namespace std;

class TwoStacks
{       int A[size];
        int n,m,tot;
        public:
        TwoStacks(){n=0,m=0;tot=size;}
        void push1(int);
        void pop1 ();
        int  top1 ();
        void push2(int);
        void pop2 ();
        int  top2 ();
};
void TwoStacks::push1(int x)
{       if(n+m!=tot)A[n++]=x;       }
void TwoStacks::pop1()
{       if(n)n--;       }
int TwoStacks::top1()
{       if(n)return A[n-1];  
        else return INF;
}

void TwoStacks::push2(int x)
{       if(n+m!=tot)A[tot-m++ -1]=x;}
void TwoStacks::pop2()
{       if(m)m--;       }
int TwoStacks::top2()
{       if(m)return A[tot-m];
        else return INF;
}
int main(int argc, char *argv[])
{       TwoStacks TS;
        TS.push2(1);
        cout<<TS.top2();
        TS.push2(2);
        cout<<TS.top2();
        TS.push2(3);
        cout<<TS.top2();       
        TS.pop2();
        cout<<TS.top2();
        TS.pop2();
        cout<<TS.top2();
        TS.pop2();
        cout<<TS.top2();
        return 0;
}
