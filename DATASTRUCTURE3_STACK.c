/*-----------------------------------DATA_STRUCTURE_STACK---------------------------------------------
- STACK_Size(ELMT ELEMENT_HEAD): Return the Size of the Present Stack

- STACK_IsEmpty(ELMT ELEMENT_HEAD): Check if the Stack is Underflow or not

- STACK_IsFull(ELMT ELEMENT_HEAD, int STACK_Capacity):
                                   Check if the Stack is Overflow or not
                                   
- ELEMENT_Create(int ELEMENT_Data): Create the new Element for the Stack, this Element has the 
                                    *next = NULL and data = ELEMENT_Data
                                    
- STACK_Push(ELMT *ELEMENT_HEAD, int STACK_Capacity, int ELEMENT_Data):
                                    ADD a New Element on the Top of Stack
                                    
- STACK_Pop(ELMT *ELEMENT_HEAD):  REMOVE Element on the Top of Stack

- STACK_Top(ELMT ELEMENT_HEAD): Return the Element's Data on the Top

- STACK_Print(ELMT ELEMENT_HEAD): PRINT the Data of Stact from the Top Element to the Last Element
                                  at present
----------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0

struct ELEMENT_TYPE
{
    int data;
    struct ELEMENT_TYPE *next;
};

typedef struct ELEMENT_TYPE *ELMT;
ELMT Top = NULL;
ELMT Last = NULL;

/*[3] : [Size] - RETURN the Stack's SIZE at present------------------------------------------------------*/
int STACK_Size(ELMT ELEMENT_HEAD)
{
    int STACK_Size = 1;
    ELMT Temp = ELEMENT_HEAD;
    if(Temp == NULL)
    {
        return 0;
    }else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
            STACK_Size++;
        }
    }

    return STACK_Size;
}

bool STACK_IsFull(ELMT ELEMENT_HEAD, int STACK_Capacity)
{
    if(STACK_Size(ELEMENT_HEAD) == STACK_Capacity)
    {
        return true;
    }else return false;
}

bool STACK_IsEmpty(ELMT ELEMENT_HEAD)
{
    if(STACK_Size(ELEMENT_HEAD) == 0)
    {
        return true;
    }else return false;
}

ELMT ELEMENT_Create(int ELEMENT_Data)
{
    ELMT ELEMENT_New;
    ELEMENT_New = (ELMT)malloc(sizeof(ELMT));
    ELEMENT_New->data = ELEMENT_Data;
    ELEMENT_New->next = NULL;

    return ELEMENT_New;
}

/*[1] : [Push] - ADD a New Element on the Top of Stack---------------------------------------------------*/
void STACK_Push(ELMT *ELEMENT_HEAD, int STACK_Capacity, int ELEMENT_Data)
{
    ELMT ELEMENT_New = ELEMENT_Create(ELEMENT_Data);
    ELMT Temp = NULL;

    if(STACK_IsFull(*ELEMENT_HEAD, STACK_Capacity) == true)
    {
        printf("STACK OVERFLOW!! Cannot push the Element %d into the Top of Stack.\n", ELEMENT_Data);
    }else
    {
        if(*ELEMENT_HEAD == NULL)
        {
            *ELEMENT_HEAD = ELEMENT_New;
            Last = ELEMENT_New;
        }else
        {
            Temp = *ELEMENT_HEAD;
            *ELEMENT_HEAD = ELEMENT_New;
            ELEMENT_New->next = Temp;
        }
        Top = ELEMENT_New;
    }
}
/*[2] : [Pop] - REMOVE Element on the Top of Stack-------------------------------------------------------*/
void STACK_Pop(ELMT *ELEMENT_HEAD)
{
    ELMT Temp = *ELEMENT_HEAD;
    if(STACK_IsEmpty(*ELEMENT_HEAD) == true)
    {
        printf("STACK UNDERFLOW!! There is no more Element to Remove.\n");
    }else
    {
        *ELEMENT_HEAD = Temp->next;
    }
}

/*[4] : [Top_Data] - PRINT Element's Data on the TOP of Stack--------------------------------------------*/
int STACK_Top(ELMT ELEMENT_HEAD)
{
    return ELEMENT_HEAD->data;
}

void STACK_Print(ELMT ELEMENT_HEAD)
{
    ELMT Temp = ELEMENT_HEAD;
    if(STACK_IsEmpty(ELEMENT_HEAD) == true)
    {
        printf("STACK UNDERFLOW!! SIZE = 0.\n");
    }else
    {
        printf("STACK PRESENT:\n");
        for(int i = (STACK_Size(ELEMENT_HEAD)-1); i != -1; i--)
        {
            printf("[%d] = %d\n", i, Temp->data);
            Temp = Temp->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    ELMT STACK_1 = NULL;
    int STACK_Capacity;
    int OPTION = 0;

    printf("\nENTER THE MAXIMUM CAPACITY OF STACK: ");
    scanf("%d", &STACK_Capacity);
    while (STACK_Capacity < 0)
    {
        printf("ERROR!!Invalid value of capacity.\nPlease enter again:");
        scanf("%d", &STACK_Capacity);
    }

    do
    {
        STACK_Print(STACK_1);

        printf("*----------------------------------------[OPTION]----------------------------------------*\n");
        printf("[1] : [Push] - ADD a New Element on the Top of Stack\n");
        printf("[2] : [Pop] - REMOVE Element on the Top of Stack\n");
        printf("[3] : [Size] - PRINT the Stack's SIZE at present\n");
        printf("[4] : [Top_Data] - PRINT Element's Data on the TOP of Stack\n");
        printf("[5] : [Exit] - Complete Stack and exit program\n");
        printf("*-----------------------------------******************-----------------------------------*\n");
        

        printf("PLEASE CHOOSE THE OPTION: ");
        scanf("%d", &OPTION);
        
        while((OPTION < 0) || (OPTION > 5))
        {
            printf("ERROR!! Invalid option {OPTION = %d}.\nPlease choose again: ", OPTION);
            scanf("%d", &OPTION);
        }

        printf("\n");
        int ELEMENT_Data = 0;

        switch (OPTION)
        {
        case 1:
            printf("ENTER NEW DATA TO PUSH ON THE TOP: ");
            scanf("%d", &ELEMENT_Data);
            STACK_Push(&STACK_1, STACK_Capacity, ELEMENT_Data);
            break;

        case 2:
            if(STACK_1 == NULL)
            {
                printf("ERROR!! ");
            }
            else
            {
                printf("REMOVED Element on the TOP of Stack [%d]\n", STACK_Top(STACK_1));
            } 
            STACK_Pop(&STACK_1);
            break;
        
        case 3:
            if(STACK_1 == NULL)
            {
                printf("STACK IS EMPTY!! Size = 0\n");
            }else
            {
                printf("STACK's SIZE = %d\n", STACK_Size(STACK_1));
            }
            break;

        case 4:
            if(STACK_1 == NULL)
            {
                printf("STACK IS EMPTY!! Top_Data = NULL.\n");
            }else
            {
                printf("STACK's TOP: %d\n", STACK_Top(STACK_1));
            }
            break;
        default:
            break;
        }
                                       
    } while (OPTION != 5);

    printf("\nEXIT...");

    return 0;
}
