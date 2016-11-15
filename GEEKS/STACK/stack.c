#include<stdio.h>
#include<stdlib.h>

struct Stack
{       int data;
        Stack *next;
};
struct Stack *getNode(int data)
{       Stack *t=(Stack*)malloc(sizeof(Stack));
        t->data=data;
        t->next=NULL;
        return t;
}

int main()
{
        return 0;
}
