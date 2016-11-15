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
void swap(int *a,int *b)
{       int *c=b;
        b=a;
        a=c;
}
class minHeap
{       int A[100];
        int n;
        public:
        minHeap(){n=0;}
        void insert(int x);
        void printHeap();
        void remove();
        int getTop();
};
int minHeap::getTop()
{       return A[1];
}
void minHeap::remove()
{       int i=1;
        while(i<n)
        if( A[i*2]<A[i*2+1] )
        {       A[i]=A[i*2];
                i*=2;
        }
        else
        {       A[i]=A[i*2+1];
                i=i*2+1;
        }
        
        A[i/2]=A[n];
        n--;
}
void minHeap::printHeap()
{
        int i;
        f1(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
void minHeap::insert(int x)
{       n++;
        A[n]=x;
        int i=n;
        while(i!=1&& A[i] < A[i/2] )
        {        swap(A[i],A[i/2]);
                 i/=2;     
        }      
}
int main(int argc, char *argv[])
{
        int A[]={1,4,8,6,5,43,3,5,7,8,8,6,43,33,4,67,76};
        int n=sizeof(A)/sizeof(A[0]);
        int i,k=2;
        minHeap MH;
        
        for(i=0;i<n;i++)
        {                MH.insert(A[i]);
                if(k)
                        k--;
                else
                        MH.remove();
        }
        cout<<MH.getTop()<<endl;
        
        return 0;
}
