#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

void ButterFree(vector<pair<long,long> > &values)
{
    cin>>profit;    
    int i=0,j=0;
    long st=-INF,end = INF;
    while(j<values.size())
    {  if(values[j].first-values[i].first < profit)j++;
        else if(values[j].first - values[i].first>profit)i++;
        else  if(values[j].second  >  values[i].second )
        {         if( end - start >  values[j].second - values[i].second ||    (end -start ==   values[j].second - values[i].second   &&  values[i].second<start) )
                  {     start = values[i].second ;   
                        end = values[j].second;
                  }
        }
    }
    cout<<start<<' '<<end<<endl;
}

void metapod()
{   cin>>N>>D;
    vector<pair<long,long> > values(N);
    for(int i=0;i<N;i++)
    {   cin>>values[i].first;
        values[i].second = i+1;
    }
    sort(values.begin(),values.end());
    for(int i=0;i<D;i++)
        ButterFree(values);
}


int main() 
{
    metapod();
    return 0;
}

