#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
//#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int main(int argc, char *argv[])
{
        int A[]={1,4,8,4,5,5,1,4,7,7,4,1,4,7,7,7,1,4,7,6};
        int n=sizeof(A)/sizeof(A[0]);
        map<int,int> M;
        map<int,int>::iterator itr;
        vector<pair<int,int> > V;
        vector<pair<int,int> >::iterator vtr;
        int i;
        
        for(i=0;i<n;i++)
                M[A[i]]++;
        for(itr=M.begin() ; itr!=M.end() ; itr++ )
                V.push_back( make_pair((*itr).second,(*itr).first) );       
        sort(V.begin(),V.end());
        for(vtr=V.end();vtr!=V.begin();)
        {       vtr--;
                while((*vtr).first--)
                        cout<<(*vtr).second<<' ';          
        }
        return 0;
}
