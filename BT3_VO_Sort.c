/*---------------------------SORT VO IN BOX----------------------------------------
- This program will print to terminal number of socks in the box
- The color of each sock will be typed one by one until the box is full
- The program require the number of socks in the box and the color of each of them,
  they must be typed exactly by keyboard
-----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    VO_DO,
    VO_VANG,
    VO_XANH,
}VO;

typedef struct boxarr{
    VO *ptr;
    int size;
} boxtype;

int nhapThongTin(boxtype *value){
    char name[7];

    printf("Nhap so vo trong hop = ");
    scanf("%d", &(value->size));

    value->ptr=(VO*)malloc(value->size * sizeof(VO));

    for(int i=0; i < value->size; i++){
        lable:
        printf("Vo[%d]: ",i);
        scanf("%s",name);
        
        if(strcmp((char*)"VO_DO",name) == 0){
            value->ptr[i] = VO_DO;
        }else if(strcmp((char*)"VO_VANG",name) == 0){
            value->ptr[i] = VO_VANG;
        }else if(strcmp((char*)"VO_XANH",name) == 0){
            value->ptr[i] = VO_XANH;
        }else{
            printf("Nhap sai mau vo!, hay nhap lai\n");
            goto lable;
        }
    }
}

void tinhSoDoiTat(boxtype *value){
    int vdo=0,vvang=0,vxanh=0;
    for(int i =0; i < value->size; i++){
        if(value->ptr[i]==0){
            vdo++;
        }else if(value->ptr[i]==1){
            vvang++;
        }else if(value->ptr[i]==2){
            vxanh++;
        }
    }
    printf("\nSo do tat do: %d\n", (int)(vdo/2));
    printf("\nSo do tat vang: %d\n", (int)(vvang/2));
    printf("\nSo do tat xanh: %d\n", (int)(vxanh/2));
}

int main(){
    boxtype value;
    nhapThongTin(&value);
    tinhSoDoiTat(&value);
    return 0;
}
