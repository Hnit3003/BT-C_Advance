/*---------------------------ARRAY_SORT_WITH_OPTION---------------------------------
- This program will sort the Array that User typed by keyboard, with 4 OPTION:
OPTION [1]: Sort the Array from Smallest to Largest
OPTION [2]: Sort the Array from Largest to Smallest
OPTION [3]: Print to the Terminal the Largest number
OPTION [4]: Exit the program
------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//------Mảng gồm 2 thông số: *ptr và size--------------------------------------------
struct ARRAY
{
    int *ptr; //Lưu địa chỉ đầu tiên của mảng
    int size; //Lưu kích thước mảng
};

//------Hàm INFOR_Enter nhập mảng và trả về địa chỉ phần tử đầu tiên của mảng--------
struct ARRAY *INFOR_Enter()
{  
    static struct ARRAY arr;
    int *ptrarr; //Khởi tạo mảng sau đó lưu vào struct *ptr
    int sizearr; //Khởi tạo biến kích thước sau đó lưu vào size

    printf("\nKich thuoc mang = ");
    scanf("%d", &sizearr);

    ptrarr = (int*)malloc(sizearr*sizeof(int));

    for(int i =0; i < sizearr; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &ptrarr[i]);
    }

    arr.ptr = ptrarr;
    arr.size = sizearr;
    
    return &arr;
}
//------Hàm ARRAY_Sort_SmallToLarge sắp xếp các giá trị từ bé đến lớn-----------
struct ARRAY ARRAY_Sort_SmallToLarge(struct ARRAY *arr)
{
    int tempt;
    
    for(int i =0; i < arr->size; i++)
    {
        for(int j =i+1; j < arr->size; j++)
        {
            if(arr->ptr[j] < arr->ptr[i])
            {
                tempt =arr->ptr[j];
                arr->ptr[j] =arr->ptr[i];
                arr->ptr[i] =tempt;
            }
        }
    }
}

//------Hàm ARRAY_Sort_LargeToSmall sắp xếp các giá trị từ lớn đến bé------------
struct ARRAY ARRAY_Sort_LargeToSmall(struct ARRAY *arr)
{
    int tempt;

    for(int i =0; i < arr->size; i++)
    {
        for(int j =i+1; j < arr->size; j++)
        {
            if(arr->ptr[i] < arr->ptr[j])
            {
                tempt =arr->ptr[i];
                arr->ptr[i] =arr->ptr[j];
                arr->ptr[j] =tempt;
            }
        }
    }
}

//------Hàm OPTION đưa ra các các kết quả tương ứng với lựa chọn----------------------
bool OPTION(int OPT, struct ARRAY *arr)
{
    switch (OPT)
    {
    case 1:
        ARRAY_Sort_SmallToLarge(arr);
        printf("\nButton 1: Sap xep day so tu Be den Lon: ");
        for(int i=0; i < arr->size; i++)
        {
            printf("\t%d",arr->ptr[i]);
        }
        return true;
        break;
    case 2:
        ARRAY_Sort_LargeToSmall(arr);
        printf("\nButton 2: Sap xep day so tu Lon den Be: ");
        for(int i =0; i < arr->size; i++)
        {
            printf("\t%d", arr->ptr[i]);
        }
        return true;
        break;
    case 3:
        ARRAY_Sort_LargeToSmall(arr);
        printf("\nButton 3: So lon nhat la: %d", arr->ptr[0]);
        return true;
        break;
    case 4:
        printf("EXIT...");
        return true;
        break;
    default:
        printf("ERROR: Chi duoc nhap gia tri nguyen tu [1] den [4]. Moi nhap lai\n");
        return false;
        break;
    }
}

int main(){
    struct ARRAY *ARR;
    ARR = INFOR_Enter();
    unsigned int OPT;

    printf("\n\nMang da nhap la: \n\t");
    for (int i =0; i < ARR->size; i++)
    {
        printf("\t[%d] = %d\t", i, ARR->ptr[i]);
    }
    
    printf("\n\nButton [1]: Sap xep day so tu Be den Lon\nButton [2]: Sap xep day so tu Lon den Be\nButton [3]: In ra so lon nhat\nButton [4]: Exit");
    printf("\n\n---NHAN 1 PHIM---\n");
    
    do
    {
        scanf("%d", &OPT);
    } while(OPTION(OPT, ARR) ==false);
    
    return 0;
}
