#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Int
{   long a;
public:
    Int(long b){a=b;}
    string toString()
    {   if(a==0)return "0";
        int neg=0;
        string s;
        if(a<0)neg=1,a=-a;
        while(a)
        {   s.push_back((a%10+'0'));
            a/=10;
        }
        if(neg)s.append("-");
        reverse(s.begin(),s.end());
        return s;
    }
};
int main()
{   Int i(-123);
cout<<i.toString();

}
