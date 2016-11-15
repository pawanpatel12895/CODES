#include<iostream>
#include<vector>
using namespace std;

void printVector( vector<int> &A )
{	for(int i=1;i<A.size();i++)
		cout<<" "<<A[i];
	cout<<endl;
}

#define l_range second.first
#define r_range second.second 
class segmentTree
{	vector<pair<int,pair<int,int > > > Seg;	// 1-based indexing
				// (valueOfNode,(l_range,r_range));
	int st;
	int getSumInRange(int currNode,int l,int r);
	public:
		segmentTree(vector<int> &data) //1-based indexing
		{
			st=1;
			int i;
			while(st<data.size()-1)st=st<<1;
			
			Seg = vector<pair<int,pair<int,int > > >(2*st,make_pair(0,make_pair(0,0)));
			for(i=1;i<data.size();++i)
				Seg[i+st-1] = make_pair(data[i],make_pair(i,i));
			while(i<Seg.size()){
				Seg[i+st-1] = make_pair(0,make_pair(i,i));
				++i;
			}
			for(i=st-1;i>0;--i)
				Seg[i] = make_pair(TreeFunction(Seg[2*i].first,Seg[2*i+1].first), make_pair(Seg[2*i].l_range,Seg[2*i+1].r_range));
		}
		int TreeFunction(int&,int&);
		int retrieve(int pos);
		
		int getSumInRange(int l,int r)//both inclusive
		{	return getSumInRange(1,l,r);			
		}
		void update(int,int);
		void printSeg()
		{	for(int i=1;i<Seg.size();i++)
				cout<<"["<<Seg[i].l_range<<","<<Seg[i].r_range<<"]\t"<<Seg[i].first <<((i%6)?"\t\t":"\n");
			cout<<endl<<endl;;
		}
};
int segmentTree::TreeFunction(int &child1,int &child2)
{	//SegVaule(node) = function(SegValue(node*2) , SegValue(node*2+1) );
	return child1+child2;
}
void segmentTree::update(int pos,int value)
{	int p = (st-1) + pos;
	int v = retrieve(p);
	while(p>0)
	{	Seg[p].first = Seg[p].first -v + value;
		p=p/2;
	}
}
int segmentTree::retrieve(int pos)
{	return Seg[pos ].first;
}
int segmentTree::getSumInRange(int currNode,int l,int r) 
{	if(l>Seg[currNode].r_range || r<Seg[currNode].l_range) return 0;
	else if(l<=Seg[currNode].l_range && r>=Seg[currNode].r_range)
		return Seg[currNode].first;
	else return getSumInRange(2*currNode  ,l,r) +
				getSumInRange(2*currNode+1,l,r);
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
//	S.printSeg();
	cout<<S.getSumInRange(2,7)<<endl;
	return 0;
}
