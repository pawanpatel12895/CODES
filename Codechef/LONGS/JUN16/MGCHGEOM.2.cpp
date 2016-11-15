// A C++ program to find convex hull of a set of points. Refer
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
 

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
long long orientation(pair<long long,long long> p, pair<long long,long long> q, pair<long long,long long> r)
{
    long long val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Prints convex hull of a set of n points.
vector<pair<long long,long long> > convexHull(vector<pair<long long,long long> > &points)
{   int n=points.size();
    // There must be at least 3 points
    if (n < 3) return vector<pair<long long,long long> >();
 
    // Initialize Result
    vector<pair<long long,long long> > hull;
 
    // Find the leftmost point
    long long l = 0;
    for (long  i = 1; i < n; ++i)
        if (points[i].first < points[l].first)
            l = i;
 
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    long  p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);
 
        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        for (long  i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
 
    } while (p != l);  // While we don't come to first point
 
    // Print Result
    return hull;
/*    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].first << ", "
              << hull[i].second << ")\n";
*/}
 
// Driver program to test above functions
long double calculateArea(vector<pair<long long,long long> > &hull)
{
    if(hull.size()<3)return 0.0;
    long double AB,BC,CA;
    long double Area=0;
    for(long long i=2;i<hull.size();++i)
    {   AB=(hull[0].first - hull[i-1].first)*(hull[0].second+hull[i-1].second);
        BC=(hull[i-1].first - hull[i].first)*(hull[i-1].second+hull[i].second);
        CA=(hull[i].first - hull[0].first)  *(hull[i].second+hull[0].second);
        Area+=fabs(AB+BC+CA)/2;
    }
    return Area;
}
int checkHullViolation(vector<pair<long long,long long> > hull, pair<long long,long long> P)
{       vector<pair<long long,long long> >::iterator itr1,itr2;
        if(hull.size()<2)return 1;
        itr2=itr1=hull.begin();
        itr2++;
        while(itr2!=hull.end())
        {       if( orientation((*itr1),P,(*itr2)) ==2 )
                        return 1;
                itr1++,itr2++;
        }
        if( orientation((*itr1),P,(*hull.begin() )) ==2 )
                        return 1;
      //  cout<<';';
        return 0;
} 
 
int main()
{
    long long T;
    scanf("%lld",&T);
    while(T--)
    {   long long N,x,y,f;
        char ch;
        pair<long long,long long> P;
        vector<pair<long long,long long> > points;
        vector<pair<long long,long long> >::iterator itr;
        vector<pair<long long,long long> > hull;
 
        cin>>N;
        for(long  i=0;i<N;++i)
        {   
            
            scanf("\n%c%lld%lld",&ch,&P.first,&P.second);
          //  cin>>ch>>P.first>>P.second;
            if(ch=='+')
            {   
                f=checkHullViolation(hull,P);
                points.push_back(P);
            }
            else
            {   f=0;
                for(itr=hull.begin();itr!=hull.end();++itr)
                {       if((*itr)==P)
                                f++;
                        if(f==2)break;
                }
                
                if(points.size())
                for(itr=points.begin() ;itr!=points.end();++itr)
                    if(P.first==(*itr).first&&P.second==(*itr).second)
                        {   points.erase(itr);break;
                        }
 
            }
            if(f==1)
            hull=convexHull(points);
            printf("%.1llf\n",calculateArea(hull));
        }
 
 
    }
 
    return 0;
}
 
