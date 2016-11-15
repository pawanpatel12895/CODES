/*/ variation on sudoku. from midsem-2, by gupta sir /*/

#include<iostream>
#include<vector>
using namespace std;
bool check_sudoku(vector<vector<int> > &sudoku,int I,int J)
{		int mx=max(0,I-1),
		Mx=min((int)sudoku.size()-1,I+1),
		my=max(0,J-1),
		My=min((int)sudoku.size()-1,J+1);
		for(int i=0;i<sudoku.size();++i)
			if(i!=I)
				if(sudoku[i][J]==sudoku[I][J])
					return false;
		for(int j=0;j<sudoku.size();++j)
			if(j!=J)
				if(sudoku[I][j]==sudoku[I][J])
					return false;
		for(int i=mx;i<=Mx;++i)
			for(int j=my;j<=My;++j)
				if(I!=i&&J!=j)
					if(sudoku[i][j]==sudoku[I][J])
						return false;
		return true;
}
bool solve_sudoku(vector<vector<int> > &sudoku,int I=0,int J=0)
{	if(I==sudoku.size())return true;
	if(sudoku[I][J]!=-1)
		return solve_sudoku(sudoku,I+(J+1)%sudoku.size(),(J+1)%sudoku.size());
	for(int num=1;num<=sudoku.size();++num)
	{	sudoku[I][J] = num;
		if(check_sudoku(sudoku,I,J)==true)
			if(solve_sudoku(sudoku,I+(J+1)/sudoku.size(),(J+1)%sudoku.size()) ==true )
				return true;
		sudoku[I][J] = -1;
	}
	return false;
}

void fillup(vector<vector<int> > sudoku)
{

}
void printsudoku(vector<vector<int> > sudoku)
{	for(int i=0;i<sudoku.size();++i)
	{	for(int j=0;j<sudoku[i].size();++j)
			if(sudoku[i][j]!=-1)
				cout<<sudoku[i][j]<<" ";
			else cout<<". ";
		cout<<endl;
	}
}
int main()
{	vector<vector<int> > sudoku=vector<vector<int> >(9,vector<int>(9,-1));
	//fillup(sudoku);
	printsudoku(sudoku);
	if(solve_sudoku(sudoku)==true)
		printsudoku(sudoku);
	else
		cout<<"unsolvable\n";
	return 0;
}