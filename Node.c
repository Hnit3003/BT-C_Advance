#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node* Node;

Node createNode(int value){
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = value;
    return temp;
}

void addNode(Node *head, int value){
    Node temp = createNode(value);
    Node p = NULL;
    if(*head == NULL){
        *head = temp;
    }else{
        p = *head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}


int main(int argc, char const *argv[])
{
    Node node1=NULL;

    addNode(&node1, 5);
    addNode(&node1, 10);
    addNode(&node1, 15);

    return 0;  
}
