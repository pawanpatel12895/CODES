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
2
int main(int argc, char *argv[])
{       int A[]={1,34,5,6,7,8,6,5,4,4,56,7,7,5,4};
        int n=sizeof(A)/sizeof(A[0]);
        Tree T;
        while(n--)T.insert(A[n]);
        T.inorder();
        cout<<T.size()<<endl;
        return 0;
}
