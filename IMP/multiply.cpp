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
void multiply(vector<int> &A,int B)
{       vector<int> P=vector<int>(0);
        for(int k=0,i=0,c,x;B;k++,B/=10)
        {       c=0;
                x=B%1000;
                for(i=0;i<A.size();i++)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]+=A[i]*x+c;
                        c=P[i+k]/1000;P[i+k]%=1000;
                        
                }
                if(c)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]=c;
                }
        }
        //printVec(P);
        A=P;
}
void convertToVec(vector<int> &V,int B)
{       
        for(int i=0;  B  ;i++,B/=10)
            V.push_back(B%10);
        if(V.size()==0)
                V.push_back(0);
        reverse(V.begin(),V.end());
}

     
int main(int argc, char *argv[])
{       vector<int> V;
        convertToVec(V,1);
        for(int i=1;i<8;i++)
                multiply(V,i);
        printVec(V);
        cout<<V.size()<<endl;     


        return 0;
}
