#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};


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

//PUSH
void push(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack.\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}

//POP
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;   //assuming -1 will never be an element in stack
    }else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int match(char a, char b){

    if(a=='{' && b=='}'){
        return 1;
    }
     if(a=='(' && b==')'){
        return 1;
    }
     if(a=='[' && b==']'){
        return 1;
    }
    return 0;

}

int parenthesisMatch( char * exp){
    //create and initilize stack
    struct stack * sp;
    sp = (struct stack * ) malloc(sizeof(struct stack));
    sp->size = 100;   //assuming the expression won't be having more than 100 chararcters 
    sp->top = -1;
    sp->arr = malloc(sp->size*sizeof(char));
    char charPopped;

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){

            push(sp, exp[i]);

        }else if (exp[i] == ')'){

            if(isEmpty(sp)){
                return 0;             //the expression is unbalanced
            }
                charPopped= pop(sp);
                if(!match(charPopped, exp[i])){

                    return 0;
                }

        }
    }
    
    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }

}

int main(){
  
    char * exp= "[8*(9)}}";

    //Checking if stack is empty
    if(parenthesisMatch(exp)){
        printf("The Expression has balanced parenthesis.\n");
    }else{
        printf("The Expression doesn't have balanced parenthesis.\n");
    }

    return 0;
}