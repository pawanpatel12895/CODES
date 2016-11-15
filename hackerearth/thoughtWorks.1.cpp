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

bool isPrime(int N)
{       if(N==1)return false;
        if(N==2)return true;
        if(N%2==0)return false;
        int sq=ceil(sqrt(N));
        for(int i=3;i<=sq;i+=2)
                if(N%i==0)return false;
        return true; 
}

int main(int argc, char *argv[])
{
        ios_base::sync_with_stdio(false);

        long Sum=0,Msum=0;
        int N;
        
        cin>>N;
        vector<int> points(N);
        int window=N;
        if(N==1)
        {       cin>>points[0];
                cout<<points[0]<<endl;
                return 0 ;
        }
        while(!isPrime(window))--window;
        for(int i=0;i<window;i++)
        {       cin>>points[i];
                Sum+=points[i];
        }
        Msum=Sum;
        for(int i=window;i<N;i++)
        {       cin>>points[i];
                Sum+=points[i];
                Sum-=points[i-window];
                Msum=max(Msum,Sum);
        }
        cout<<Msum<<endl;
        return 0;
}
