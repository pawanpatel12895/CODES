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
int fact (int n)
{       return (n<2)?1:n*fact(n-1);     }
int findRank(string S)
{
        map<int,int> MP;
        map<int,int>::iterator itr,jtr;
        for(int i=0;i<S.size();i++)
                MP[S[i]]++;
        int st=0,i=0,rank=1;
        int characters=S.size();
        while(st!=S.size())
        {       itr = MP.begin();
                for(;itr!=MP.end()&&(*itr).first<S[st];itr++)
                {       if((*itr).second==0)continue;
                         int temp=fact(characters-1);
                        jtr=MP.begin();
                        for( ;jtr!=MP.end();jtr++)
                                if(itr==jtr)
                                        temp/=fact((*jtr).second-1);
                                else temp/=fact((*jtr).second);
                        rank+=temp;
                }
                MP[S[st]]--;   
                if(MP[S[st]])MP.erase(MP[S[st]]);
                st++;
                characters--;
        }
        return rank;       
}

int main(int argc, char *argv[])
{       string test("drive");
        cout<<findRank(test)<<endl;

        return 0;
}
