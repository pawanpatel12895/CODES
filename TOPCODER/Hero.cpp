#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;


int main(int argc, char *argv[])
{	char S[52];
 	int A[10]={0};
 	int c=0;
 
 	cin>>S;
 	for(int i=0;S[i]!='\0';i++)
        	if(S[i]=='+')c++;
        	else A[S[i]-'0']++;
 	
    for(int i=0;i<10;i++)
    {	if(A[i]&&c)
        	while(A[i]--)cout<<char(i+'0');
    	else if(c==0)while(A[i]--)cout<<char(i+'0');
    	else if(A[i]==0){cout<<'+';c--;} 
    }
	cout<<endl;
        return 0;
}
