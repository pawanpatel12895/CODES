//dosn't store range of the child nodes. 

#include<iostream>
#include<vector>
using namespace std;

void printVector( vector<int> &A )
{	for(int i=1;i<A.size();i++)
		cout<<" "<<A[i];
	cout<<endl;
}

class segmentTree
{	vector<int> Seg;	// 1-based indexing
	int st;
	public:
		segmentTree(vector<int> &data) //1-based indexing
		{
			st=1;
			while(st<data.size()-1)st=st<<1;
			cout<<data.size()-1<<' '<<st<<endl;
			Seg = vector<int>(2*st,0);
			for(int i=1;i<data.size();++i)
				Seg[i+st-1] = data[i];
			for(int i=st-1;i>0;--i)
				Seg[i] = TreeFunction(Seg[2*i],Seg[2*i+1]);
		}
		int TreeFunction(int&,int&);
		int retrieve(int);
		void update(int,int);
		void printSeg()
		{	for(int i=1;i<Seg.size();i++)
				cout<<" "<<Seg[i];
			cout<<endl;
		}
		int getSumInRange(int l,int r); //both inclusive
};
int segmentTree::TreeFunction(int &child1,int &child2)
{	//SegVaule(node) = function(SegValue(node*2) , SegValue(node*2+1) );
	return child1+child2;
}
void segmentTree::update(int pos,int value)
{	int p = (st-1) + pos;
	int v = retrieve(p);
	while(p>0)
	{	Seg[p] = Seg[p] -v + value;
		p=p/2;
	}
}
int segmentTree::retrieve(int pos)
{	return Seg[st-1 +pos];
}
int segmentTree::getSumInRange(int l,int r) 
{	if(l>r) return 0;


}

int main()
{
	int arr[]={132,5,31,2,1,2,1,123,1};
	vector<int> A=vector<int>(1,0);
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n;i++)
		A.push_back(arr[i]);
	segmentTree S(A);
	S.printSeg();
	S.update(5,100);
	S.printSeg();
	return 0;
}
