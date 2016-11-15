#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        vector<pair<int,int> > V;
        vector<pair<int,int> >::iterator itr;
        int A[]={1,2,3,4,5,7,8,5};
        int n=sizeof(A)/sizeof(A[0]);
        int i;
        f0(i,n)
                V.push_back( make_pair (A[i]%2,A[i]) ); 
        sort(V.begin(),V.end());      
        
        for(itr = V.begin(); itr!=V.end() ; itr++)
                cout<<" "<<(*itr).second;
        cout<<endl;
        return 0;
}
