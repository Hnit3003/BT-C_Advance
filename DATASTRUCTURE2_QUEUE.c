/*-----------------------------------DATA_STRUCTURE_QUEUE---------------------------------------------
- QUEUE_Size(NODE NODE_FRONT): Return the Size of the present Queue

- QUEUE_IsEmpty(NODE NODE_FRONT): Check if the Queue is Empty or not

- QUEUE_IsFull(NODE NODE_FRONT, int QUEUE_Capacity):
                                   Check if the Queue's number of Nodes are euqual to capacity or not

- QUEUE_CreateNode(int NODE_Data): Create the new Node for the Queue, this Node has the *next = NULL 
                                   and data = NODE_Data

- QUEUE_EnQueue(NODE *NODE_FRONT, int QUEUE_Capacity, int NODE_Data):
                                    ADD the New Node at the end of Queue

- QUEUE_DeQueue(NODE *NODE_FRONT):  REMOVE the Node at the Front of Queue

- QUEUE_Print(NODE NODE_FRONT): Print the data of each Node of the Queue into the Terminal

- QUEUE_Data_Front(NODE NODE_FRONT): Return the First Data of Queue
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

/*[3] : [Size] - Print the Queue's SIZE at present--------------------------------------------------------*/
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

/*[1] : [EnQueue] - ADD the New Node at the end of Queue----------------------------------------------------*/
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

/*[2] : [DeQueue] - REMOVE the Node at the Front of Queue---------------------------------------------------*/
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

int QUEUE_Data_Front(NODE NODE_FRONT)
{
    return NODE_FRONT->data;
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
    NODE QUEUE_1 = NULL;
    int QUEUE_Capacity;
    int OPTION = 0;

    printf("\nENTER THE MAXIMUM CAPCITY OF QUEUE: ");
    scanf("%d", &QUEUE_Capacity);
    while (QUEUE_Capacity < 0)
    {
        printf("ERROR!!Invalid value of capacity.\nPlease enter again:");
        scanf("%d", &QUEUE_Capacity);
    }

    do
    {
        QUEUE_Print(QUEUE_1);

        printf("*----------------------------------------[OPTION]----------------------------------------*\n");
        printf("[1] : [EnQueue] - ADD the New Node at the end of Queue\n");
        printf("[2] : [DeQueue] - REMOVE the Node at the Front of Queue\n");
        printf("[3] : [Size] - Print the Queue's SIZE at present\n");
        printf("[4] : [Data_Front] - Print the Fisrt data of Queue\n");
        printf("[5] : [Exit] - Complete Queue and exit program\n");
        printf("*-----------------------------------******************-----------------------------------*\n");
        

        printf("PLEASE CHOOSE THE OPTION: ");
        scanf("%d", &OPTION);
        
        while((OPTION < 0) || (OPTION > 5))
        {
            printf("ERROR!! Invalid option {OPTION = %d}.\nPlease choose again: ", OPTION);
            scanf("%d", &OPTION);
        }

        printf("\n");
        int NODE_Data = 0;

        switch (OPTION)
        {
        case 1:
            printf("ENTER NEW DATA TO ENQUEUE: ");
            scanf("%d", &NODE_Data);
            QUEUE_EnQueue(&QUEUE_1, QUEUE_Capacity, NODE_Data);
            break;

        case 2:
            if(QUEUE_1 == NULL)
            {
                printf("ERROR!! ");
            }
            else
            {
                printf("Removed the Front of Queue [%d]\n", QUEUE_Data_Front(QUEUE_1));
            } 
            QUEUE_DeQueue(&QUEUE_1);
            break;
        
        case 3:
            if(QUEUE_1 == NULL)
            {
                printf("QUEUE IS EMPTY!! Size = 0\n");
            }else
            {
                printf("QUEUE's SIZE = %d\n", QUEUE_Size(QUEUE_1));
            }
            break;

        case 4:
            if(QUEUE_1 == NULL)
            {
                printf("QUEUE IS EMPTY!! Front_data = NULL.\n");
            }else
            {
                printf("First Data of Queue: %d\n", QUEUE_Data_Front(QUEUE_1));
            }
            break;
        default:
            break;
        }
                                                  
    } while (OPTION != 5);

    printf("\nEXIT...");

    return 0;
}

