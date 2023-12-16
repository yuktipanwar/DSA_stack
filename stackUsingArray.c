#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

//we can't perform push() if a stack is full
//we can't perform pop() if the stack is empty.
//it is important to check these conditions before performing push or pop.

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1; //True
    }else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
   
}

int main(){

    // struct stack s;p
    // s.size = 80;
    // s.top = -1;
    // s.arr= (int *)malloc(s.size*sizeof(int));

    struct stack * s;                                 //if we make a pointer stack s then we can pass it to the functions and easily call it by reference.
    s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr= (int *)malloc(s->size * sizeof(int));

    //Manually pusing an element
    s->arr[0] = 7;
    s->top++;

    //Checking if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }else{
        printf("The stack is not empty\n");
    }

    return 0;
}