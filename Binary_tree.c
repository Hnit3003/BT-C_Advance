#include<stdio.h>

struct node{
    int data;
    struct node *lelfchild;
    struct node *rightchild;
};

int checkEven(int value){
    if(value%2 == 0){
        return 1;
    }else{
        return 0;
    }
}

// int checkOdd(int value){
//     if(value/2 == 0){
//         return 0;
//     }else{
//         return 1;
//     }
// }

typedef struct node* Node;

Node initNode(int value){
    Node temp;
    temp->data = value;
    temp->lelfchild = NULL;
    temp->rightchild = NULL;
    return temp;
}

void insert(Node address, int value){
    Node temp = initNode(value);
    Node p;

    if(address == NULL){
        address = temp;
    }else{
        if(checkEven(value) == 1){
            p = address;
            while(p -> lelfchild != NULL){
               p = p->lelfchild;
            }
            p -> lelfchild = &temp;
        }else{
            p = address;
                while(p -> rightchild != NULL){
                p = p->rightchild;
            }
            p -> rightchild = &temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node node1 = NULL;

    insert(node1, 10);
    insert(node1, 15);
    insert(node1, 20);
    insert(node1, 25);
    return 0;
}
