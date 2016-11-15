#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>
#define INF 10000000
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

void swap(int *a,int *b)
{       int *c=b;
        b=a;
        a=c;
}
class maxHeap
{       int A[100];
        int n;
        public:
        maxHeap(){n=0;}
        void insert(int x);
        void printHeap();
        void remove();
        int getTop();
};
int maxHeap::getTop()
{       if(n==0)return INF;
       return A[1];
}
void maxHeap::remove()
{       int i=1;
        while(i<n)
        if( A[i*2]>A[i*2+1] )
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
void maxHeap::printHeap()
{
        int i;
        f1(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
void maxHeap::insert(int x)
{       n++;
        A[n]=x;
        int i=n;
        while(i!=1&& A[i] > A[i/2] )
        {        swap(A[i],A[i/2]);
                 i/=2;     
        }      
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
{       if(n==0)return INF;       
        return A[1];
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
       
       maxHeap MH;
       minHeap mH;
       int A[]={5,1,3,5,6,3,1};
       int n=sizeof(A)/sizeof(A[0]);
       int bal=0,i;
       int median=0;
       
       for(i=0;i<n;i++)
       {        switch(bal)
                {       case 0:if (A[i] < median)
                                {       MH.insert(A[i]);
                                        median = MH.getTop();
                                        bal =-1;
                                } 
                                else 
                                {       mH.insert(A[i]);
                                        median = mH.getTop();
                                        bal = 1;
                                }       
                                break;
                        case 1: if (A[i] < median)
                                       MH.insert(A[i]);
                                        
                                else 
                                {       MH.insert(mH.getTop());
                                        mH.remove();
                                        mH.insert(A[i]);
                                }
                                bal=0;
                                median = ( mH.getTop()+MH.getTop() )/2;
                                break;
                        case -1 :if (A[i] >= median)
                                {
                                       mH.insert(A[i]);
                                }       
                                else 
                                {       mH.insert(MH.getTop());
                                        MH.remove();
                                        MH.insert(A[i]);
                                }
                                bal=0;
                                median = ( mH.getTop()+MH.getTop() )/2;
                                break;
                }
                cout<<median<<' ';
       }
        return 0;
}
