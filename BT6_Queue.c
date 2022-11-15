#include<stdio.h>

#define bool int
#define true 1
#define flase 0

#define MAX 5

int queue[MAX];

int front = 0, rear = 0;



bool isEmpty(){
    if(front == rear){
        return true;
    }else{
        return flase;
    }
}

bool isFull(){
    if(rear == MAX){
        return true;
    }else{
        return flase;
    }
}

void enqueue(int value){

    if(!isFull()){
        queue[rear] = value;
        rear++;
    }else{
        printf("The queue is Full!\n");
    }
}

void dequeue(){
    if(!(front == rear)){
        queue[front] = '\0';
        front++;
    }else{
        printf("The queue is Empty!\n");
        queue[front] = queue[rear-1] = '\0';
    }
}

int isFront(){
    return queue[front];
}

int isRear(){
    return queue[rear-1];
}

int sortQueue(int value){
    printf("Lay phan tu Front = %d, them vao phan tu Rear = %d\n", queue[front], value);
    for(int i=0; i<isRear(); i++){
        queue[i] = queue[i+1];
    }

    queue[rear-1] = value;
    

    for(int i=0; i < rear; i++){
        printf("[%d] = %d\n", i, queue[i]);
    }
    return queue[front];
}

int main(int argc, char const *argv[])
{
    //queue->size = 5;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    //enqueue(7);

    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();
    //dequeue();

    printf("front[] = %d\n", isFront());
    printf("rear[] = %d\n", isRear());

    printf("Hang doi vua nhap la:\n");
    for(int i=0; i < rear; i++){
        printf("[%d] = %d\n", i, queue[i]);
    }

    int take1 = sortQueue(7);

    int take2 = sortQueue(8);

    int take3 = sortQueue(9);

    printf("Cac phan tu da lay la:\n%d, %d, %d", take1, take2,take3);
    

    return 0;
}
