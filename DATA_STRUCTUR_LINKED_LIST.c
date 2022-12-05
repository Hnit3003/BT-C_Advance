#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE* NODE;

NODE NODE_Create(int NODE_Value)
{
    NODE NEW_NODE;
    NEW_NODE = (NODE)malloc(sizeof(NODE));
    NEW_NODE->data = NODE_Value;
    NEW_NODE->next = NULL;

    return NEW_NODE;
}

void NODE_Add(NODE *NODE_HEAD, int NODE_Value)
{
    NODE NEW_NODE = NODE_Create(NODE_Value);
    NODE Temp = NULL;

    if(*NODE_HEAD == NULL)
    {
        *NODE_HEAD = NEW_NODE;
    }else
    {
        Temp = *NODE_HEAD;
        if(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = NEW_NODE;
    }
}

int main(int argc, char const *argv[])
{
    NODE LIST_1 = NULL;
    NODE_Add(&LIST_1, 10);
    NODE_Add(&LIST_1, 20);
    NODE_Add(&LIST_1, 15);
    return 0;
}
