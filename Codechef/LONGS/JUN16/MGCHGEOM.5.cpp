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

class MGCH
{       struct Node
        {       Point point;
                Node *next;
        }*CL;
        set< Point > SL;
        long double Area;

        Node       *getNode( Point );
        void        delCL(Node *t);
        void        printList(Node*);
        int         orientation(Point,Point,Point);
        long double getArea(Point,Point,Point);
        
       public:
        MGCH()      {CL=NULL;SL=set< Point >();Area=0;}
        ~MGCH()     {delCL(CL);}
        void        printset();
        void        printList()         {cout<<"LIST:: ";printList(CL);cout<<endl;}
        long double getArea()           {return Area;}
        void        insert(Point p);
};
MGCH::Node *MGCH::getNode( Point point)
{       Node *t=(Node*)malloc(sizeof(Node));
        t->next=NULL;
        t->point=point;
        return t;
}
int MGCH::orientation(Point p,Point q,Point r)
{   long long val = (q.yy - p.yy) * (r.xx - q.xx) -
                    (q.xx - p.xx) * (r.yy - q.yy) ;
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2;  // clock or counterclock wise
}
void MGCH::delCL(Node *t)
{       if(t==NULL)return;
        if(t->next==t||t->next==NULL)
        {       free(t);t=NULL; return;}
        Node *u=t->next;
        t->next=u->next;
        free(u);
        delCL(t);
}
void MGCH::printset()
{       set<pair<int,int> >::iterator i; 
        cout<<"SET:: ";
        for(i=SL.begin();i!=SL.end();++i)
                cout<<(*i).xx<<':'<<(*i).yy<<' ';
        cout<<endl;
}
void MGCH::printList(Node *rt)
{        if(rt==NULL)return;
        Node *t=rt;
        do
        {       cout<<t->point.xx<<':'<<t->point.yy<<' ';
                t=t->next;
        }while(t!=NULL&&t!=rt);

}
long double MGCH::getArea(Point p,Point q,Point r)
{       long double pq,qr,rp;
        pq=(p.xx-q.xx)*(p.yy+q.yy);
        qr=(q.xx-r.xx)*(q.yy+r.yy);
        rp=(r.xx-p.xx)*(r.yy+p.yy);
        return fabs((pq+qr+rp)/2);
}
void MGCH::insert(Point ne)
{       
        if(CL==NULL)
        {       CL=getNode(ne);
                CL->next=CL;
                return;
        }
        if(CL->next==CL)
        {       CL->next=getNode(ne);
                CL->next->next=CL;
                return;
        }
        else
        {       Point p,q,r;
                Node *lp1 = CL, *lp2=CL->next,*lp3,*np;
                int f=1;
                while(lp1!=CL||f)
                {       f=0;
                        lp2=lp1->next;
                        p=lp1->point;
                        q=lp2->point;
                        
                        if(orientation(p,ne,q)==2)
                        {       lp1->next=np=getNode(ne);
                                np->next=lp2;
                                lp3=lp2->next;
                                r=lp3->point;
                                while(orientation(ne,q,r)!=2&&lp1!=lp3)
                                {       SL.insert(q);
                                        np->next=lp3;
                                        free(lp2);
                                        lp2=lp3;
                                        lp3=lp3->next;
                                        q=lp2->point;
                                        r=lp3->point;
                                }
                                return;
                        }
                        lp1=lp1->next;
                }
                
                
        }

}

int main(int argc, char *argv[])
{       
        MGCH M;
        M.printList();
        M.insert(make_pair(0,4));
        M.printList();
        M.insert(make_pair(0,0));
        M.printList();
        M.insert(make_pair(4,0));
        M.printList();
        M.insert(make_pair(0,-3));
        M.printList();

        return 0;
}
