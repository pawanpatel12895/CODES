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

template <typename T>
class segmentTree
{       vector<T> data;
        int size;
       public: 
        segmentTree(){size=0;}
        void insert(vector<T> &V);
        void update(int,T);
};
template <typename T>
void segmentTree<T>::insert(vector<T> &V)
{       size=V.size();
        if(size==0)return;
        int i,j,pow=1;
        for(i=0;i<size;i++)    data.push_back(V[i]);        
        while(pow<size)pow=pow<<1;
        for(i=size;i<pow;i++)  data.push_back(0);
        reverse(data.begin(),data.end());
        for(i=0,j=pow-1;i!=j;i+=2,j++)
                data.push_back(data[i]+data[i+1]);
        reverse(data.begin(),data.end());
}
template<typename T>
void segmentTree<T>::update(int index,T val)
{       

}
int main(int argc, char *argv[])
{       int A[]={1,2,3,5,6};
        int n=sizeof(A)/sizeof(A[0]);
        segmentTree<int> S;
        Tree T;
        while(n--)
                T.push_back(A[n]);
              
        return 0;
}
