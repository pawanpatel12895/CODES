#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void printVec(vector<int > &vec)
{
    int i;
    for(i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}
bool comparator(int a,int b)
{     return a>b; }
bool findLargest(vector<int> arr,int &num)
{   num=0;
    deque<int> zero,one,two;
    int i,sum = 0;
    sort(arr.begin(),arr.end());
    for(i=0;i<arr.size();i++)
    {   sum+=arr[i];
        if(arr[i]%3==0)
            zero.push_back(arr[i]);
        else if(arr[i]%3==1)
            one.push_back(arr[i]);
        else two.push_back(arr[i]);
      }
      if(sum%3 == 1)
      {     if(one.size())
                  one.pop_front();
            else if(two.size()>1)
            {      two.pop_front(); }
            else return false;
      } 
      else if(sum%3 == 2)
      {     if(two.size())two.pop_front();
            else if(one.size()>1)
            {     one.pop_front();one.pop_front();}
            else return false;
      }
      vector<int> aux;
      while(!zero.empty())
      {     aux.push_back(zero.front());
            zero.pop_front();
      }
      while(!one.empty())
      {     aux.push_back(one.front());
            one.pop_front();
      }
      while(!two.empty())
      {     aux.push_back(two.front());
            two.pop_front();
      }
      sort(aux.begin(),aux.end(),comparator);
      for(i=0;i<aux.size();i++)
            num = num *10 +aux[i];
      return true;
}

int main()
{   vector<int > digits;
    digits.push_back(3);
    digits.push_back(2);
    digits.push_back(4);
    digits.push_back(7);
    digits.push_back(1);
    digits.push_back(4);
    printVec(digits);
    int num;
    if(findLargest(digits,num))
        cout<<num<<endl;
    return 0;
}
