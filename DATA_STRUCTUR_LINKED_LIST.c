/*---------------------------DATA_STRUCTURE_LINKED_LIST----------------------------------------------------
- LIST_Size(NODE NODE_HEAD): Return the Size of the List

- NODE_Create(int NODE_Value): Create new node for the List, this node has the *next = NULL 
                               and data = value

- LIST_PushBack(NODE *NODE_HEAD, int NODE_Value): ADD the new node into the last position 
                                                  of the List

- LIST_PopBack(NODE *NODE_HEAD): REMOVE the Last Node of the List

- LIST_Assign(NODE *NODE_HEAD): Enter the Position and the New Data of Node you want to ASSIGN 
                                a new value, then this Node has a new value assigned

- LIST_Insert(NODE *NODE_HEAD: Enter the Position you want to INSERT a New Node, then enter the
                               value for this Node. New Node is inserted to to List

- LIST_Erase(NODE *NODE_HEAD): ERASE the Node that you choose by enter it Position

- LIST_Print(NODE NODE_HEAD): Print the data of each node of the List into the Terminal

- NODE_Data_Front(NODE NODE_HEAD): Return the Fisrt Node's Data

- NODE_Data_Rear(NODE NODE_HEAD): Return the Last Node's Data
---------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE* NODE;

int LIST_Size(NODE NODE_HEAD)
{
    int LIST_Size = 1;
    NODE Temp = NODE_HEAD;
    if(NODE_HEAD == NULL)
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

NODE NODE_Create(int NODE_Value)
{
    NODE NEW_NODE;
    NEW_NODE = (NODE)malloc(sizeof(NODE));
    NEW_NODE->data = NODE_Value;
    NEW_NODE->next = NULL;

    return NEW_NODE;
}

/*[1] : [PushBack] - ADD the New Node into the last position of the List---------------------------------*/
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

/*[2] : [PopBack] - REMOVE the Last Node of the List-----------------------------------------------------*/
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

/*[3] : [Assign] - Enter the Position and the New Data of Node you want to ASSIGN------------------------*/
void LIST_Assign(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(*NODE_HEAD);
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


/*[4] : [Insert] - INSERT a New Node at the selected Position--------------------------------------------*/
void LIST_Insert(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(*NODE_HEAD);

    if(*NODE_HEAD == NULL)
    {
        printf("THE LIST IS EMPTY!! CAN NOT INSERT.\n");
    }else
    {
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
}

/*[5] : [Erase] - ERASE the Node at the selected Position------------------------------------------------*/
void LIST_Erase(NODE *NODE_HEAD)
{
    int DATA_New, Position;
    int size = LIST_Size(*NODE_HEAD);

    if(*NODE_HEAD == NULL)
    {
        printf("THE LIST IS EMPTY!! There is no Node to Erase.\n");
    }else
    {
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
    
}


/*[6] : [Data_Front] - Return the Fisrt Node's Data-------------------------------------------------------*/
int NODE_Data_Front(NODE NODE_HEAD)
{
    return NODE_HEAD->data;
}

/*[7] : [Data_Rear] - Return the Last Node's Data---------------------------------------------------------*/
int NODE_Data_Rear(NODE NODE_HEAD)
{
    NODE Temp = NODE_HEAD;
    while(Temp->next != NULL)
    {
        Temp = Temp->next;
    }
    return Temp->data;
}

void LIST_Print(NODE NODE_HEAD)
{
    NODE NODE_Temp = NODE_HEAD;
    int count = 0;

    if(NODE_HEAD == NULL)
    {
        printf("THE LIST IS EMPTY!!\n");
    }
    else
    {
        printf("LINKED LIST PRESENT:\n");
        for(int i = 0; i < LIST_Size(NODE_HEAD); i++)
        {
            printf("[%d] = %d\n", i, NODE_Temp->data);
            NODE_Temp = NODE_Temp->next;
        }
    }

}

int main(int argc, char const *argv[])
{
    NODE LINKED_LIST_1 = NULL;
    int OPTION = 0;

    do
    {
        printf("\n");
        LIST_Print(LINKED_LIST_1);

        printf("*----------------------------------------[OPTION]----------------------------------------*\n");
        printf("[1] : [PushBack] - ADD the New Node into the last position of the List\n");
        printf("[2] : [PopBack] - REMOVE the Last Node of the List\n");
        printf("[3] : [Assign] - Enter the Position and the New Data of Node you want to ASSIGN\n");
        printf("[4] : [Insert] - INSERT a New Node at the selected Position\n");
        printf("[5] : [Erase] - ERASE the Node at the selected Position\n");
        printf("[6] : [Data_Front] - Print the Fisrt Node's Data\n");
        printf("[7] : [Data_Rear] - Print the Last Node's Data\n");
        printf("[8] : [Exit] Complete Linked_List and exit program\n");
        printf("*-----------------------------------******************-----------------------------------*\n");
        
        printf("PLEASE CHOOSE THE OPTION: ");
        scanf("%d", &OPTION);
        
        while((OPTION < 0) || (OPTION > 8))
        {
            printf("ERROR!! Invalid option {OPTION = %d}.\nPlease choose again: ", OPTION);
            scanf("%d", &OPTION);
        }

        printf("\n");
        int NODE_Data = 0;

        switch (OPTION)
        {
        case 1:
            printf("ENTER NEW DATA TO PUSH BACK: ");
            scanf("%d", &NODE_Data);
            LIST_PushBack(&LINKED_LIST_1, NODE_Data);
            break;

        case 2:
            if(LINKED_LIST_1 == NULL)
            {
                printf("ERROR!! The Linked List is EMPTY! There is no node to POPBACK!.\n");
            }else
            {
                printf("Removed the Rear Node [%d]\n", NODE_Data_Rear(LINKED_LIST_1));
                LIST_PopBack(&LINKED_LIST_1);
            }
            break;
        
        case 3:
            LIST_Assign(&LINKED_LIST_1);
            break;

        case 4:
            LIST_Insert(&LINKED_LIST_1);
            break;

        case 5:
            LIST_Erase(&LINKED_LIST_1);
            break;

        case 6:
            if(LINKED_LIST_1 == NULL)
            {
                printf("THE LINKED LIST IS EMPTY!!");
            }else
            {
                printf("Data of the First NODE: [0] = %d",NODE_Data_Front(LINKED_LIST_1));
            }
            break;

        case 7:
            if(LINKED_LIST_1 == NULL)
            {
                printf("THE LINKED LIST IS EMPTY!!");
            }else
            {
                printf("Data of the Last NODE: [%d] = %d", (LIST_Size(LINKED_LIST_1)-1), NODE_Data_Front(LINKED_LIST_1));
            }
            break;

        default:
            break;
        }
                                                  
    } while (OPTION != 8);
    
    printf("EXIT...");
    
    return 0;
}
