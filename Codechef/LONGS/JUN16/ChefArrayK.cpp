#include<iostream>
using namespace std;
#define MOD 1000000007
#define llong long long
llong gcdExtended(llong a, llong b, llong *x, llong *y);
 
// Function to find modulo inverse of a
llong modInverse(llong a)
{   llong m=MOD;
    llong x, y;
    llong g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        llong res = (x%m + m) % m;
        return res;
    //
 
    //cout << "Modular multiplicative inverse is " << res;
    }
}
llong power(llong a,llong n)
{   if(n==0)return 1;
    llong p=power(a,n/2);
    p=(p*p)%MOD;
    if(n%2==0)return p;
    else    return (a*p)%MOD;
}
 
 
// C function for extended Euclidean Algorithm
llong gcdExtended(llong a, llong b, llong *x, llong *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    llong x1, y1; // To store results of recursive call
    llong gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
 
 
int main()
{
        int Test;
        cin>>Test;
        while(Test--)
        {       llong N=0,K=0,t,Z=0;
                cin>>N>>K;
 
                for(int i=0;i<N;i++)
                {       cin>>t;
                        if(t==0)Z++;
                }
 
                llong A=1,F=1;
                if(!Z)
                {
                        if(K>=N-1)A=power(2,N-1)%MOD;
                        else
                        {
                                for(llong i=1;i<=min(K,N-1);i++)
                                {       F=(((F*(N-i))%MOD) * modInverse(i)) % MOD;
                                        A=(A+F)%MOD;
                                }
                        }
                }
                else
                {
                        N=N-Z;
                        if(K>=N)A=power(2,N)%MOD;
                        else
                        {
                                for(llong i=1;i<=K;i++)
                                {       F=(((F*(N-i+1))%MOD) * modInverse(i)) % MOD;
                                        A=(A+F)%MOD;
                                }
                        }
                }
                cout<<A<<endl;
        }
        return 0;
}
