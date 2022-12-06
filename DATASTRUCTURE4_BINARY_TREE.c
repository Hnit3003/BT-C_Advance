/*---------------------------DATA_STRUCTURE_BINARY_TREE-------------------------------------------------------
*This Tree has the Odd data on the LeftChild and the Even data on the RightChild

- NODE_Create(int NODE_Data): Create new node for the Tree, this node has the *LeftChild = *RightChild = NULL 
                              and data = NODE_Data
- BINARY_TREE_Print(NODE NODE_ROOT, int TREE_Level): Print the Tree into the Terminal
                                                          if Tree_Level = 0, all Data are printed
            *The Tree has the form:
                NODE_ROOT
                    |_RightChild
                      |_RightChild...
                        |_...
                    |_LeftChild
                      |_LeftChild...
                        |_...

--------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *RightChild;
    struct NODE *LeftChild;
   
};

typedef struct NODE *NODE;

NODE NODE_Create(int NODE_Data)
{
    NODE NODE_New;
    NODE_New = (NODE)malloc(sizeof(NODE));
    NODE_New->data = NODE_Data;
    NODE_New->LeftChild = NULL;
    NODE_New->RightChild = NULL;

    return NODE_New;
}

/*[1] : [Insert] - ADD a New Branch Node on the Tree----------------------------------------------------------*/
void NODE_Insert(NODE *NODE_ROOT, int NODE_Data)
{
    NODE NODE_New = NODE_Create(NODE_Data);
    NODE Temp = NULL;
    if(*NODE_ROOT == NULL)
    {
        *NODE_ROOT = NODE_New;
    }else
    {
        Temp = *NODE_ROOT;

        if(NODE_Data%2 == 0)
        {
           while(Temp->LeftChild != NULL)
           {
                Temp = Temp->LeftChild;
           }
           Temp->LeftChild = NODE_New;
        }else
        {
            while(Temp->RightChild != NULL)
            {
                Temp = Temp->RightChild;
            }
            Temp->RightChild = NODE_New;
        }
    }
}

void BINARY_TREE_Print(NODE NODE_ROOT, int TREE_Level)
{
    if(NODE_ROOT == NULL)
        return;
    
    for(int i = 0; i < TREE_Level; i++)
    {
        printf(i == TREE_Level - 1 ? "|_" : "  ");
    }
    printf("%d\n", NODE_ROOT->data);
    BINARY_TREE_Print(NODE_ROOT->LeftChild, TREE_Level + 1);
    BINARY_TREE_Print(NODE_ROOT->RightChild, TREE_Level + 1);
}

int main(int argc, char const *argv[])
{
    NODE NODE_ROOT_1 = NULL;
    int OPTION = 0;

    do
    {

        printf("*----------------------------------------[OPTION]----------------------------------------*\n");
        printf("[1] : [Insert] - ADD a New Branch Node on the Tree\n");
        printf("[2] : [Exit] - Complete the Binary Tree and exit program\n");
        printf("*-----------------------------------******************-----------------------------------*\n");

        printf("PLEASE CHOOSE THE OPTION: ");
        scanf("%d", &OPTION);
        
        while((OPTION < 0) || (OPTION > 2))
        {
            printf("ERROR!! Invalid option {OPTION = %d}.\nPlease choose again: ", OPTION);
            scanf("%d", &OPTION);
        }

        printf("\n");
        int NODE_Data = 0;

        switch (OPTION)
        {
        case 1:
            printf("ENTER NEW DATA TO OF THE NODE: ");
            scanf("%d", &NODE_Data);
            NODE_Insert(&NODE_ROOT_1, NODE_Data);
            break;

        default:
            break;
        }

        BINARY_TREE_Print(NODE_ROOT_1, 0);   

    } while (OPTION != 2);

    printf("\nEXIT...");

    return 0;
}
