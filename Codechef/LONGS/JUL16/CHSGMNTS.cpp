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

void Rebecca()
{       int i,j,N;
        cin>>N;
        vector<int > orig(N),next(N,-1),prev(N,-1);
        f0(i,N)
        {       cin>>orig[i];
                for(j=i-1;j>=0;j--)
                        if(orig[i]==orig[j])
                        {	next[i]=j;break;	}
        }
        for(i=N-1;i>=0;i--)
        	for(j=i+1;j<N;j++)
        		if(orig[i]==orig[j])
        		{	prev[i]=j;break;	}
        
        for(i=0;i<orig.size();i++)
        	cout<<orig[i]<<' ';
        cout<<endl;
        
        for(i=0;i<next.size();i++)
        	cout<<next[i]<<' ';
		cout<<endl;
		for(i=0;i<prev.size();i++)
        	cout<<prev[i]<<' ';
		cout<<endl;
}


int main(int argc, char *argv[])
{
        int T;
        cin>>T;
        while(T--)
                Rebecca();

        return 0;
}
