#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;
// C function for extended Euclidean Algorithm
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
        return  (x%m + m) % m;
        
    }
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
void printVec(string &A)
{       for(llong i=0;i<A.size();i++)
                cout<<(llong)A[i]<<' ';
        cout<<endl;
}void printVec(vector<llong> &A)
{       for(llong i=0;i<A.size();i++)
                cout<<(llong)A[i]<<' ';
        cout<<endl;
}
void divide(string &A,llong B)
{       string V;
        
        llong c=0;
        for(llong i=A.size()-1;i>=0;i--)
        {       c=c*10+A[i];
                V.push_back(c/B);
                c=c%B;
        }
        reverse(V.begin(),V.end());
        while(V[V.size()-1]==0&&V.size())
                V.erase(V.size()-1);
        A=V;         
              
}
void divide(llong &a,llong b)
{
        llong c=modInverse(b);
        a=(a*c)%MOD; 
}
void convertToVec(string &V,llong B)
{       
        for(llong i=0;  B  ;i++,B/=10)
            V.push_back(B%10);
        if(V.size()==0)
                V.push_back(0);
        reverse(V.begin(),V.end());
}
void multiply(string &A,llong B)
{       string P;
        for(llong k=0,i=0,c,x;B;k++,B/=10)
        {       c=0;
                x=B%10;
                for(i=0;i<A.size();i++)
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
void multiply(llong &a,llong b)
{
        a=(a*b)%MOD;
}
void constructHell(vector<llong> &cities,vector<pair<llong,string> > &hell)
{       llong i,j;
        llong N=cities.size();
        hell.push_back(make_pair(1,string(1,1)));
                
        for(i=1;i<=N;i++)
        {       hell.push_back(make_pair(1,string(1,1)));
                for(j=0;j<N;j+=i)
                {       multiply(hell[i].first ,cities[j]);
                        multiply(hell[i].second,cities[j]);
                }
        }
}
void printHell(vector<pair<llong,string> > hell)
{       for(llong i=1;i<hell.size();i++)
        {       cout<<hell[i].first<<'_';
                printVec(hell[i].second);
        }
}
void changeHell(vector<pair<llong,string> > &hell,llong index,llong old,llong ne)
{
        if(index==0)
        {       for(llong i=1;i<hell.size();i++)
                {       divide(hell[i].first,old);
                        divide(hell[i].second,old);
                        multiply(hell[i].first,ne);
                        multiply(hell[i].second,ne);
                }
                return;
        }
        if(index==1)
        {       divide(hell[1].first,old);
                divide(hell[1].second,old);
                multiply(hell[1].first,ne);
                multiply(hell[1].second,ne);
                return;
        }  if(index==2)
        {       divide(hell[1].first,old);
                divide(hell[1].second,old);
                multiply(hell[1].first,ne);
                multiply(hell[1].second,ne);
                divide(hell[2].first,old);
                divide(hell[2].second,old);
                multiply(hell[2].first,ne);
                multiply(hell[2].second,ne);
                return;
        }     
        llong root=ceil(sqrt(index));
       for(llong i=1;i<root;i++)
        if(index%i==0)   
        {       divide(hell[i].first,old);
                divide(hell[i].second,old);
                multiply(hell[i].first,ne);
                multiply(hell[i].second,ne);
                
                divide(hell[index/i].first,old);
                divide(hell[index/i].second,old);
                multiply(hell[index/i].first,ne);
                multiply(hell[index/i].second,ne);
        }        
        if(index%root==0)
        {       divide(hell[root].first,old);
                divide(hell[root].second,old);
                multiply(hell[root].first,ne);
                multiply(hell[root].second,ne);
        }
}

int main(int argc, char *argv[])
{ 
        llong N,x;
        cin>>N;
        vector<llong> cities;
        vector<pair<llong,string> > hell;
        for(llong i=0;i<N;i++)
        {       cin>>x;
                cities.push_back(x);
        }
        constructHell(cities,hell);
       printHell(hell);
        printVec(cities);                     
        llong Q,old,_new,ch,R;
        cin>>Q;
        while(Q--)
        {       cin >> ch>> R;
                
                if(ch==1)
                {       cin>>_new;
                '
                        R--;
                        old=cities[R];
                        cities[R]=_new;
                        changeHell(hell,R,old,_new);
                }
                else
                {
                     //   printHell(hell);
                        cout<<(int)hell[R].second[hell[R].second.size()-1]<<' '<<hell[R].first<<endl;
                }
        
        }
             
        return 0;
}
