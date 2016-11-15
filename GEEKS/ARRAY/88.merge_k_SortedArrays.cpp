//Do it again from Scratch
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

void printArray(int A[],int n)
{
        int i;
        f0(i,n)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main(int argc, char *argv[])
{       int A[5][5]=    {{0,23,42,52,62},
                         {-2,2,21,22,24},
                         {-1,4,6,7,12},
                         {1,5,8,10,28},
                         {-7,9,20,40,50}
                        };
        int n=5;
        int Arr[25];
        int i[5]={0},j,nid,l,m,ind,k;
        minHeap mH;     
        mH.insert(INF);  
        for(k=j=0;k<25;k++)
        {       for(l=0,m=INF;l<5;l++)
                {       if(i[l]<5 && A[l][i[l]] < m)
                        {       m=A[l][i[l]];
                                ind=l;
                        }
                }
                if(m!=INF)
                        mH.insert(m);
                i[ind]++;
                if(mH.getTop()==INF)break;
                Arr[j++]=mH.getTop();
                mH.remove();
        }
        printArray(Arr,25);

        return 0;
}
