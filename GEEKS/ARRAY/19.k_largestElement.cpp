#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)

void swap(int * a,int * b)
{       int * c=a;
        a=b;
        b=c;
}
using namespace std;
class minHeap
{       int A[100];
        int n;
        public:
        minHeap(){n=0;}
        void insert(int x);
        void printHeap();
        int  remove();
        int getTop();
};
int minHeap::getTop()
{       return A[1];
}
int minHeap::remove()
{       if(n==0)return INF;       
        if (n==1){int t=A[1];A[1]=INF;return t;}
        
        int i=1,t=A[1];
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
        return t;
}
void minHeap::printHeap()
{
        int i;
        f1(i,n)
                cout<<A[i]<<' ';
}


void minHeap::insert(int x)
{       n++;
        A[n]=x;
        int i=n;
        while(i!=1&& A[i] < A[i/2] )
        {        swap(A[i],A[i/2]);
                 i/=2;
 //                cout<<'.';       
        }
       
}

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
}
int main(int argc, char *argv[])
{
        int A[]={6,3,7,4,2,8,9,1,0,5};
        int n=10,i,k;
        minHeap MH;
        cin>>k;
        
        f0(i,k)
                MH.insert(A[i]);
        for(i=k;i<n;i++)
                if (MH.getTop() < A[i])
                {       MH.remove();
                        MH.insert(A[i]);
                }
        MH.printHeap();
        return 0;
}
