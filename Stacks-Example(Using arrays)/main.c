#include <stdio.h>
#include <stdlib.h>
#define maxStack 20

typedef enum {TRUE,FALSE} boolean;

typedef int stackEntryType;

typedef struct{
    int top;
    stackEntryType elements[maxStack];
}stack;

void createStack(stack *s){
    s->top=-1;
}

boolean isEmpty(const stack *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

boolean isFull(const stack *s){
    if(s->top==maxStack-1){
        return 1;
    }else{
        return 0;
    }
}

void push(stack *s){
    if(isFull(s)){
        printf("\nStack is full.");
    }else{
        printf("\Enter the number : ");
        int item;
        scanf("%d",&item);
        s->elements[++s->top] = item;
    }
}

void pop(stack *s){
    if(isEmpty(s)){
        printf("\nStack is empty.");
    }else{
        s->top--;
    }
}

void viewStack(stack *s){
    if(isEmpty(s)){
        printf("\nStack is empty.");
    }else{
        printf("\n");
        for(int x=0;x<=s->top;x++){
            printf("%d ",s->elements[x]);
        }
    }
}

int menu(){
    int x;
    printf("\n\n--------Stacks Example------\n");
    printf("\n(1) Push numbers");
    printf("\n(2) Pop numbers");
    printf("\n(3) View stack");
    printf("\n(4) Exit");
    printf("\n\nSelect : ");
    scanf("%d",&x);
    return x;
}

int main()
{
    stack s;
    createStack(&s);
    int x=0;
    while(x!=4){
        x=menu();
        switch(x){
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            viewStack(&s);
            break;
        default:
            break;
        }
    }
    return 0;
}
