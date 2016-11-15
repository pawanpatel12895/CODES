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

template<typename T>
class minHeap
{       vector<T> D;
        #define INFINITE 100000000
        void swap(T &a,T &b)
        {       T c=a;a=b;b=c;}
        T at(int i)
        {       if(i<D.size())return D[i];
                else return INFINITE;
        }
  public:
        minHeap<T>(){D=vector<T>(1,1);};
        void push(T x);
        void pop();
        T top();
        int size(){return D.size()-1;};
        void showHeap();
};
template<typename T>
void minHeap<T>::showHeap()
{       for(int i=1;i<D.size();i++)
                cout<<D[i]<<' ';
        cout<<endl;
}
template<typename T>
void minHeap<T>::push(T x)
{       int i=D.size();
        D.push_back(x);
        while(i!=1&&D[i/2]>D[i])
        {       swap(D[i],D[i/2]);
                i=i>>1;
        }
}
template<typename T>
T minHeap<T>::top()
{       if(D.size()<=1)return INFINITE;
        return D[1];
}
template<typename T>
void minHeap<T>::pop()
{       int i=1;
        while(i<D.size())
        {       if(at(2*i)<at(2*i+1))
                {       D[i]=at(2*i);
                        i=2*i;
                }
                else
                {       D[i]=at(2*i+1);
                        i=2*i+1;
                }
        }
        D[i/2]=D[D.size()-1];
        D.pop_back();
}
int main(int argc, char *argv[])
{       int A[]={1,3,6,8,7,2,3,5,6,7,54,2,2,4}; 
        int n=sizeof(A)/sizeof(A[0]);
        minHeap<int> mH;
        mH.showHeap();
        while(n--)
        {       mH.push(A[n]);
                mH.showHeap();
        }
        return 0;
}

