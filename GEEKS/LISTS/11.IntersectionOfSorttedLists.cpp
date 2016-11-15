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
        void intersect(Node *A,Node *B)
        {       if(A==NULL||B==NULL)return;
                if(A->data==B->data){
                        cout<<A->data<<' ';
                        intersect(A->next,B->next);
                        }
                else if(A->data < B->data)
                        intersect(A->next,B);
                else intersect(A,B->next);
                cout<<'*';
        }
/**/
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
 /**/   void intersect(List L)
        {      
                L.intersect (root);     }
        void intersect(Node *rt)
        {       intersect(root,rt); cout<<':';     }

};

int main(int argc, char *argv[])
{       int A[]={1,2,3,34,55,56,67};
        int B[]={1,3,4,45,55};
        int n=sizeof(A)/sizeof(A[0]);
        int m=sizeof(B)/sizeof(B[0]);
        List L,M;
        while(n--)L.push_front(A[n]);
        while(m--)M.push_front(B[m]);
        L.display();
        M.display();
        L.intersect(M);
        M.display();
        
        return 0;
}
