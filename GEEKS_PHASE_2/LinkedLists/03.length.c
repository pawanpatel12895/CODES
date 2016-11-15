#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define f0(i,N) for(i=0;i<N;i++)
#define f1(i,N) for(i=1;i<=N;i++)
#define fij(i,A,B) for(i=A;i<B;i++)
#define MOD 1000000007
#define INF 1111111111
#define SIZE 100

struct Node
{     int data;
       struct Node *next;
};

struct Node *getNode(int data)
{     struct Node *t = (struct Node*)malloc(sizeof(struct Node));
      t->data = data;
      t->next = NULL;
      return t;
}

struct Node *insertAtBeg(struct Node *root,int data)
{     if(root == NULL) return getNode(data);
      root->next = insertAtBeg(root->next,data);
      return root;
}
void deleteAll(struct Node *root)
{     if(root==NULL)return;
      deleteAll(root->next);
      free(root);
}
void printList(struct Node *root)
{     if(root==NULL)return;
      printf("%d ",root->data);
      printList(root->next);
}
struct Node *delNode(struct Node *root,int data)
{     if(root == NULL) return NULL;
      if(root->data == data)
      {     struct Node *t = root->next;
            free(root);
            return t;
      }
      
      root->next = delNode(root->next,data);
      return root;
}
int length(struct Node *root)
{     if(root==NULL) return 0;
      return 1+ length(root->next);
}
int main()
{     struct Node *L1;
      int i;
      for( i=0;i<9;i++)
      {     L1 = insertAtBeg(L1,i);
      }
      printList(L1);
      printf("\n");
      delNode(L1,5);
      
      printList(L1);
      printf("\n");
      deleteAll(L1);
           
      return 0;
}
