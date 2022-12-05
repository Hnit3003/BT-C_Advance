/*---------------------------SORT VO IN BOX----------------------------------------
- This program will print to terminal number of socks in the box
- The color of each sock will be typed one by one until the box is full
- The program require the number of socks in the box and the color of each of them,
  they must be typed exactly by keyboard
-----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum
{
    VO_DO,
    VO_VANG,
    VO_XANH,
}VO;

typedef struct BOX
{
    VO *ptr;
    int size;
} BOX_TYPE;

int INFOR_Enter(BOX_TYPE *value)
{
    char NAME[9];

    printf("Nhap so vo trong hop = ");
    scanf("%d", &(value->size));

    value->ptr=(VO*)malloc(value->size * sizeof(VO));

    printf("Nhap mau vo:\n[VO_DO] hoac [VO_XANH] hoac [VO_VANG]\n");
   
    for(int i=0; i < value->size; i++)
    {
        lable:
        printf("Vo[%d]: ",i+1);
        scanf("%s",NAME);
        
        if(strcmp((char*)"VO_DO",NAME) == 0)
        {
            value->ptr[i] = VO_DO;
        }
        else if(strcmp((char*)"VO_VANG",NAME) == 0)
        {
            value->ptr[i] = VO_VANG;
        }
        else if(strcmp((char*)"VO_XANH",NAME) == 0)
        {
            value->ptr[i] = VO_XANH;
        }else
        {
            printf("Nhap sai mau vo!, hay nhap lai\n");
            goto lable;
        }
    }
}

void SOCKS_Calculate(BOX_TYPE *value)
{
    int vo_do=0, vo_vang=0, vo_xanh=0;
    for(int i=0; i < value->size; i++)
    {
        if(value->ptr[i]==0)
        {
            vo_do++;
        }
        else if(value->ptr[i]==1)
        {
            vo_vang++;
        }
        else if(value->ptr[i]==2)
        {
            vo_xanh++;
        }
    }
    printf("So do tat do: %d\n", (int)(vo_do/2));
    printf("So do tat vang: %d\n", (int)(vo_vang/2));
    printf("So do tat xanh: %d\n", (int)(vo_xanh/2));
    printf("Tong so doi tat co trong hop la: %d\n", (int)(vo_do/2)+(int)(vo_vang/2)+(int)(vo_xanh/2));
}

int main()
{
    BOX_TYPE value;

    INFOR_Enter(&value);
    SOCKS_Calculate(&value);

    return 0;
}
