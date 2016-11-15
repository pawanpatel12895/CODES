#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool nextLex(string &S)
{   int first = -1,second =-1;
    int i;
    for(i=S.size()-2;i>=0;--i)
        if(S[i]<S[i+1]){first = i;break;}
    if(first==-1)return false;
    for(i=first +1; i<S.size();i++)if(S[i]>S[first]){second=i;break;}
    for(;i<S.size();i++)if(S[i]>S[first]&&S[i]<=S[second])second=i;
    if(S[second]<=S[first])return false;
    swap(S[first],S[second]);
    sort(S.begin()+first+1,S.end());
    return true;
}
int main()
{   int c= 0;
    string S("GHDECFAB");
    do
    {   ++c;
        cout<<S<<endl;
    }while(nextLex(S));
    cout<<c;
    return 0;
}
