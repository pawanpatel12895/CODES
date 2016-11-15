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

void closestTo_x(vector<int> &V,int x)
{       if(V.size()<2)return;       
        int i=0,j=V.size()-1;
        int a=V[i],b=V[j];
        cout<<' ';
        while(i<j)
        {       if(abs(a+b-x) > abs(V[i]+V[j]-x))
                        a=V[i],b=V[j];
                else if(V[i] + V[j] < x)i++;    
                else j--;   
        }
        cout<<a<<' '<<b<<endl;
}


int main(int argc, char *argv[])
{
        int A[]={1,2,4,6,7,8,9,12,34,56};
        int i=0,n=sizeof(A)/sizeof(A[0]);
        vector<int> V;
        while(i<n) V.push_back(A[i++]);
        closestTo_x(V,25);
        return 0;
}
