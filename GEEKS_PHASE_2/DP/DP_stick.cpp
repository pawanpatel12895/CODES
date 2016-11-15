#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define N 2000
#define MODULUS 1000000007


int main()
{
	long long int T, s, i, j, x, y;
	vector<vector<long long int> > dp(N+1, vector<long long int>(N+1));
	dp[0][0]=0;
	for(j=1;j<=N;j++)
		dp[0][j] = 1;
	for(x=1;x<=N;x++)				// i, j variable mat lena
	{
		for(y=i;y<=N;y++)
		{
			if(x==y)
				dp[x][y] = dp[x-1][y];
			else
				dp[x][y] = (dp[x-1][y] + dp[x][y-1])%MODULUS;
		}
	}
	
	for(i=1;i<=N;i++)
		dp[i][i] = (dp[i][i]+dp[i-1][i-1])%MODULUS;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &s);
		s=s/2;
		printf("%lld\n", dp[s][s]);
	}
	return 0;
}