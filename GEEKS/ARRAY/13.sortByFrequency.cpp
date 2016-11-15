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
        map<int,int> M;
        int A[]={3,2,5,5,2,5,2,2,5};
        int n=9,i;
        
        f0(i,n)
               M[A[i]]++;
        
        vector<pair<int,int> > V2;
        vector<pair<int,int> >::iterator  itr2;
        map<int,int>::iterator itr=M.begin();
        ////// need to debug
        for(itr = M.begin() ; itr !=M.end(); itr++ )
        {       int i = (*itr).first;
                int j = (*itr).second;
//                cout<<i<<':'<<j<<';';
               V2.push_back( make_pair(j,i)) ;
        } 
        sort(V2.begin(),V2.end());
        for(itr2 = V2.begin() ; itr2 !=V2.end(); itr2++ )
        {       int i=(*itr2).first;
                
                while(i--)cout<<(*itr2).second<<' ';
        }
        return 0;
}

