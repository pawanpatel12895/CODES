

/*/
Coder : pawan patel
About Coder : BE 3Yr, SGSITS INDORE  
Topic : find pair of which product is maximum from an array of list 
Date : Monday April 18 2016 
Requirements : size of array, array eements
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
using namespace std;
int main()
{
        int n, i, arr[100];
        cin>>n;
        
        int m1,m2,l1,l2;
        m1=m2=l1=l2=0;
        f1(i,n)
        {
                cin>>arr[i];
                if(arr[i]>m2)
                        if(arr[i]>m1)
                        {       m2=m1;
                                m1=arr[i];
                        }
                        else
                                m2=arr[i];                
                 else if (arr[i]<l2)
                        if(arr[i]<l1)
                        {       l2=l1;
                                l1=arr[i];
                        }              
                        else
                                l2=arr[i];
        }
        cout<<max(l1*l2,m1*m2)<<endl;       
        return 0;
}
