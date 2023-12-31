#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1; //True
    }else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

//PUSH- we don't need to return so we use void.
void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack.\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;   //assuming -1 will never be an element in stack
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i +1;
    if(arrayInd < 0){
        printf("Not a valid Position");
        return -1;
    }else{
            return sp->arr[arrayInd];
    }
}

int main(){
    //sp will store address of structure.
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *) malloc(sp->size * sizeof(int));

    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Before pushing,%d\n", isEmpty(sp));

    push(sp, 56);
    push(sp, 23);
    push(sp, 45);
    push(sp, 6);
    push(sp, 73);
    push(sp, 88);
    push(sp, 16);
    push(sp, 34);
    push(sp, 76);
    push(sp, 100);  //--->Push 10 values
    // push(sp, 46);  //Stack Overflow, since the size of stack is 10.

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    
    printf("Popped %d from the stack\n", pop(sp)); //---> Last in First out.
    // printf("Popped %d from the stack", pop(sp)); //---> Last in First out.
    // printf("Popped %d from the stack", pop(sp)); //---> Last in First out.

    //Printing Values from Stack
    for(int j= 1; j<= sp->top+1; j++){
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    

    return 0;
}