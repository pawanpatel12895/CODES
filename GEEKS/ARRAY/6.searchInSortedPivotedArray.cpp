#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int binSearchInPivotedArray(int arr[],int i,int j,int ele)
{        int mid =( i + j )/2;
        if (arr[mid]==ele)
                return mid;
        if (i>=j)
                return -1;
        if(arr[i]  <= arr[ mid ])
        {       if (ele < arr[mid] && ele >= arr [i] )
                        return binSearchInPivotedArray(arr,i,mid-1,ele);
                else
                        return binSearchInPivotedArray(arr,mid+1,j,ele);
        }
        else
        {       if (ele > arr[mid] && ele <= arr[j])
                        return binSearchInPivotedArray(arr,mid+1,j,ele);        
                else    return binSearchInPivotedArray(arr,i,mid-1,ele);             
        }
}
int main(int argc, char *argv[])
{
        int arr[20] = { 6,7,8,1,2 ,3, 4, 5 };
        int n=8;
        
        cout<<binSearchInPivotedArray(arr,0,7,5)<<endl;
                
        return 0;
}
