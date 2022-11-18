#include<stdio.h>
#include<stdbool.h>

#define capacity 5

int stack[capacity];

int top = 0;
int last = 1;

bool isEmpty(){
    if(top <= last){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(top >= (capacity)){
        return true;
    }else{
        return false;
    }
}

void push(int value){
    if(isFull() == false){
        stack[top] = value;
        top++;
    }else{
        printf("The stack is Full, cannot push the value {%d}!!\n", value);
        value = 0;
    }
}

void pop(){
    if(isEmpty() == false){
        top--;
    }else{
        printf("The stack is empty, value top now {%d}\n", stack[0]);
    }
}

int isTop(){
    return stack[top-1];
}

int size(){
    return top;
}

int main(int argc, char const *argv[])
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    printf("Stack inited:\n");
    for(int i = 0; i<capacity; i++){
        printf("[%d] = %d\n", i, stack[i]);
    }

    printf("\nTop now = %d\n", isTop());
    printf("Size now = %d", size());
    return 0;
}
