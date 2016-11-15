#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        long long T,K;
        cin>>T;
        while(T--)
        {       string S;
                cin>>K;
                K--;
                while(K)
                {       S.push_back((char)(((K%5)*2)+'0'));
                        K/=5;
                }
                if(S.size()==0)S.push_back('0');
                reverse(S.begin(),S.end());
                cout<<S<<endl;
        }

        return 0;
}
