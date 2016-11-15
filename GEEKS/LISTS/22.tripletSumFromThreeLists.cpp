#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>

#define INF 10000000
#define size 100
#define llong long long
#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
using namespace std;

class List 
{       struct Node
        {       int data;
                Node *next;
        }*root;
        void delAll(Node *root)
        {       if(root==NULL)return;
                delAll(root->next);
                free(root);
                cout<<'.';
        }
        Node *getNode(int data)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->next=NULL;
                t->data=data;
                return t;
        }
        Node *insertAtBack(Node *t,int data)
        {       if(t == NULL)return getNode(data);
                t->next=insertAtBack(t->next,data);
                return t;
        }
        Node *insertAtFront(Node *t,int data)
        {       Node *s=getNode(data);
                s->next=t;
                return s;       
        }
        Node *delFromBack(Node *t)
        {       if(t->next==NULL){free(t);return NULL;}
                t->next=delFromBack(t->next);
                return t;
        }
        Node *delFromFront(Node *t)
        {       Node *s=t->next;
                free(t);
                return s;
        }
        void disp(Node *t)
        {       if(t==NULL)return;
                cout<<t->data<<' ';
                disp(t->next);
        }
/**/        Node *splitInHalf(Node *root)
        {       if(root==NULL||root->next==NULL)return NULL;
                Node *t=root,*s=root;
                if(root->next->next==NULL)
                {       t=root->next;
                        root->next=NULL;
                        return t;       
                }
                while(t!=NULL)
                {       t=t->next;
                        if(t==NULL)break;
                        t=t->next;
                        s=s->next;
                }
                t=s->next;
                s->next=NULL;
                return t;
        }
        Node *Merge(Node *A,Node *B)
        {       if(A==NULL)return B;
                if(B==NULL)return A;
                Node *t;
                if(A->data<B->data)
                {       t=A;
                        t->next=Merge(A->next,B);
                }
                else
                {       t=B;
                        t->next=Merge(A,B->next);
                }
                return t;
        }
        Node *MergeSort(Node *rt)
        {       if(rt==NULL||rt->next==NULL)return rt;
                Node *t=splitInHalf(rt);
                t=MergeSort(t);
                rt=MergeSort(rt);
                rt=Merge(rt,t);
                return rt;
        }
        Node * reverse(Node *root)
        {       Node *x=root,*y,*z;
                if(x==NULL)return NULL;
                y=x->next;
                x->next=NULL;
                if(y==NULL)return x;
                while(y!=NULL)
                {       z=y->next;
                        y->next=x;
                        x=y;
                        y=z;
                }
                root=x;
                return root;
        }       
/**/
        void findSum(Node *r1,Node *r2,Node *r3,int sum)
        {       if(r1==NULL)return;
                Node *t2=r2,*t3=r3;
                while(t2!=NULL&&t3!=NULL)
                {       if(r1->data + t2->data + t3->data == sum)
                        {       cout<<r1->data<<' '<<t2->data<<' '<<t3->data<<'\n';
                                return;
                        }
                        else if(r1->data + t2->data + t3->data < sum)
                                t2=t2->next;
                        else t3=t3->next;
                }
                findSum(r1->next,r2,r3,sum);
        }

       public:
        List(){root=NULL;}
        ~List(){delAll(root);}
        void push_back(int key)
        {       root=insertAtBack(root,key);}
        void push_front(int key)
        {       root=insertAtFront(root,key);}
        void pop_back()
        {       if(root!=NULL)
                root=delFromBack(root);
        }
        void pop_front()
        {       if(root!=NULL)
                root=delFromFront(root);
        }
        void display(){disp(root);cout<<'\n';}
 /**/       void MergeSort()
        {       root=MergeSort(root);   }        
 /**/
        void findSum(List L,List M,int sum)
        {       L.findSum(root,M,sum);       }
        void findSum(Node *r1,List M,int sum)
        {       M.findSum(r1,root,sum);            }
        void findSum(Node *r1,Node *r2,int sum)
        {       
                r1=MergeSort(r1);
                r2=MergeSort(r2);
                r2=reverse(r2);
               // disp(r2);
                findSum(root,r1,r2,sum);            
                
        }
        
};

int main(int argc, char *argv[])
{       int A[]={1,4,3,5,2};
        int B[]={7,8,9,4,3};
        int C[]={7,5,3,3,4,5,66};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
        int l=sizeof(C)/sizeof(C[0]);
        List L,M,N;
        while(n--)L.push_front(A[n]);
        while(m--)M.push_front(B[m]);
        while(l--)N.push_front(C[l]);
        L.findSum(M,N,7);
        return 0;
}
