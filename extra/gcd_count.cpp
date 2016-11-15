/*/
Coder : pawan patel
About Coder : BE 3Yr, SGSITS INDORE  
Topic : gcd  
Date : Saturday April 23 2016 
Requirements : none
Descriptions : counts max recursion of any pair below 10^6
Quote : if it is still in your head, do it. 
/*/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int ct=0,c;
long gcd (long a, long b)
{       if (b==0)return a;
        ct=max(ct,++c);
        return gcd(b,a%b);
}

int main()
{       long i,j;
        f1(i,100000)
        {       f1(j,i/10)
                {       c=0;
                        gcd(i,j);                
                }
        }
        cout<<"***"<<ct<<endl;

        return 0;
}
