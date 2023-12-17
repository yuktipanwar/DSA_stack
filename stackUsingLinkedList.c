#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// global variable
struct Node *top = NULL;

// TRAVERSAL
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Check if stack is empty
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if stack is Full
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// PUSH ELEMENT IN STACK
struct Node *push(struct Node *top, int x)
{

    if (isFull(top))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// POPPING ELEMENT IN STACK
int pop(struct Node *tp)
{ // will return the integer that it will pop

    if (isEmpty(tp))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{

    struct Node *top = NULL; // the linked is empty for now.

    top = push(top, 78);
    top = push(top, 88);
    top = push(top, 67);
    top = push(top, 92);
    top = push(top, 71);

    int element = pop(top);

    // while we are popping the an element of top, it goes to the main function but the change of value doesn't bother the main function.
    // however, to excute pop we want it to change the value in the fuction also so we either make top a pointer in fucntion pop or we declare it as a global variable.
    // by doing so, whenever we'll change the value of it in the function it will also change outside the function.

    printf("Popped element is %d\n", element);

 
    linkedListTraversal(top);

    

    return 0;
}