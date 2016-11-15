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


void printArray(pair<int, pair<int,int> > A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i].first<<' ';
        cout<<endl;
}
bool intersect(pair<int ,pair<int,int> > P,pair<int ,pair<int,int> > Q)
{       if( (P.second.first == Q.second.first) ||
            (P.second.second == Q.second.first) ||
            (P.second.first == Q.second.second) ||
            (P.second.second == Q.second.second) 
          ) return true;
        return false;
}

int main(int argc, char *argv[])
{       int A[]={1,2,5,3,5,8,4,2,5,7,4,2};
        int n=sizeof(A)/sizeof(A[0]);
        int m=(n*(n-1))/2;
        pair<int ,pair<int,int> > P[m];
        pair<int,int> t;        
        int i,j,k,l;
        int sum;
        cin>>sum;
        for(k=i=0;i<n;i++)
               for(j=0;j<i;j++,k++)
                       P[k]=make_pair(A[i]+A[j] , make_pair(j,i) );
        printArray(P,m);
        
        sort (P,P+m);       
         printArray(P,m);
       
        i=0,j=m-1;
        while(i<j)
        {       if(sum == P[i].first+P[j].first && !intersect(P[i],P[j]))
                {       
                cout<<"indexes : "<<P[i].second.first<<" "<<P[i].second.second<<" "<<P[j].second.first<<" "<<P[j].second.second<<endl;
                return 0;
                }
                else if (sum < P[i].first+P[j].first )j--;
                else i++;
        }
 
 
        cout<<"No Quadruples Exist\n";
        return 1;
}
