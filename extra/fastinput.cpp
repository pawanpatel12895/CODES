/*/
Coder : pawan patel
About Coder : BE 3Yr, SGSITS INDORE  
Topic : 
Date : 
Requirements : 
Descriptions : 
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
#define gc getchar_unlocked
using namespace std;
void finput(llong &x)
{
   register llong c = gc();
   x = 0;
   llong neg = 0;
   for(; ((c<48||c>57)&&c!='-'); c=gc() );
   if(c=='-') 
   {  neg=1;
      c=gc();
   }
   for(;c>47&&c<58 ; c=gc()) 
   {  x=(x<<1) + (x<<3) + c - 48;
   }
   if(neg) 
      x=-x;
}

int main()
{       llong x;
        finput(x);

        return 0;
}
