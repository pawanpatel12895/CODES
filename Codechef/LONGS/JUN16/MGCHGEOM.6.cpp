#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define xx first
#define yy second
#define Point pair<int,int>
using namespace std;
set< Point > BULL;
list< Point > HULL;
      
int orientation(Point p,Point q,Point r)
{   long long val = (q.yy - p.yy) * (r.xx - q.xx) -
                    (q.xx - p.xx) * (r.yy - q.yy) ;
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2;  // clock or counterclock wise
}
long double getArea(Point p,Point q,Point r)
{       long double pq,qr,rp;
        pq=(p.xx-q.xx)*(p.yy+q.yy);
        qr=(q.xx-r.xx)*(q.yy+r.yy);
        rp=(r.xx-p.xx)*(r.yy+p.yy);
        return fabs((pq+qr+rp)/2);
}
void printset(set< Point > BULL)
{       set< Point >::iterator i; 
        cout<<"SET:: ";
        for(i=BULL.begin();i!=BULL.end();++i)
                cout<<(*i).xx<<':'<<(*i).yy<<' ';
        cout<<endl;
}
void printList(list< Point > HULL)
{       list< Point >::iterator i; 
        cout<<"List:: ";
        for(i=HULL.begin();i!=HULL.end();++i)
                cout<<(*i).xx<<':'<<(*i).yy<<' ';
        cout<<endl;
}

void insert(Point newPoint)
{       if(HULL.size()<2){     HULL.insert(HULL.end(),newPoint);  return ; }
        
        int O;
        Point p1,p2,p3;
        list<Point >::iterator iH,jH,kH;
        iH=jH=HULL.begin();
        jH++;
        p1=*iH;
        p2=*jH;
        while(jH!=HULL.end())
        {       O=orientation(p1,newPoint,p2);
                if(O==2)
                {       kH=jH;
                        kH++;
                        while(kH!=HULL.end()&&orientation(*jH,newPoint,*kH)!=1)
                }
        
        
        
        }
        


}



int main(int argc, char *argv[])
{       


        return 0;
}

