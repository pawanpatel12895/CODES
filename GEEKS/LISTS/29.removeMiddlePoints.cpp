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
        {       int data1,data2;
                Node *next;
        }*root;
        void delAll(Node *root)
        {       if(root==NULL)return;
                delAll(root->next);
                free(root); cout<<'.';
        }
        Node *getNode(int data1,int data2)
        {       Node *t=(Node *)malloc(sizeof(Node));
                t->next=NULL; t->data1=data1;t->data2=data2;
                return t;
        }
        Node *insertAtBack(Node *t,int data1,int data2)
        {       if(t == NULL)return getNode(data1,data2);
                t->next=insertAtBack(t->next,data1,data2);
                return t;
        }
        Node *insertAtFront(Node *t,int data1,int data2)
        {       Node *s=getNode(data1,data2); s->next=t;
                return s;       
        }
        Node *delFromBack(Node *t)
        {       if(t->next==NULL){free(t);return NULL;}
                t->next=delFromBack(t->next);
                return t;
        }
        Node *delFromFront(Node *t)
        {       Node *s=t->next; free(t);
                return s;
        }
        void disp(Node *t)
        {       if(t==NULL)return;
                cout<<t->data1<<':'<<t->data2<<"  ";
                disp(t->next);
        }
        Node *splitInHalf(Node *root)
        {       if(root==NULL||root->next==NULL)return NULL;
                Node *t=root,*s=root;
                if(root->next->next==NULL)
                {       t=root->next; root->next=NULL;
                        return t;       
                }
                while(t!=NULL)
                {       t=t->next;
                        if(t==NULL)break;
                        t=t->next; s=s->next;
                }
                t=s->next;
                s->next=NULL;
                return t;
        }
        Node *Merge(Node *A,Node *B)
        {       if(A==NULL)return B;
                if(B==NULL)return A;
                Node *t;
                if(A->data1<B->data1){t=A;t->next=Merge(A->next,B);}
                else{t=B;t->next=Merge(A,B->next);}
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
                y=x->next; x->next=NULL;
                if(y==NULL)return x;
                while(y!=NULL)
                {       z=y->next; y->next=x;
                        x=y;       y=z;
                }
                root=x; return root;
        }       
       public:
        List(){root=NULL;}
        ~List(){delAll(root);}
        void push_back(int key1,int key2){root=insertAtBack(root,key1,key2);}
        void push_front(int key1,int key2){root=insertAtFront(root,key1,key2);}
        void pop_back(){if(root!=NULL)root=delFromBack(root);}
        void pop_front(){if(root!=NULL)root=delFromFront(root);}
        void display(){disp(root);cout<<'\n';}
        void MergeSort(){root=MergeSort(root);}        
};

int main(int argc, char *argv[])
{       
        

        return 0;
}
