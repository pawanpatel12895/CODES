#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

/*
int KnapSack(vector<pair<int,int> > &items,int capacity,int i)
{       if(i==-1||capacity<=0)return 0;
        if(items[i].first > capacity) return KnapSack(items,capacity,i-1);
        return max(items[i].second
                     +  KnapSack(items,capacity-items[i].first,i-1) 
                     ,  KnapSack(items,capacity,i-1));
}

int KnapSack(vector<pair<int,int> > &items,int capacity)
{       return KnapSack(items,capacity,items.size()-1);        }
*/


//Memorized
int KnapSack(vector<pair<int,int> > &items,int capacity,int i,vector<vector<int> > &MAT)
{       if(i==-1||capacity<=0)return 0;
        if(MAT[i][capacity]==-1)
        {       if(items[i].first > capacity) MAT[i][capacity]=KnapSack(items,capacity,i-1,MAT);
                else MAT[i][capacity]  = max(   items[i].second
                                               +KnapSack(items,capacity-items[i].first,i-1,MAT)
                                               ,KnapSack(items,capacity,i-1,MAT)
                                                );
        }
        return MAT[i][capacity];
}
int KnapSack(vector<pair<int,int> > &items,int capacity)
{       vector<vector<int> > MAT(items.size()+1,vector<int>(capacity+1,-1));
        return KnapSack(items,capacity,items.size()-1,MAT);
}


int main(int argc, char *argv[])
{       vector<pair<int,int> > items;//item(weight,value)
        int capacity = 22;
        items.push_back(make_pair(10,100));
        items.push_back(make_pair(8,120));
        items.push_back(make_pair(12,130));
        items.push_back(make_pair(14,150));
        
        sort(items.begin(),items.end());
        
        cout<<KnapSack(items,capacity)<<endl;

        return 0;
}
