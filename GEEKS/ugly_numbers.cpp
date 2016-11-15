/*/
Coder : pawan patel
About Coder : BE 3Yr, SGSITS INDORE  
Topic : dynamic programming , ugly numbers
Date : Saturday April 23 2016 
Requirements : none
Descriptions : numbers which are purely divisible by 2 or 3 or 5
Paradigm : Dynamic Prog.
Quote : if it is still in your head, do it. 
/*/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define _for1(i,n) for(i=1;i<=n;i++)
#define _for0(i,n) for(i=0;i< n;i++)

using namespace std;
inline int min(int a,int b,int c)
{
        return min(a,min(b,c));
}

int main()
{       
        int Arr[1000];
        
        int i2,i3,i5,i;
        Arr[0]=1;
        i2=i3=i5=0;
        
        for(i=1;i<100;i++)
        {      Arr[i]=min(Arr[i2]*2,Arr[i3]*3,Arr[i5]*5);
               if(Arr[i]==Arr[i2]*2)i2++;  
               if(Arr[i]==Arr[i3]*3)i3++;  
               if(Arr[i]==Arr[i5]*5)i5++;
               cout<<Arr[i]<<' ';
        }
        return 0;
}

