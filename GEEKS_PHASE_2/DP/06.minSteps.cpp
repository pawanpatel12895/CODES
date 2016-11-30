#include <bits/stdc++.h>
using namespace std;
#define INF 111111111
int minSteps(vector<int> &arr,int pos)
{	if(pos == arr.size()-1)return 0;
	static vector<int> temp(arr.size(),INF);
	for(int i=1; i<=arr[pos]&&i+pos<arr.size() ;++i)
		temp[pos] = min(temp[pos], 1+minSteps(arr,pos+i) );
	return temp[pos];
}
int main()
{	int A[]={3,2,4,2,5,2,1,5,6,4,3,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1};
	int N = sizeof(A)/sizeof(A[0]);
	vector<int> Arr;
	for(int i=0;i<N;++i)
		Arr.push_back(A[i]);
	cout<<minSteps(Arr,0)<<endl;
	return 0;
}