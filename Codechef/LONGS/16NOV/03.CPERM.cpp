#include<bits/stdc++.h>

#define INF 1111111111
#define MOD 1000000007
#define llong long long
#define ldouble long double
#define _f0(i,n) for(i=0;i<n;++i)
#define _f1(i,n) for(i=1;i<=n;++i)

using namespace std;
//#define MOD 1000000007
long long power(long long P=2,long long N)
{   if(N==0)return 1;
    long long A = power2(N/2);
    A=(A*A)%MOD;
    if(N&1) A=(A*P)%MOD;
    return A;
}
//#define MOD 1000000007
long long mod(long long M)
{   return (M%MOD+MOD)%MOD; }

void testcase(int testcaseNo)
{   long long N;
        cin>>N;
        if(N==1)
            cout<<0<<endl;
        else
            cout<<mod(power2(N-1)-2)<<endl;
}

int main()
{
    int i,T;
    cin>>T;
    _f1(i,T)
        testcase(i);
    return 0;
}
