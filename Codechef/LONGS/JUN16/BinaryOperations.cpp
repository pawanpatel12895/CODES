#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{
        int T,i,c1,c2,b1,b2;
        string A,B;
        cin>>T;
        while(T--)
        {       cin>>A>>B;
                if(A.size()!=B.size())
                        cout<<"Unlucky Chef\n";
                else
                {       c1=c2=b1=b2=0;
                        f0(i,A.size())
                        {       if(A[i]=='0'&&B[i]=='1')       
                                        c1++;
                                else if(A[i]=='1'&&B[i]=='0')
                                        c2++;
                                if(A[i]=='0')b1++;
                                if(B[i]=='0')b2++;
                        }
                        if((b1==0&&b2!=0)||(b1==A.size()&&b2!=A.size()))
                                cout<<"Unlucky Chef\n";
                        else cout<<"Lucky Chef\n"<<max(c1,c2)<<endl;
                }
        }

        return 0;
}
