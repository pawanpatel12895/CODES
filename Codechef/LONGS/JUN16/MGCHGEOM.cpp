#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define SIZE 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

int orientation(pair<int,int> p,pair<int,int> q, pair<int,int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
void convexHull(vector<pair<int,int> > points)
{       int n=points.size();
    if (n < 3) return;
 
    vector<pair<int,int> > hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].first < points[l].first)
            l = i;
 
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
       p = q;
 
    } while (p != l); 
 
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].first << ", "
              << hull[i].second << ")\n";
}
int main(int argc, char *argv[])
{       
        int n,i,j;
        vector<pair<int,int> > V;
        vector<pair<int,int> > H;

        cin>>n;
        for(i=0;i<n;i++)
        {       cin>>i>>j;
                V.push_back(make_pair(i,j));
        }
        convexHull(V);       

        return 0;
}
