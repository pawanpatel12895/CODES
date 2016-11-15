#include "bits/stdc++.h"
using namespace std;

bool match(string &A,string &B,int I)
{   int i=0;
    for(i=0;i<B.size();++i)
        if(B[i]!=A[I+i])
            return false;
    return true;
}
void printArray(vector<bool> &V)
{
    for(int i=0;i<V.size();++i)
        cout<<V[i]<<' ';
    cout<<endl;
}


int main()
{   int T;
    cin>>T;
    while(T--)
    {   string A,B;
        cin>>A>>B;
        vector<bool> is(A.size(),0);
        int N = A.size()-B.size();
        for(int i=0;i<=N;++i)
            is[i] = match(A,B,i);
        printArray(is);
    }
    return 0;
}

