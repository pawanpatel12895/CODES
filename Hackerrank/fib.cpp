#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
llong fib[1000];
int tot=2;
void setFib()
{       fib[0]=0;
        fib[1]=fib[2]=1;
        int i;
        for(i=3;i<1000;i++)
        {       fib[i]=fib[i-1]+fib[i-2];
                if(fib[i]<fib[i-1])break;
                tot++;
        }

}
void print()
{       int i;
        f1(i,tot)
         cout<<i<<" : "<<fib[i]<<endl;

}
llong FIB[50];
int total=0;
void evenFib()
{
        int i,j=1;
        f1(i,tot)
        {   if(fib[i]%2==0)
                {       FIB[j]=fib[i];
                        j++;
                        total++;
                }           
        }
}
unsigned llong compute(llong N)
{       int i;
        unsigned llong Sum=0;
        for(i=0;FIB[i]<=N;i++)
        {       Sum+=FIB[i];
        
        }
        return Sum;
}
int main()
{       setFib();
        evenFib();
        llong T,N;
        cin>>T;
        while(T--)
        {
                cin>>N;
                cout<<compute(N)<<endl;
        
        }
        //print();
        return 0;
}
