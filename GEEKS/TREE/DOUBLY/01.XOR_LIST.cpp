#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<climits>
#include<vector>
#include<map>

#define f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n) for(i=0;i< n;i++)
#define MOD 1000000007
#define INF 1111111111
#define llong long long
#define SIZE 100
 
using namespace std;

class XOR_List
{     struct Node
      {     int data;
            Node *prev,*next;
      }*pointer;
      Node *getNode(int data)
      {     Node *t = (Node*) malloc (sizeof(Node));
            t-prev = t->next = NULL;
            t->data = data;
            return t;
      }
      XOR_List()
      {     pointer = NULL;      }  
      void delAllNext(Node* t)
      {     if(t==NULL)return;
            delAllNext(t->next);
            free(t);
      }
      void delAllPrev(Node* t)
      {     if(t==NULL)return;
            delAllPrev(t->prev);
            free(t);
      }
      ~XOR_List()
      {     if(pointer !=NULL)
            {     delAllPrev(pointer->prev);
                  delAllNext(pointer->next);
                  free(pointer);
            }
      }
      void displayPrev(Node *t)
      {     if(t == NULL)return ;
            displayPrev(t->prev);
            cout<<t->data<<' ';
      }
      void displayNext(Node *t)
      {     if(t==NULL)return;
            cout<<t->data<<endl;
            displayPrev(t->next);
      }
      public:
      void insert(int data)
      {     Node *t = getNode(data);
            t->next = pointer;
            if(pointer)pointer ->prev = t;
            pointer = t;
      }
      void display()
      {     if(pointer != NULL)
            {     displayPrev(pointer);
                  cout<<pointer->data<<' ';
            }
      }
};
int main(int argc, char *argv[])
{
        return 0;
}
