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

void findElements(int A[],int n,int k)
{
        pair<int,int> P[k-1];
        int i,j;
        for(i=0;i<k-1;i++)
                P[i].second=0;

        for(i=0;i<n;i++)
        {       //if present
                for(j=0;j<k-1;j++)
                       if(P[j].first==A[i])
                        {        P[j].second++;
                                break;
                        }
                if(j==k-1)      //if Not Present
                {       for(j=0;j<k-1;j++) // if space is avail in P<int,int>
                               if(P[j].second==0)
                                {       P[j].first=A[i];
                                        P[j].second++;
                                        break;
                                }
                        if(j==k-1)      //eleminate
                        {       for(j=0;j<k-1;j++)
                                        P[j].second--;
                        
                        }
                }
        }
        
        for(i=0;i<k-1;i++)
        {       if(P[i].second >= n/k)
                        cout<<P[i].first<<' ';
        }
}


int main(int argc, char *argv[])
{
        int A[]={3,1,2,2,2,1,4,3,3};
        int n=sizeof(A)/sizeof(A[0]);

        findElements(A,n,4);
        cout<<';';

        return 0;
}
