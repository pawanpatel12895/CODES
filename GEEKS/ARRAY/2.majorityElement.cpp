#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int i,A[100],n;
        int count,num;
        count=0,num=0;
        cin>>n;
        f0(i,n)
        {       cin>>A[i];
                if(count==0)
                {       num=A[i];
                        
                }
                if(A[i] == num)
                        count++;
                else    count--;
                
        }
        count=0;
        f0(i,n)
               if (A[i]==num)count++;
        if(count > n/2 )cout<<"Majority "<<num<<endl;
        else            cout<<"No majority "<<endl;
        return 0;
}
