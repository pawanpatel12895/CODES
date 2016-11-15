#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 1111111111
#define SIZE 100
#define MOD 1000000007
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define Point pair<llong,llong>
#define llong long long
#define ldouble long double
#define xx first
#define yy second
using namespace std;

ldouble areaOfTriangle(Point p,Point q,Point r)
{       return fabs(    (p.xx -q.xx ) *( p.yy +q.yy )
                       +(q.xx -r.xx ) *( q.yy +r.yy )
                       +(r.xx -p.xx ) *( r.yy +p.yy )
                   )/2;
}
int orientation(Point p,Point q,Point r)
{       llong val = (q.yy - p.yy)*(r.xx - q.xx )
                   -(q.xx - p.xx)*(r.yy - q.yy);
        if(val==0)return 0;
        return (val>0)?1:2;
}
void printhull(list<Point> L)
{
        list<Point>::iterator i;
        for(i=L.begin();i!=L.end();++i)
                cout<<(*i).first<<':'<<(*i).second<<"  ";
}

int main(int argc, char *argv[])
{       llong T,N;
        Point P;
        char ch;
        
        ios_base::sync_with_stdio(false);
        cin>>T;
        while(T--)
        {       vector<Point> points;
                list<Point> hull;
                cin>>N;
                cin>>ch>>P.first>>P.second;
                while(N--)
                {       if(ch=='+')
                        {       points.push_back(P);
                        
                                printhull(hull);
                        }
                
                
                }
        }
        return 0;
}
