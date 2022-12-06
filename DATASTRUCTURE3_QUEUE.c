/*-----------------------------------DATA_STRUCTURE_QUEUE---------------------------------------------
- QUEUE_Size(NODE NODE_FRONT): Return the Size of the present Queue

- QUEUE_IsEmpty(NODE NODE_FRONT): Check if the Queue is Empty or not

- QUEUE_IsFull(NODE NODE_FRONT, int QUEUE_Capacity):
                                   Check if the Queue's number of Nodes are euqual to capacity or not

- QUEUE_CreateNode(int NODE_Data): Create the new Node for the Queue, this Node has the *next = NULL 
                                   and data = NODE_Data

- QUEUE_EnQueue(NODE *NODE_FRONT, int QUEUE_Capacity, int NODE_Data):
                                    Add the New Node at the end of the Queue

- QUEUE_DeQueue(NODE *NODE_FRONT):  Remove the Node at the Front of the Queue

- QUEUE_Print(NODE NODE_FRONT): Print the data of each Node of the Queue into the Terminal
----------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0

struct NODE_TYPE
{
    int data;
    struct NODE_TYPE *next;
};

typedef struct NODE_TYPE *NODE;

NODE Front = NULL, Rear = NULL;

int QUEUE_Size(NODE NODE_FRONT)
{
    int QUEUE_Size = 1;
    NODE Temp = NODE_FRONT;
    while(Temp->next != NULL)
    {
        Temp = Temp->next;
        QUEUE_Size++;
    }
    return QUEUE_Size;
}

bool QUEUE_IsEmpty(NODE NODE_FRONT)
{
    if(Front == NULL)
    {
        return true;
    }else
    {
        return false;
    }
}

bool QUEUE_IsFull(NODE NODE_FRONT, int QUEUE_Capacity)
{
    if(QUEUE_Size(NODE_FRONT) == QUEUE_Capacity)
    {
        return true;
    }else
    {
        return false;
    }
}


NODE QUEUE_CreateNode(int NODE_Data)
{
    NODE NEW_NODE;
    NEW_NODE = (NODE)malloc(sizeof(NODE));
    NEW_NODE->data = NODE_Data;
    NEW_NODE->next = NULL;
    
    return NEW_NODE;
}

void QUEUE_EnQueue(NODE *NODE_FRONT, int QUEUE_Capacity, int NODE_Data)
{
    NODE NEW_NODE = QUEUE_CreateNode(NODE_Data);
    NODE Temp = NULL;

    if(QUEUE_IsEmpty(*NODE_FRONT) == true)
    {
        *NODE_FRONT = NEW_NODE;
    }else
    {
        Temp = *NODE_FRONT;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        if(QUEUE_IsFull(*NODE_FRONT, QUEUE_Capacity) == true)
        {
            printf("CANNOT ENQUEUE THE VALUE %d!! The queue is full now (MAXIMUM CAPACITY)!\n", NODE_Data);
        }else
        {
            Temp->next = NEW_NODE;
        }
    }
    Front = *NODE_FRONT;
    Rear = NEW_NODE;
}

void QUEUE_DeQueue(NODE *NODE_FRONT)
{
    NODE Temp = *NODE_FRONT;
    if(QUEUE_IsEmpty(*NODE_FRONT) == true)
    {
        printf("CANNOT DEQUEUE!! The Queue is empty!\n");
    }
    else
    {
        *NODE_FRONT = Temp->next;
    }

    Front = *NODE_FRONT;
}

void QUEUE_Print(NODE NODE_FRONT)
{
    NODE Temp = NODE_FRONT;
    printf("QUEUE ENTERED:\n");
    if(QUEUE_IsEmpty(NODE_FRONT) == true)
    {
        printf("The Queue is EMPTY.\n");
    }
    else
    {
        for(int i=0; i<QUEUE_Size(NODE_FRONT); i++)
        {
            printf("[%d] = %d\n", i, Temp->data);
            Temp = Temp->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int QUEUE_Capacity;

    printf("Enter the maximum capacity of the Queue: ");
    scanf("%d", &QUEUE_Capacity);
    while (QUEUE_Capacity < 0)
    {
        printf("ERROR!!Invalid value of capacity.\nPlease enter again:");
        scanf("%d", &QUEUE_Capacity);
    }

    NODE QUEUE1 = NULL;

    QUEUE_EnQueue(&QUEUE1, QUEUE_Capacity, 20);
    // QUEUE_IsEmpty(QUEUE1);
    QUEUE_EnQueue(&QUEUE1, QUEUE_Capacity, 25);
    QUEUE_Size(QUEUE1);
    QUEUE_IsFull(QUEUE1, QUEUE_Capacity);
    QUEUE_EnQueue(&QUEUE1, QUEUE_Capacity, 30);
    // QUEUE_DeQueue(&QUEUE1);
    // QUEUE_DeQueue(&QUEUE1);
    // QUEUE_DeQueue(&QUEUE1);
    // QUEUE_DeQueue(&QUEUE1);
    QUEUE_Print(QUEUE1);

    return 0;
}

