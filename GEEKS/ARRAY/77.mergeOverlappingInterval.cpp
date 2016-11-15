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
{       pair<int,int> P[]={ {1,2},{3,4},{9,10},{8,9},{6,7},{4,6} };
        int n=sizeof(P)/sizeof(P[0]);
        stack<pair<int,int> > S;
        
        int i,j;
        sort(P,P+n);
        
        for(i=0;i<n;i++)
        {
                while(!S.empty()&&S.top().second >= P[i].first)      
                {       P[i].first=S.top().first;
                        S.pop();
                }        
                S.push(P[i]);       
        }
        while(!S.empty())
        {       cout<<S.top().first<<' '<<S.top().second<<endl;
                S.pop();
        }
        return 0;
}
