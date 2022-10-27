#include<stdio.h>
#include<stdlib.h>

typedef struct allArr{
    int sizeArr;
    int sizeEven;
    int sizeOdd;
    int *ptrArr;
    int *ptrEven;
    int *ptrOdd;
}arr;

void nhapMang(arr *value){
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &(value->sizeArr));
    value->ptrArr=(int*)malloc(value->sizeArr * sizeof(int));

    for(int i=0; i < value->sizeArr; i++){
        printf("\nArr[%d] = ",i);
        scanf("%d",&(value->ptrArr[i]));
    }
}

void kiemTraChanLe(arr *value){
    value->sizeEven=0;
    value->sizeOdd=0;
    for(int i=0; i < value->sizeArr; i++){
        if((value->ptrArr[i] % 2)==0){
            //value->ptrArr[i]=value->ptrEven[i];
            (value->sizeEven)++;
        }else{
            //value->ptrArr[i]=value->ptrOdd[i];
            (value->sizeOdd)++;
        }
    }

    value->ptrEven=(int*)malloc(value->sizeEven * sizeof(int));
    value->ptrOdd=(int*)malloc(value->sizeOdd * sizeof(int));
    
    int evenCount=0, oddCount=0;
    for(int i=0; i < value->sizeArr; i++){
        if((value->ptrArr[i] % 2)==0){
           value->ptrArr[i] = value->ptrEven[evenCount];
           evenCount++;
        }else{
            value->ptrArr[i] = value->ptrOdd[oddCount];
            oddCount++;
        }
    }

    for(int i=0; i < value->sizeArr; i++){
        printf("\n%d\n",value->ptrEven[i]);
    }
}

void inMang(arr *value){
    printf("\nMang co %d phan tu chan\n", value->sizeEven);
    for(int i=0; i < value->sizeEven; i++){
        printf("Even[%d] = %d\n", i, value->ptrEven[i]);
    }
    printf("\nMang co %d phan tu le\n", value->sizeOdd);
    for(int i=0; i < value->sizeOdd; i++){
        printf("Even[%d] = %d\n", i, value->ptrOdd[i]);
    }
}  

int main(){
    arr value;
    nhapMang(&value);
    kiemTraChanLe(&value);
    inMang(&value);
    return 0;
}
