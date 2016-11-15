#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPalin(string &A,int I,int J)
{	while(I<J)
	{	if(A[I++] != A[J--])
			return false;
	}
	return true;
}
int longestPalndromeSize(string A)
{	vector<vector<int> > matrix(A.size(),)

}
int main()
{	string A("cghsdfsfwerwedfwefvdafaaevdaargedafadafwefffdaacdfsdfsafewsdaffasfaefegeewrwafdfasfadsa");
	cout<<longestPalndromeSize(A)<<endl;
	return 0;
}