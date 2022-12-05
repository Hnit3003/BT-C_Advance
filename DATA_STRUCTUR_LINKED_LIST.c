/*---------------------------DATA_STRUCTURE_LINKED_LIST-----------------------------------------
- NODE_Create(int NODE_Value): Create new node for the List, this node has the *next = NULL 
                               and data = value

- LIST_PushBack(NODE *NODE_HEAD, int NODE_Value): Add the new node into the last position 
                                                  of the List

- LIST_PopBack(NODE *NODE_HEAD): Delete the last node of the List

- LIST_Assign(NODE *NODE_HEAD): Enter the Position and the New Data of Node you want to ASSIGN 
                                a new value, then this Node has a new value assigned

- LIST_Insert(NODE *NODE_HEAD: Enter the Position you want to INSERT a New Node, then enter the
                               value for this Node. New Node is inserted to to List

- LIST_Erase(NODE *NODE_HEAD): ERASE the Node that you choose by enter it Position

- LIST_Print(NODE *NODE_HEAD): PRINT the data of each node of the List into the Terminal

- LIST_Size(NODE *NODE_HEAD): Return the SIZE of the List

------------------------------------------------------------------------------------------------*/

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

void LIST_PushBack(NODE *NODE_HEAD, int NODE_Value)
{
    NODE NEW_NODE = NODE_Create(NODE_Value);
    NODE Temp = NULL;

    if(*NODE_HEAD == NULL)
    {
        *NODE_HEAD = NEW_NODE;
    }else
    {
        Temp = *NODE_HEAD;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = NEW_NODE;
    }
}

void LIST_PopBack(NODE *NODE_HEAD)
{
    NODE Temp = *NODE_HEAD;
    
    if(Temp == NULL)
    {
        printf("THE LIST IS EMPTY!!\n");
    }
    else if(Temp->next == NULL)
    {
        free(Temp->next);
        *NODE_HEAD = NULL;
        printf("DELETED ALL THE LIST!!\n");
    }
    else
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next->next);
        Temp->next = NULL;
    }
}

void LIST_Assign(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(NODE_HEAD);
    NODE Temp = *NODE_HEAD;

    if(*NODE_HEAD == NULL)
    {
        printf("THE LIST IS EMPTY!! CAN NOT ASSIGN A NEW VALUE!\n");
    }
    else
    {
        printf("Enter the Position of the Node you want to ASSIGN the new value: \n");
        scanf("%d", &Position);
        while ((Position < 0) || (Position >= size))
        {
            printf("ERROR!! THERE IS NO %dth POSITION IN THE LIST.\nPlease enter again: ", Position);
            scanf("%d", &Position);
        }

        printf("\nEnter the new value of the NODE[%d]: ", Position);
        scanf("%d", &DATA_New);

        for(int i = 0; i < Position; i++)
        {
            Temp = Temp->next;
        }

        Temp->data = DATA_New;
    }
    
}

void LIST_Insert(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(NODE_HEAD);

    printf("Enter the Position of the Node you want to INSERT: \n");
    scanf("%d", &Position);
    while ((Position < 0) || (Position >= size))
    {
        printf("ERROR!! THERE IS NO %dth POSITION IN THE LIST.\nPlease enter again: ", Position);
        scanf("%d", &Position);
    }

    printf("\nEnter the new value of the NEW NODE[%d]: ", Position);
    scanf("%d", &DATA_New);

    NODE NODE_NEW = NODE_Create(DATA_New);
    NODE Temp = *NODE_HEAD;

    for(int i=1; i<Position; i++)
    {
        Temp = Temp->next;
    }

    NODE_NEW->next = Temp->next;
    Temp->next = NODE_NEW;
}

void LIST_Erase(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(NODE_HEAD);

    printf("Enter the Position of the Node you want to ERASE: \n");
    scanf("%d", &Position);
    while ((Position < 0) || (Position >= size))
    {
        printf("ERROR!! THERE IS NO %dth POSITION IN THE LIST.\nPlease enter again: ", Position);
        scanf("%d", &Position);
    }

    NODE Temp = *NODE_HEAD;
    if(Position == 0)
    {
        *NODE_HEAD = Temp->next;
    }
    else
    {
        for(int i=1; i<Position; i++)
        {
            Temp = Temp->next;
        }
        if(Position == (size - 1))
        {
            Temp->next = NULL;
        }else
        {
            Temp->next = Temp->next->next;
        }
    }
}

void LIST_Print(NODE *NODE_HEAD)
{
    NODE NODE_Temp = *NODE_HEAD;
    int count = 0;

    if(*NODE_HEAD == NULL)
    {
        printf("THE LIST IS EMPTY!!\n");
    }
    else
    {
        printf("LIST ENTERED:\n");
        while(NODE_Temp->next != NULL)
        {
            printf("[%d] = %d\n", count, NODE_Temp->data);
            NODE_Temp = NODE_Temp->next;
            count++;
            if(NODE_Temp->next == NULL)
            {
                printf("[%d] = %d\n", count, NODE_Temp->data);
            }
        }
    }

}

int LIST_Size(NODE *NODE_HEAD)
{
    int LIST_Size = 1;
    NODE Temp = *NODE_HEAD;
    if(*NODE_HEAD == NULL)
    {
        return 0;
    }
    else
    {
        while(Temp->next != NULL) 
        {
            LIST_Size++;
            Temp = Temp->next;
        }
        return LIST_Size;
    }
    
}

int main(int argc, char const *argv[])
{
    NODE LIST1 = NULL;
    LIST_PushBack(&LIST1, 10);
    LIST_PushBack(&LIST1, 20);
    LIST_PushBack(&LIST1, 15);
    LIST_PushBack(&LIST1, 25);
    // LIST_PopBack(&LIST1);
    // LIST_PopBack(&LIST1);
    // LIST_PopBack(&LIST1);
    // LIST_PopBack(&LIST1);
    LIST_Print(&LIST1);
    printf("Size of the LIST = %d\n",LIST_Size(&LIST1));
    LIST_Assign(&LIST1);
    LIST_Print(&LIST1);
    LIST_Insert(&LIST1);
    LIST_Print(&LIST1);
    LIST_Erase(&LIST1);
    LIST_Print(&LIST1);

    return 0;
}
