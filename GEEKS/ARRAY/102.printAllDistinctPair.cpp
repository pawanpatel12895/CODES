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
{       int A[]={1,3,5,7,7,3,3,6,8,8,4,2,4,7,8,5};
        int n=sizeof(A)/sizeof(A[0]);
        set<int> S;
        set<int>::iterator itr;
        for(int i=0;i<n;i++)
                S.insert(A[i]);
        for(itr=S.begin();itr!=S.end();itr++)
                cout<<*itr<<' ';                
        cout<<endl;
        return 0;
}
