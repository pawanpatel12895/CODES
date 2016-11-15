#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

bool isPalin(string S,int s,int e)
{       while(s<e)
                if(S[s++]!=S[e--])return false;
       
       return true;
}
/*
//Recursive
int LongestPalindromic(string &S,int i,int j)
{       if(i==j)return 1;
        if(isPalin(S,i,j))
        {       for(int k = i;k<=j;k++)
                        cout<<S[k];
                cout<<endl;
                return j-i+1;
        }
        return max(LongestPalindromic(S,i+1,j) , LongestPalindromic(S,i,j-1));
}
*/
int LongestPalindromic(string &S,int i,int j,vector<vector<int> > &MAT)
{       if(i==j)MAT[i][j]=1;
        if(MAT[i][j]==-1)
        {        
                if(isPalin(S,i,j))       
                        MAT[i][j]=j-i+1;
                else 
                MAT[i][j]=max(LongestPalindromic(S,i+1,j,MAT) , LongestPalindromic(S,i,j-1,MAT));
        }
        return MAT[i][j];
}
int LongestPalindromic(string &S,int i,int j)
{       vector<vector<int> > MAT(i+1,vector<int>(j+1,-1));
        return LongestPalindromic(S,i,j,MAT);
}
int main(int argc, char *argv[])
{
        string S=string("paw");
        cout<<"Length = "<<LongestPalindromic(S,0,S.size()-1);
        cout<<endl;
        return 0;
}
