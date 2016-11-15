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

bool isprime(int n)
{       if(n==2)return true;
        if(n&1==0)return false;
        int i,s= ceil (sqrt(n));
        for(i=3;i<s;i+=2)
                if(n%i==0)return false;
        return true;
}
void addToSet(map<int,set<int> > &M,int A)
{       int S=ceil(sqrt(A));
        if(A==1||A==2||A==3)
               M[A].insert(A);
        else         
        for(i=1;i<S;i++)
        {       if(A%i==0)
                {       if(isprime(i))
                                M[i].insert(A);
                        if(isprime(A/i))
                                M[A/i].insert(A);
                }
        }
}

int main(int argc, char *argv[])
{       int T;
        cin>>T;
        while(T--)
        {       map<int,set<int> > M;
                int N;
                cin>>N;
                for(int i=0;i<N;i++)
                {       cin>>x;
                        addToSet(M,x);
                }
                cout<<M.size()<<endl;
        }
        return 0;
}
