#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define MOD 1000000007
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

void multiply(string &A,llong B)
{       string P;
        for(llong k=0,i=0,c,x;B;k++,B/=10)
        {       c=0;
                x=B%10;
                if(A.size()>20)i=A.size()-20;
                else i=0;
                for(;i<A.size();i++)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]+=A[i]*x+c;
                        c=P[i+k]/10;P[i+k]%=10;
                        
                }
                if(c)
                {       if(i+k==P.size())P.push_back(0);
                        P[i+k]=c;
                }
        }
        A=P;
}
void prllongVec(string &s)
{       for(llong i=0;i<s.size();i++)
                cout<<(llong)s[i];
        cout<<endl;
}

int main(int argc, char *argv[])
{
        llong N;
        cin>>N;
        vector<llong> V(N+1);
        for(llong i=1;i<=N;i++)
                cin>>V[i];
        llong Q,ch,a,b;
        cin>>Q;
        while(Q--)
        {       cin>>ch>>a;
                if(ch==1)
                {       cin>>b;
                        V[a]=b;
                }
                else
                {       llong Ans=1;
                        string s=string(1,1);       
                        for(llong i=1;i<=N;i+=a)
                        {       multiply(s,V[i]);
                                Ans=(Ans*V[i])%MOD;
                        }
                        cout<<(llong)s[s.size()-1]<<' '<<Ans<<endl;
                }
        }
        return 0;
}

