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


int main(int argc, char *argv[])
{
        int A[]={1,7,3,6,9,4,6,8,9,3,4578};
        int n=sizeof(A)/sizeof(A[0]);
        set<int> S;
        int min=-1;
        for(int i=n-1;i>=0;i--)
        {      
                if(S.find(A[i])!=S.end())
                        min=i;
                else S.insert(A[i]);
        }
        if(min==-1)cout<<"No Repeating Elements \n";
        else       cout<<A[min]<<endl;
        return 0;
}
