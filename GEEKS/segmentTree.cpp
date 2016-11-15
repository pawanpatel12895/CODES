#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define ulong unsigned long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class SegmentTree
{
        int *Arr;
        int N;
        public:
        SegmentTree(){Arr=NULL;N=0;}
        SegmentTree(int n){       N=n;
                                Arr=(int *)malloc(2*n*sizeof(int));       
                          }
        ~SegmentTree(){free(Arr);}
        void set(int i,int d);
        int  get(int i);
        int  getRangedQuerry(int l,int r);
        void printAll();
};
void SegmentTree::set(int i,int d)        
{       *(Arr+N+i)=d;
}
int SegmentTree::get(int i)
{       return *(Arr+N+i);
}
int SegmentTree::getRangedQuerry(int l,int r)
{       return 0;
}
void SegmentTree::printAll()
{      int i;
       f0(i,2*N){cout<<*(Arr+i)<<" ";}
}
       

int main()
{       SegmentTree T=SegmentTree(3);
        T.set(2,50);
        cout<<T.get(2)<<endl;
        T.printAll();
        return 0;
}
