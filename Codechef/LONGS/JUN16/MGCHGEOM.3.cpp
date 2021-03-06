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
vector<pair<long long,long long > > convexHull(map<pair<long long,long long>,int> &points)
{   long long  n=points.size();
    // There must be at least 3 points
    if (n < 3) return vector<pair<long long,long long> >();
 
    // Initialize Result
    vector<pair<long long,long long> > hull;
    map<pair<long long,long long >,int >::iterator itr1,itr2,itr3;
    itr1=points.begin();
    itr2=itr1;
    
    do
    {
        // Add current point to result
        hull.push_back((*itr1).first);
 
        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        itr2=itr1;
        itr2++;
        if(itr2==points.end())itr2=points.begin();
        
        
        for (itr3=points.begin(); itr3!=points.end(); itr3++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation((*itr1).first, (*itr3).first, (*itr2).first) == 2)
               itr2 = itr3;
        }
 
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        itr1 = itr2;
 
    } while (itr1 != points.begin() );  // While we don't come to first point
 
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
    for(long long i=2;i<hull.size();i++)
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
    cin>>T;
    while(T--)
    {   long long N,x,y;
        char ch;
        pair<long long,long long> P;
        map<pair<long long,long long>,int > points;
        vector<pair<long long,long long> >::iterator itr;
        vector<pair<long long,long long> > hull;
        int f;
        cin>>N;
        for(long  i=0;i<N;i++)
        {//   cin>>ch>>P.first>>P.second;
              scanf("\n%c%lld%lld",&ch,&P.first,&P.second);
         
            if(ch=='+')
            {   f=checkHullViolation(hull,P);
                
                points[P]++;
            }
            else
            {   f=0;
                for(itr=hull.begin();itr!=hull.end();++itr)
                {       if((*itr)==P)
                                f++;
                        if(f==2)break;
                }
                if(points[P]>1)points[P]--;
                else points.erase(P);
            
            }
            if(f==1)
            
            hull=convexHull(points);
            printf("%.1llf\n",calculateArea(hull));
        }
 
 
    }
 
    return 0;
}
 
