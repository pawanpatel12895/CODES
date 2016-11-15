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
llong gcd (llong a, llong b)
{       if (b==0)return a;
        return gcd(b,a%b);
}

int main(int argc, char *argv[])
{
        llong T,A,B,C,D,E,F;
        cin>>T;
        while(T--)
        {
                cin>>A>>B>>C>>D;
                E=gcd(C,D);
                F=floor(abs(B-A)/E);
                C=min(A,B);
                D=max(A,B);
                C+=F*E;
                cout<<min(abs(C-D),abs(C+E-D))<<endl;         
        }

        return 0;
}
