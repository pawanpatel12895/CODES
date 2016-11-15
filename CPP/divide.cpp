#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
void divide(vector<int> &A,int B)
{       vector<int> V;
        
        int c=0;
        for(int i=A.size()-1;i>=0;i--)
        {       c=c*10+A[i];
                V.push_back(c/B);
                c=c%B;
        }
        reverse(V.begin(),V.end());
        while(V[V.size()-1]==0&&V.size())
                V.pop_back();
                
        printVec(V);        
}
void convertToVec(vector<int> &V,int B)
{       
        for(int i=0;  B  ;i++,B/=10)
            V.push_back(B%10);
        if(V.size()==0)
                V.push_back(0);
        //reverse(V.begin(),V.end());
}

int main(int argc, char *argv[])
{       vector<int> V;
        convertToVec(V,2048);
        printVec(V);
        divide(V,16);
        return 0;
}
