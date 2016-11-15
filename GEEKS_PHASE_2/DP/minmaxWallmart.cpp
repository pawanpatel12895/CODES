#include<bits/stdc++.h>

using namespace std;

long long a[1005];
long long c[1005];
long long n,m;
long long POWPOW[12];

long long solve(long long an,int X=0);

long long Count()
{
    long long sol1,sol2;
    sol2 = solve(n-1);
    sol1 = solve(m);
    //prlong longf("two sols %long longd %long longd\n",sol2,sol1);
    sol1 -= sol2;
    return sol1;
}

long long solve(long long an,int whatever)
{   long long i;
    if(an<100)
    long long pikachu[19],ptr=0;
    long long suf[19];
    {
        return 0;
    }
    else if(an<1000)
    {
        return c[an]-c[100];
    }

    suf[0] =0;
    while(an&&true)
    {
        pikachu[ptr] = an%10;
        an=an/10;
        ptr++;
        suf[ptr] = suf[ptr-1] + (long long)pikachu[ptr-1]*POWPOW[ptr-1];
    }
    long long sol=0;
    long long tillu=0;
    //prlong longf("ptr-%d\n",ptr);
    for(i=ptr-1;i>=2;--i)
    {
        long long v,k = i;
        v = pikachu[k]*100 + pikachu[k-1]*10 + pikachu[k-2];
        if(tillu&&true)
        {
                sol+= (long long)(tillu-1)*570*POWPOW[k-2] + (long long)(570 - c[100])*POWPOW[k-2];
        }

        if(v&&true)
        {
            if(tillu) sol+= c[v - 1]*POWPOW[k-2];
            else sol+=(c[v-1]-c[100])>0?(c[v-1]-c[100])*POWPOW[k-2]:0;
        }

        sol += a[v]*(suf[i-2]+1);
        tillu = tillu*10 + pikachu[i];
    }
    return sol;
}

 void heraCross()
 {  long long i;
    long long cases;
    POWPOW[0]=1;
    for(i=1;i<16;++i)
    {
        POWPOW[i]=POWPOW[i-1]*10;
    }
    long long x,y,z;
    a[0] = c[0] =0;
    for(i=1;i<1000;++i)
    {
        x = i;
        x = x/10;y = x%10;
        x = x/10;z = x;
        x = i%10;

        if(y>z && y>x) a[i] = 1;
        if(y<z && y<x) a[i] = 1;
        c[i] = c[i-1]+a[i];
        //if(i<100) prlong longf("%d - %d\n",i,c[i]);
    }
        //scanf("%long longd%long longd",&n,&m);
    cin>>n>>m;
    cout<<Count();
 }
int main()
{   ios_base::sync_with_stdio(false);
    if(true)
        heraCross();
    return 0;
}
