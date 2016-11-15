#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void shuffle(vector<int> &V)
{    for(int i=0;i<V.size();i++)
       swap(V[i],V[rand()%(i+1)]);
}
void printVec(vector<int> &A)
{       for(int i=0;i<A.size();i++)
                cout<<A[i]<<' ';
        cout<<endl;
}
int main()
{   vector<int> V;
    for(int i=1;i<=18;i++)
        V.push_back(i);
    printVec(V);
    shuffle(V);
    printVec(V);
	return 0;
}












