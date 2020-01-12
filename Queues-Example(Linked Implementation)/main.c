#include <stdio.h>
#include <stdlib.h>
#define maxQueue 10
typedef int queueElementType;

typedef enum{TRUE,FALSE} boolean;

typedef struct  {
    queueElementType element;
    struct node *next;
}node;

typedef struct {
    int count;
    node *front;
    node *rear;
}queue;

void createQueue(queue *q){
    q->count=0;
    q->front=NULL;
    q->rear=NULL;
}

boolean isEmpty(const queue *q){
    if(q->count==0){
        return 1;
    }else{
        return 0;
    }
}

boolean isFull(const queue *q){
    if(q->count==maxQueue){
        return 1;
    }else{
        return 0;
    }
}

void ENQueue(queue *q){
    if(isFull(q)){
        printf("\nQueue is full.");
    }else{
        node *np;
        np = (node *)malloc(sizeof(node));
        printf("\nEnter the number : ");
        queueElementType item;
        scanf("%d",&item);
        np->element=item;
        if(q->front==NULL&&q->rear==NULL){
            q->front=q->rear=np;
        }else{
            q->rear->next=np;
            q->rear=np;
        }
        q->count++;
    }
}

void DEQueue(queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty.");
    }else{
        node *np;
        np=(node *)malloc(sizeof(node));
        np=q->front;
        if(q->front==q->rear){
            q->front=q->rear=NULL;
        }else{
            q->front=np->next;
        }
        free(np);
        q->count--;
    }
}

void viewQueue(const queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty");
    }else{
        node *np;
        np = (node *)malloc(sizeof(node));
        np=q->front;
        printf("\n");
        for(int x=0;x<q->count;x++){
            printf("%d ",np->element);
            np=np->next;
        }
    }
}

int menu(){
    int x;
    printf("\n\n--------Queues Example------\n");
    printf("\n(1) Insert numbers");
    printf("\n(2) Remove numbers");
    printf("\n(3) View queue");
    printf("\n(4) Exit");
    printf("\n\nSelect : ");
    scanf("%d",&x);
    return x;
}

int main()
{
    queue q;
    createQueue(&q);
    int x=0;
    while(x!=4){
        x=menu();
        switch(x){
        case 1:
            ENQueue(&q);
            break;
        case 2:
            DEQueue(&q);
            break;
        case 3:
            viewQueue(&q);
            break;
        default:
            break;
        }
    }
    return 0;
}
