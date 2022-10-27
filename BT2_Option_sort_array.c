#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//------Mảng gồm 2 thông số: *ptr và size--------------------------------------------
struct typeArr{
    int *ptr; //Lưu địa chỉ đầu tiên của mảng
    int size; //Lưu kích thước mảng
};

//------Hàm nhapThongTin trả về địa chỉ phần tử đầu tiên của mảng--------------------
struct typeArr *nhapThongTin(){
    
    static struct typeArr arr;
    int *ptrarr; //Khởi tạo mảng sau đó lưu vào struct *ptr
    int sizearr; //Khởi tạo biến kích thước sau đó lưu vào size

    printf("\nKich thuoc mang = ");
    scanf("%d", &sizearr);

    ptrarr = (int*)malloc(sizearr*sizeof(int));

    for(int i =0; i < sizearr; i++){
        printf("[%d] = ", i);
        scanf("%d", &ptrarr[i]);
    }

    arr.ptr = ptrarr;
    arr.size = sizearr;
    
    return &arr;
}
//------Hàm beDenLon sắp xếp các giá trị từ bé đến lớn - Thuật toán nổi bọt-----------
struct typeArr beDenLon(struct typeArr *arr){
    int tempt;
    
    for(int i =0; i < arr->size; i++){
        for(int j =i+1; j < arr->size; j++){
            if(arr->ptr[j] < arr->ptr[i]){
                tempt =arr->ptr[j];
                arr->ptr[j] =arr->ptr[i];
                arr->ptr[i] =tempt;
            }
        }
    }
}

//------Hàm lonDenBe sắp xếp các giá trị từ lớn đến bé - Thuật toán nổi bọt-----------
struct typeArr lonDenBe(struct typeArr *arr){
    int tempt;

    for(int i =0; i < arr->size; i++){
        for(int j =i+1; j < arr->size; j++){
            if(arr->ptr[i] < arr->ptr[j]){
                tempt =arr->ptr[i];
                arr->ptr[i] =arr->ptr[j];
                arr->ptr[j] =tempt;
            }
        }
    }
}

//------Hàm button đưa ra các các kết quả tương ứng với lựa chọn----------------------
bool button(int button, struct typeArr *arr){
    switch (button)
    {
    case 1:
        beDenLon(arr);
        printf("\nButton 1: Sap xep day so tu Be den Lon: ");
        for(int i=0; i < arr->size; i++){
            printf("\t%d",arr->ptr[i]);
        }
        return true;
        break;
    case 2:
        lonDenBe(arr);
        printf("\nButton 2: Sap xep day so tu Lon den Be: ");
        for(int i =0; i < arr->size; i++){
            printf("\t%d", arr->ptr[i]);
        }
        return true;
        break;
    case 3:
        lonDenBe(arr);
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
    struct typeArr *test;
    test = nhapThongTin();
    unsigned int btn;

    printf("\n\nMang da nhap la: \n\t");
    for (int i =0; i < test->size; i++){
        printf("\t[%d] = %d\t", i, test->ptr[i]);
    }
    
    printf("\n\nButton [1]: Sap xep day so tu Be den Lon\nButton [2]: Sap xepl day so tu Lon den Be\nButton [3]: In ra so lon nhat\nButton [4]: Exit");
    printf("\n\n---NHAN 1 PHIM---\n");
    
    do{
        scanf("%d", &btn);
    } while(button(btn, test) ==false);
    
    return 0;
}
