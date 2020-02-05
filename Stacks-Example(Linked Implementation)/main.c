#include <stdio.h>
#include <stdlib.h>
#define maxStack 50

typedef int stackEntryType;
typedef enum{FALSE,TRUE} boolean;
typedef struct node{
    stackEntryType data;
    struct node *next;
}Node;

typedef struct stack{
    int noElement;
    Node *top;
}stack;

void createStack(stack *s){
    s->top=NULL;
    s->noElement=0;
}

boolean isEmpty(const stack *s){
    if(s->top==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(stack *s){
    stackEntryType x;
    printf("\nEnter a number to add : ");
    scanf("%d",&x);
    Node *np;
    np=(Node *)malloc(sizeof(Node));
    np->data=x;
    np->next=s->top;
    s->top=np;
    s->noElement++;
}

void pop(stack *s){
    if(isEmpty(s)){
        printf("\nStack is empty");
    }else{
        Node *np;
        np=s->top;
        s->top=np->next;
        s->noElement--;
        free(np);
    }

}

void viewStack(stack *s){
    if(isEmpty(s)){
       printf("\nStack is empty");
    }else{
        Node *np;
        np=s->top;
        for(int x=0;x<s->noElement;x++){
            printf("%d ",np->data);
            np=np->next;
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

int main(){
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
