/*---------------------------EVEN AND ODD---------------------------------
- This program will split the array that you typed into even and ood array
- Then the program will print both of arrays into the Terminal
------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

typedef struct ARRAY_TYPE
{
    int sizeArr;
    int sizeEven;
    int sizeOdd;
    int *ptrArr;
    int *ptrEven;
    int *ptrOdd;
}ARR;

void ARRAY_Enter(ARR *value)
{

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &(value->sizeArr));

    while(value->sizeArr < 0)
    {
        printf("Nhap sai dinh dang kich co Mang: {%d}\nMoi nhap lai: ", value->sizeArr);
        scanf("%d", &(value->sizeArr));
    }
    value->ptrArr=(int*)malloc(value->sizeArr * sizeof(int));

    for(int i=0; i < value->sizeArr; i++)
    {
        printf("\nArr[%d] = ",i);
        scanf("%d",&(value->ptrArr[i]));
    }
}

void ODD_OR_EVEN_Check(ARR *value)
{
    value->sizeEven=0;
    value->sizeOdd=0;
    int evenCount=0, oddCount=0;

    for(int i=0; i < value->sizeArr; i++)
    {
        if((value->ptrArr[i] % 2)==0)
        {
            (value->sizeEven)++;
        }else{
            (value->sizeOdd)++;
        }
    }
    
    value->ptrEven=(int*)malloc(value->sizeEven * sizeof(int));
    value->ptrOdd=(int*)malloc(value->sizeOdd * sizeof(int));

    for(int i=0; i < value->sizeArr; i++)
    {
        if((value->ptrArr[i] % 2)==0)
        {
           value->ptrEven[evenCount] = value->ptrArr[i];
           evenCount++;
        }else{
            value->ptrOdd[evenCount] = value->ptrArr[i];
            oddCount++;
        }
    }
}

void ARRAY_Print(ARR *value)
{
    printf("\nMang co %d phan tu chan\n", value->sizeEven);
    for(int i=0; i < value->sizeEven; i++)
    {
        printf("Even[%d] = %d\n", i, value->ptrEven[i]);
    }

    printf("\nMang co %d phan tu le\n", value->sizeOdd);
    for(int i=0; i < value->sizeOdd; i++)
    {
        printf("Even[%d] = %d\n", i, value->ptrOdd[i]);
    }
}  

int main()
{
    ARR value;

    ARRAY_Enter(&value);
    ODD_OR_EVEN_Check(&value);
    ARRAY_Print(&value);

    return 0;
}
