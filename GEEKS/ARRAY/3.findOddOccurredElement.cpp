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
        int A[100],n;
        int ele=0,i;
        
        cin>>n;
        f0(i,n)
        {       cin>>A[i];
                ele^=A[i];       
        }
        cout<<ele<<endl;
        return 0;
}
